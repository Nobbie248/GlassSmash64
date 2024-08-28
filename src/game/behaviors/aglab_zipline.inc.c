extern const Trajectory jrb_area_1_spline_c3_curve[];

#define MAX_ZIPLINE_DISTANCE 50000.f

#define oZiplineProgress oFloatF4
#define oZiplineCurPoint oF8

static inline float point_to_segment_distance(Vec3f Q, Vec3f P1, Vec3f P2, Vec3f closest_point, float* ot) {
    Vec3f P1P2;
    vec3f_diff(P1P2, P2, P1);
    Vec3f P1Q;
    vec3f_diff(P1Q, Q, P1);

    float P1P2_dot_P1P2 = vec3_dot(P1P2, P1P2);
    float t = vec3_dot(P1Q, P1P2) / P1P2_dot_P1P2;

    if (t < 0) {
        vec3f_copy(closest_point, P1);
        return MAX_ZIPLINE_DISTANCE;
    } else if (t > 1) {
        vec3f_copy(closest_point, P2);
        return MAX_ZIPLINE_DISTANCE;
    } else {
        closest_point[0] = P1[0] + t * P1P2[0];
        closest_point[1] = P1[1] + t * P1P2[1];
        closest_point[2] = P1[2] + t * P1P2[2];
        float d;
        vec3f_get_dist(Q, closest_point, &d);
        *ot = t;
        return d;
    }
}

void bhv_zipline_init()
{
    cur_obj_become_tangible();
}

void bhv_zipline_step()
{
    const Trajectory* traj = segmented_to_virtual(jrb_area_1_spline_c3_curve);
    if (o->oInteractStatus != TRUE)
    {
        Vec3f Q = { gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2] };
        f32 minDist = 2000.f;
        Vec3f closestPoint = {0, 0, 0};
        f32 minT = 0;
        int minPoint = 0;
        
        for (int i = 0; i < 2; i++)
        {
            Vec3f trajCurPoint = {traj[i*4 + 1], traj[i*4 + 2], traj[i*4 + 3]};
            Vec3f trajNextPoint = {traj[i*4 + 5], traj[i*4 + 6], traj[i*4 + 7]};

            Vec3f tmpClosestPoint;
            f32 tmpT = 0;
            float tmpDist = point_to_segment_distance(Q, trajCurPoint, trajNextPoint, tmpClosestPoint, &tmpT);
            if (tmpDist < minDist)
            {
                minDist = tmpDist;
                minT = tmpT;
                minPoint = i * 4;
                vec3f_copy(closestPoint, tmpClosestPoint);
            }
        }
    
        if (minDist < 1000.f)
        {
            o->oPosX = closestPoint[0];
            o->oPosY = closestPoint[1];
            o->oPosZ = closestPoint[2];
            o->oZiplineProgress = minT;
            o->oZiplineCurPoint = minPoint;
            o->oForwardVel = 30.f;
            cur_obj_become_tangible();
        }
        else
        {
            cur_obj_become_intangible();
        }

    #if 0
        print_text_fmt_int(20, 20, "%d", (int) dist);
        print_text_fmt_int(20, 40, "X %d", (int) o->oPosX);
        print_text_fmt_int(20, 60, "Y %d", (int) o->oPosY);
        print_text_fmt_int(20, 80, "Z %d", (int) o->oPosZ);
        
        print_text_fmt_int(20, 140, "X %d", (int) gMarioStates->pos[0]);
        print_text_fmt_int(20, 160, "Y %d", (int) gMarioStates->pos[1]);
        print_text_fmt_int(20, 180, "Z %d", (int) gMarioStates->pos[2]);
    #endif
    }
    else
    {
       // Advance along the zipline
        {
            Vec3f trajCurPoint = {traj[o->oZiplineCurPoint + 1], traj[o->oZiplineCurPoint + 2], traj[o->oZiplineCurPoint + 3]};
            Vec3f trajNextPoint = {traj[o->oZiplineCurPoint + 4 + 1], traj[o->oZiplineCurPoint + 4 + 2], traj[o->oZiplineCurPoint + 4 + 3]};
            Vec3f trajDirection;
            vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
            o->oFaceAngleYaw = atan2s(trajDirection[2], trajDirection[0]);
            o->oMoveAngleYaw = o->oFaceAngleYaw;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw;

            f32 dirMag = vec3_mag(trajDirection);
            // Calculate velocity
            {
                f32 xdir = trajDirection[0];
                f32 zdir = trajDirection[2];
                f32 szmag = sqrtf(xdir * xdir + zdir * zdir);
                xdir /= szmag;
                zdir /= szmag;

                f32 xspd = gMarioState->intendedMag * sins(gMarioState->intendedYaw);
                f32 zspd = gMarioState->intendedMag * coss(gMarioState->intendedYaw);
                f32 dot = xdir * xspd + zdir * zspd;

                o->oForwardVel *= 0.95f;
                o->oForwardVel += dot / 12.0f;
                o->oForwardVel = CLAMP(o->oForwardVel, 0.f, 40.f);

                if (o->oForwardVel < 1.f)
                {
                    cur_obj_become_intangible();
                    gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
                }

                cur_obj_play_sound_1(SOUND_ENV_ELEVATOR1);
            }

            f32 movAmt = o->oForwardVel / dirMag;

            o->oZiplineProgress += movAmt;
            if (o->oZiplineProgress >= 1.f)
            {
                if (traj[o->oZiplineCurPoint + 8] == -1)
                {
                    cur_obj_become_intangible();
                    gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;
                }
                else
                {
                    o->oZiplineProgress = o->oZiplineProgress - 1.f;
                    o->oZiplineCurPoint += 4;
                }
            }
        }
        {
            Vec3f trajCurPoint = {traj[o->oZiplineCurPoint + 1], traj[o->oZiplineCurPoint + 2], traj[o->oZiplineCurPoint + 3]};
            Vec3f trajNextPoint = {traj[o->oZiplineCurPoint + 4 + 1], traj[o->oZiplineCurPoint + 4 + 2], traj[o->oZiplineCurPoint + 4 + 3]};
            Vec3f trajDirection;
            vec3f_diff(trajDirection, trajNextPoint, trajCurPoint);
            o->oPosX = trajCurPoint[0] + (trajDirection[0] * o->oZiplineProgress);
            o->oPosY = trajCurPoint[1] + (trajDirection[1] * o->oZiplineProgress);
            o->oPosZ = trajCurPoint[2] + (trajDirection[2] * o->oZiplineProgress);
        }
    }
}

// rotating_platform.inc.c

struct WFRotatingPlatformData {
    s16 unused;
    s16 scale;
    const Collision *collisionData;
    s16 collisionDistance;
};

struct WFRotatingPlatformData sWFRotatingPlatformData[] = {
    { 0, 100, wf_seg7_collision_rotating_platform, 2000 },
    { 0, 150, wdw_seg7_collision_rotating_platform, 1000 }
};

void bhv_wf_rotating_wooden_platform_loop(void) {
    if (o->oAction == 0) {
        o->oAngleVelYaw = 0;
        if (o->oTimer > 60) {
            o->oAction++;
        }
    } else {
        o->oAngleVelYaw = 0x100;
        if (o->oTimer > 126) {
            o->oAction = ROTATING_PLATFORM_ACT_STOPPED;
        }
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR2);
    }
    cur_obj_rotate_face_angle_using_vel();
}

void bhv_rotating_platform_loop(void) {
    s8 speed = GET_BPARAM1(o->oBehParams);
    if (o->oTimer == 0) {
        obj_set_collision_data(o, sWFRotatingPlatformData[o->oBehParams2ndByte].collisionData);
        o->oCollisionDistance = sWFRotatingPlatformData[o->oBehParams2ndByte].collisionDistance;
        cur_obj_scale(sWFRotatingPlatformData[o->oBehParams2ndByte].scale * 0.01f);
    }
    o->oAngleVelYaw = speed << 4;
    o->oFaceAngleYaw += o->oAngleVelYaw;
}

void bhv_gemmies_rotating_loop(void) {
    o->oAngleVelYaw = 0x23;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY = o->oHomeY + sins(o->oTimer * 0x123) * 50.0f;
}
void bhv_cube_rotate_loop(void) {
    o->oAngleVelYaw = -0x23;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY = o->oHomeY + sins((o->oTimer * 0x123) + 0x4000) * 50.0f;
}
#define PLATFORM_SPEED 8.0f
#define MOVE_DURATION 140
#define STOP_DURATION 75
void bhv_back_and_forth_loop(void) {
    
    switch (o->oAction) {
        case 0:
            o->oPosX += PLATFORM_SPEED;
            if (++o->oTimer >= MOVE_DURATION) {
                o->oAction = 1;
                o->oTimer = 0;
            }
            break;
        
        case 1:
            if (++o->oTimer >= STOP_DURATION) {
                o->oAction = 2;
                o->oTimer = 0;
            }
            break;
        
        case 2:
            o->oPosX -= PLATFORM_SPEED;
            if (++o->oTimer >= MOVE_DURATION) {
                o->oAction = 3;
                o->oTimer = 0;
            }
            break;
        
        case 3:
            if (++o->oTimer >= STOP_DURATION) {
                o->oAction = 0;
                o->oTimer = 0;
            }
            break;
    }
}

void bhv_car_loop(void) {
    o->oAngleVelYaw = 0x60;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY = o->oHomeY;
}
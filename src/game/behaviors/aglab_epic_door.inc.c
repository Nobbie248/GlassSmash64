#include "game/emutest.h"

extern const Collision beta_door_r_collision[];
extern const Collision beta_door_l_collision[];

#define oCrystal0 oObjF4
#define oCrystal1 oObjF8

extern u8 gCheatingTranslucency;

static void kill_beta_warp()
{
    uint32_t flags = save_file_get_flags();
    if ((flags & SAVE_FILE_RL_BOWSER_DEAD) && gMarioStates->numStars >= 30) {
        return;
    }

    struct Object* warp = cur_obj_nearest_object_with_behavior(bhvFadingWarp);
    if (warp)
    {
        warp->activeFlags = 0;
    }
}

void bhv_epic_door_init()
{
    kill_beta_warp();
    int flags[2];
    int models[2];
    if (0 == o->oBehParams2ndByte)
    {
        flags[0] = SAVE_FILE_RL_GEM_1;
        models[0] = MODEL_GEM_GREEN;

        flags[1] = SAVE_FILE_RL_GEM_3;
        models[1] = MODEL_GEM_RED;
    }
    else
    {
        flags[0] = SAVE_FILE_RL_GEM_2;
        models[0] = MODEL_GEM_BLUE;

        flags[1] = SAVE_FILE_RL_GEM_4;
        models[1] = MODEL_GEM_PURPLE;
    }
    
    struct Object** crystals = &o->oObjF4;
    for (int i = 0; i < 2; i++)
    {
        if (save_file_get_flags() & flags[i])
        {
            crystals[i] = spawn_object(o, models[i], bhvStaticObject);
            crystals[i]->oPosY = o->oPosY + 166.f + 78.f * i;
            obj_scale(crystals[i], 1.1f);
        }
        else
        {
            crystals[i] = NULL;
        }
    }

    o->oDrawingDistance = 10000.f;
}

static void adjust_crystal(struct Object* crystal)
{
    if (!crystal)
        return;

#if 0
    static f32 amt = 183.f;
    if (gPlayer1Controller->buttonPressed & L_JPAD)
    {
        amt += 0.1f;
    }
    if (gPlayer1Controller->buttonPressed & R_JPAD)
    {
        amt -= 0.1f;
    }
    print_text_fmt_int(20, 20, "%d", (s32)amt);
#endif

    int angleOff = o->oBehParams2ndByte ? -0x4000 : 0x4000;
    crystal->oPosX = o->oPosX + 190.f * sins(o->oMoveAngleYaw + angleOff) - sins(o->oMoveAngleYaw + 2*angleOff) * 38.f;
    crystal->oPosZ = o->oPosZ + 190.f * coss(o->oMoveAngleYaw + angleOff) - coss(o->oMoveAngleYaw + 2*angleOff) * 38.f;
    crystal->oFaceAngleYaw = o->oMoveAngleYaw;
    // crystal->oPosY = o->oPosY + amt;
}

void bhv_epic_door_loop()
{
    if (0 == o->oBehParams2ndByte)
    {
        obj_set_collision_data(o, beta_door_l_collision);
    }
    else
    {
        obj_set_collision_data(o, beta_door_r_collision);
    }

    s32 flags = save_file_get_flags();
    if ((flags & SAVE_FILE_RL_GEMS) == SAVE_FILE_RL_GEMS)
    {
        static const Vec3f kPivot = { 1030, -711, -4167 };
        Vec3f dist;
        vec3_diff(dist, kPivot, gMarioStates->pos);
        f32 mag = vec3_mag(dist);

        if (1 == o->oAction)
        {
            if (1 == o->oBehParams2ndByte)
            {
                if (o->oMoveAngleYaw < 0x3000)
                {
                    o->oMoveAngleYaw += 0x100;
                    cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
                }
            }
            else
            {
                if (o->oMoveAngleYaw > -0x3000)
                {
                    o->oMoveAngleYaw -= 0x100;
                    cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
                }
            }

            if (mag > 2000.f)
            {
                o->oAction = 0;
            }
        }
        else
        {
            if (o->oMoveAngleYaw < 0)
            {
                o->oMoveAngleYaw += 0x100;
                cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
            }
            if (o->oMoveAngleYaw > 0)
            {
                o->oMoveAngleYaw -= 0x100;
                cur_obj_play_sound_1(SOUND_ENV_BOAT_ROCKING1);
            }

            if (mag < 1000.f)
            {
                o->oAction = 1;
            }
        }
    }

    adjust_crystal(o->oCrystal0);
    adjust_crystal(o->oCrystal1);

    if (1 == o->oBehParams2ndByte)
    {
        checkWarp();
    }
}

void bhv_static_object_on_console_loop()
{
    if (gIsConsole)
        o->activeFlags = 0;
}

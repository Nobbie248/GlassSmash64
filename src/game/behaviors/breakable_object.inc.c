#include "game/level_update.h"
#include "game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/ingame_menu.h"
#include "src/game/interaction.h"
#include "game/save_file.h"
#include "game/hud.h"
#include "src/game/print.h"
#include "src/game/spawn_object.h"

void award_star(s16 starIndex) {
    s16 fileNum = gCurrSaveFileNum - 1;
    s16 courseNum = gCurrCourseNum - 1;

    if (starIndex < 0 || starIndex > 6) {
        return;
    }

    u8 starFlags = save_file_get_star_flags(fileNum, courseNum);

    if (!(starFlags & (1 << starIndex))) {
        save_file_set_star_flags(fileNum, courseNum, starFlags | (1 << starIndex));
        gMarioState->numStars++;
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
        save_file_do_save(gCurrSaveFileNum - 1);
    }
}

void check_and_spawn_star(void) {
    u16 slideTime = level_control_timer(TIMER_CONTROL_START);
    s32 shouldWin = 0;

    if (gCurrLevelNum == LEVEL_BOB) {
        if (gTotalBrokenObjects >= 30) {
            if (slideTime < 1829) { award_star(0); award_star(1); award_star(2); }
            else if (slideTime < 2129) { award_star(0); award_star(1); }
            else if (slideTime < 2729) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_WF) {
        if (gTotalBrokenObjects >= 30) {
            if (slideTime < 1979) { award_star(0); award_star(1); award_star(2); }
            else if (slideTime < 2279) { award_star(0); award_star(1); }
            else if (slideTime < 2879) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_JRB) {
        if (gTotalBrokenObjects >= 30) {
            if (slideTime < 1679) { award_star(0); award_star(1); award_star(2); }
            else if (slideTime < 1929) { award_star(0); award_star(1); }
            else if (slideTime < 2579) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_CCM) {
        if (gTotalBrokenObjects >= 30) {
            if (slideTime < 2279) { award_star(0); award_star(1); award_star(2); }
            else if (slideTime < 2579) { award_star(0); award_star(1); }
            else if (slideTime < 3179) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_BBH) {
        if (gTotalBrokenObjects >= 8) {
            if (slideTime < 779) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_HMC) {
        if (gTotalBrokenObjects >= 8) {
            if (slideTime < 689) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (gCurrLevelNum == LEVEL_LLL) {
        if (gTotalBrokenObjects >= 8) {
            if (slideTime < 869) { award_star(0); }
            shouldWin = 1;
        }
    }

    if (shouldWin) {
        gIsPer = 1;
        seq_player_lower_volume(SEQ_PLAYER_LEVEL, 0, 40);
        play_sound(SOUND_OBJ_UKIKI_CHATTER_LONG, gGlobalSoundSource);
        gTotalBrokenObjects = 0;
        level_control_timer(TIMER_CONTROL_STOP);
    }
}

#define MODEL_1 MODEL_PLANT_POT
#define MODEL_2 MODEL_ORNATE_POT
#define MODEL_3 MODEL_FLOWER_ORNATE_POT
#define MODEL_4 MODEL_FLORAL_POT

void bhv_pots_init(void) {
    struct Object *obj = gCurrentObject;
    if (gCurrLevelNum == LEVEL_JRB && obj->behavior == bhvAztecPots) {
        u16 randVal = random_u16() % 4;

        switch (randVal) {
            case 0:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_1];
                break;
            case 1:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_2];
                break;
            case 2:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_3];
                break;
            case 3:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_4];
                break;
        }
    }
}

#define MODEL_A MODEL_YOSHY
#define MODEL_B MODEL_TOADY
#define MODEL_C MODEL_KOOPY
#define MODEL_D MODEL_POTTY

void bhv_jstatues_init(void) {
    struct Object *obj = gCurrentObject;
    if (gCurrLevelNum == LEVEL_WF && obj->behavior == bhvJStatues) {
        u16 randVal = random_u16() % 4;
        
        switch (randVal) {
            case 0:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_A];
                break;
            case 1:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_B];
                break;
            case 2:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_C];
                break;
            case 3:
                obj->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_D];
                break;
        }
        obj->oFaceAngleYaw = random_u16();
    }
}


void breakable_object_behavior_loop(u32 sound, u32 particleModel, f32 particleSize1) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);
    struct Object* closehit = cur_obj_nearest_object_with_behavior(bhvClosehit);

    if ((brick && obj_check_if_collided_with_object(o, brick)) ||
        (brick2 && obj_check_if_collided_with_object(o, brick2)) ||
        (closehit && obj_check_if_collided_with_object(o, closehit)) ||
        cur_obj_was_attacked_or_ground_pounded()) {     
            
        play_sound(sound, gGlobalSoundSource);

        if (o->behavior == bhvPileLeaves) {
            for (int i = 0; i < 9; i++) {
                struct Object *leafParticle = spawn_object(o, MODEL_P_LEAVES, bhvLeafParticle);
                f32 angle = random_float() * 2.0f * M_PI;
                f32 distance = random_float() * 10.0f;
                leafParticle->oPosX = o->oPosX + sins(angle) * distance;
                leafParticle->oPosY = o->oPosY + random_float() * 50.0f;
                leafParticle->oPosZ = o->oPosZ + coss(angle) * distance;
                leafParticle->oVelX = sins(angle) * (random_float() * 5.0f + 2.0f);
                leafParticle->oVelZ = coss(angle) * (random_float() * 5.0f + 2.0f);
                leafParticle->oVelY = random_float() * 10.0f + 5.0f;
            }
        
            spawn_mist_particles_variable(0, 0, 46.0f);
            spawn_triangle_break_particles(15, particleModel, particleSize1, 4);
            obj_mark_for_deletion(o);
            return;
        } else {
            spawn_mist_particles_variable(0, 0, 46.0f);
            spawn_triangle_break_particles(15, particleModel, particleSize1, 4);
        }

        if (gMarioState == NULL) {
            return;
        }
        
        u32 oldCoins = gMarioState->numCoins;
        u32 oldBroken = gTotalBrokenObjects;
        
        gMarioState->numCoins++;
        gTotalBrokenObjects++;
        
        if (gMarioState->numCoins == oldCoins || gTotalBrokenObjects == oldBroken) {
            return;
        }

        obj_mark_for_deletion(o);
        check_and_spawn_star();
    }
}

void bhv_falling_leaf_particle(void) {
    if (o->oTimer == 0) {
        o->oVelX = (random_float() - 0.5f) * 30.0f;
        o->oVelZ = (random_float() - 0.5f) * 30.0f;
        o->oVelY = 20.0f + random_float() * 10.0f;

        o->oFaceAnglePitch = (s16)(random_float() * 0x4000);
        o->oFaceAngleYaw = (s16)(random_float() * 0x4000);
        o->oFaceAngleRoll = (s16)(random_float() * 0x4000);

        o->oAngleVelPitch = (s16)(random_float() * 0x1000);
        o->oAngleVelYaw = (s16)(random_float() * 0x1000);
        o->oAngleVelRoll = (s16)(random_float() * 0x1000);
    }

    o->oVelY -= 1.0f; 

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;

    o->oFaceAnglePitch += o->oAngleVelPitch;
    o->oFaceAngleYaw += o->oAngleVelYaw;
    o->oFaceAngleRoll += o->oAngleVelRoll;

    if (o->oTimer > 60) {
        obj_mark_for_deletion(o);
    }
}

void bhv_breakable_bubbly_loop(void) {
    breakable_object_behavior_loop(SOUND_ACTION_HIT_2, MODEL_BUBBLY_POP, 0.8f);
}

void bhv_breakable_mushy_loop(void) {
    breakable_object_behavior_loop(SOUND_AIR_BOWSER_SPIT_FIRE, MODEL_MUSHY_PARTICLE, 0.3f);
}

void bhv_breakable_leaves_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_YOSHI_TALK, MODEL_P_LEAVES, 1.0f);
}

void bhv_breakable_glass_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_BREAK_BOX, MODEL_GLASS_SHARD, 1.2f);
}

void bhv_breakable_lantern_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_RACE_GUN_SHOT, MODEL_LANTERN_POP, 2.0f);
}

void bhv_breakable_statue_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_CRUMBLES, 2.0f);
}

void bhv_breakable_statue2_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_CRUMBLES2, 3.0f);
}

void bhv_breakable_vase_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_BREAK_BOX, MODEL_CHINA_POP, 1.5f);
}

void bhv_breakable_target_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_CRUMBLES, 2.0f);
}

void bhv_breakable_pot_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_CRUMBLESB, 2.0f);
}

void bhv_breakable_ball_saver_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_RACE_GUN_SHOT, MODEL_BALL_SAVER_PARTICLE, 2.0f);
}

void bhv_breakable_barrel_chest_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_CANNON_BARREL_PITCH, MODEL_CHEST_BARREL_PARTICLE, 2.0f);
}

void bhv_breakable_diamond_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_DIAMOND_PARTICLE, 2.0f);
}

void bhv_breakable_oogaboogas_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_MAD_PIANO_CHOMPING, MODEL_CHEST_BARREL_PARTICLE, 1.0f);
}

void bhv_breakable_bottle_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_BREAK_BOX, MODEL_BOTTLE_PARTICLE, 2.0f);
}

void bhv_breakable_kite_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_MAD_PIANO_CHOMPING, MODEL_BALL_SAVER_PARTICLE, 2.0f);
}

void convert_slide_time(s32 slideTime, char *buffer) {
    s32 totalSeconds = slideTime / 30;
    
    sprintf(buffer, "%d'%02d\"%d", totalSeconds / 60, totalSeconds % 60, (slideTime % 30) / 3);
}

void pauseinputscore(void) {
    static int delayTimer = 0;
    u16 slideTime = level_control_timer(TIMER_CONTROL_STOP);
    u16 currentTime = level_control_timer(TIMER_CONTROL_STOP);
    save_file_collect_slide_time(gCurrSaveFileNum - 1, gCurrCourseNum - 1, currentTime);

    int buttonPressed = gMarioStates->controller->buttonPressed;

    if (delayTimer >= 60) {
        if (buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
            initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAG_EXIT_COURSE);
            fade_into_special_warp(WARP_SPECIAL_NONE, 0);
            gIsPer = 0;
            delayTimer = 0;
        }
    } else {
        delayTimer++;
    }

    u16 bestTime = save_file_get_best_slide_time(gCurrSaveFileNum - 1, gCurrCourseNum - 1);
    if (bestTime != 0) {
        char bestTimeString[16];
        convert_slide_time(bestTime, bestTimeString);
        print_text(200, 100, bestTimeString);
    }

    s16 fileNum = gCurrSaveFileNum - 1;
    s16 courseNum = gCurrCourseNum - 1;
    u8 starFlags = save_file_get_star_flags(fileNum, courseNum);
    int collectedStars = 0;
    for (int i = 0; i < 7; i++) {
        if (starFlags & (1 << i)) {
            collectedStars++;
        }
    }

    struct Controller *c = gMarioStates->controller;
    gMarioStates->input = 0;
    c->rawStickX = c->rawStickY = c->stickX = c->stickY = c->stickMag = c->buttonDown = c->buttonPressed = 0;

    char timeString[16];  
    char starString[16];

    convert_slide_time(slideTime, timeString);

    print_text(130, 180, "score");
    print_text(50, 150, "your time");
    print_text(200, 150, timeString);
    print_text(50, 100, "best time"); 

    if (gCurrLevelNum != LEVEL_BBH &&
        gCurrLevelNum != LEVEL_HMC &&
        gCurrLevelNum != LEVEL_LLL) {
        sprintf(starString, "Stars: %d out of 3", collectedStars);
    } else {
        sprintf(starString, "Stars: %d out of 1", collectedStars);
    }

    print_text(70, 50, starString);

    save_file_do_save(gCurrSaveFileNum - 1);
}

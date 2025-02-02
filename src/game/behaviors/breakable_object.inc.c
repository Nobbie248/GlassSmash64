#include "game/level_update.h"
#include "game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/ingame_menu.h"
#include "src/game/interaction.h"
#include "game/save_file.h"
#include "game/hud.h"

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

    if (gTotalBrokenObjects >= 30) {
        if (slideTime < 1830) {
            award_star(0);
            award_star(1);
            award_star(2);
        }
        else if (slideTime < 2130) {
            award_star(0);
            award_star(1);
        }
        else if (slideTime < 2730) {
            award_star(0);
        }

        gTotalBrokenObjects = 0;
        level_control_timer(TIMER_CONTROL_STOP);
    }
}


void breakable_object_behavior_loop(u32 sound, u32 particleModel,f32 particleSize1) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);
    struct Object* closehit = cur_obj_nearest_object_with_behavior(bhvClosehit);

    if ((brick && obj_check_if_collided_with_object(o, brick)) ||
        (brick2 && obj_check_if_collided_with_object(o, brick2)) ||
        (closehit && obj_check_if_collided_with_object(o, closehit)) ||
        cur_obj_was_attacked_or_ground_pounded()) {
        obj_mark_for_deletion(o);
        play_sound(sound, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, particleModel, particleSize1, 4);
        gMarioState->numCoins++;
        gTotalBrokenObjects++;
        check_and_spawn_star();
    }
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

void bhv_breakable_vase_loop(void) {
    breakable_object_behavior_loop(SOUND_GENERAL_BREAK_BOX, MODEL_CHINA_POP, 1.5f);
}

void bhv_breakable_target_loop(void) {
    breakable_object_behavior_loop(SOUND_OBJ_SNUFIT_SHOOT, MODEL_CRUMBLES, 2.0f);
}
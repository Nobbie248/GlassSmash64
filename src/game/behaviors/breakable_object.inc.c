#include "game/level_update.h"
#include "game/behavior_actions.h"
#include "include/behavior_data.h"
#include "src/game/ingame_menu.h"



void check_and_spawn_star(void) {
    if (gTotalBrokenObjects >= 30) {
        bhv_spawn_star_no_level_exit(STAR_BP_ACT_100_COINS);
        gTotalBrokenObjects = 0;
        level_control_timer(TIMER_CONTROL_STOP);
        play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
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

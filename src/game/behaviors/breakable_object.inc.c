

void bhv_breakable_object_init(void) {
    load_object_collision_model();
    cur_obj_become_tangible();
    obj_get_collision_data();
}



void bhv_breakable_object_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);

   

    if (obj_check_if_collided_with_object(o, brick)) {                         //need another one later I think
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_WHITE_PARTICLE_SMALL, 10.0f, 4);
        spawn_triangle_break_particles(10, MODEL_WHITE_PARTICLE_SMALL, 4.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
    }
    
    if (cur_obj_wait_then_blink(360, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
            if (cur_obj_was_attacked_or_ground_pounded()) {
                spawn_mist_particles_variable(0, 0, 46.0f);
                spawn_triangle_break_particles(15, MODEL_WHITE_PARTICLE_SMALL, 10.0f, 4);
                spawn_triangle_break_particles(10, MODEL_WHITE_PARTICLE_SMALL, 4.0f, 4);
        o->oAction = BREAKABLE_BOX_ACT_BROKEN;
                cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
                obj_mark_for_deletion(o);
                gMarioState->numCoins++;
            }
            
            
}

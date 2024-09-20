void bhv_breakable_object_init(void) {
    // load_object_collision_model(); // ignore this
}

void bhv_breakable_object_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);

    if (brick != NULL && obj_check_if_collided_with_object(o, brick)) {
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(20, MODEL_DIRT_ANIMATION, 3.0f, 4);
        create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
    }
    load_object_collision_model();
}

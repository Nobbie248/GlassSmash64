void bhv_breakable_object_loop(void) {
    if (obj_check_if_collided_with_object(o, bhvBrick)) {
        spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
        create_sound_spawner(SOUND_GENERAL2_BOBOMB_EXPLOSION);
        obj_mark_for_deletion(o);
    }
}


void bhv_breakable_object_init(void) {
    load_object_collision_model();
    cur_obj_become_tangible();
    obj_get_collision_data();
}



void bhv_breakable_glass_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);
    
if (brick != NULL) {
Vec3f pos  = { brick->oPosX, brick->oPosY, brick->oPosZ };
f32 offset = 200.f;
f32 extraX = 0.f;
f32 extraZ = 0.f;

    if (o->oFaceAngleYaw != DEGREES(180))
        extraX = 255.f;
    else
        extraZ = 255.f;

    if (((pos[0] < (o->oPosX + extraX + offset)) && (pos[0] > (o->oPosX - (offset + extraX))))
    && ((pos[1] < (o->oPosY + offset + 150.f))  && (pos[1] > (o->oPosY - (offset - 150.f))))
    && ((pos[2] < (o->oPosZ + extraZ + offset)) && (pos[2] > (o->oPosZ - (offset + extraZ))))) {
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_WHITE_PARTICLE_SMALL, 10.0f, 4);
        spawn_triangle_break_particles(10, MODEL_WHITE_PARTICLE_SMALL, 4.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
    
    }
}
    
    if (cur_obj_was_attacked_or_ground_pounded()) {
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_WHITE_PARTICLE_SMALL, 10.0f, 4);
        spawn_triangle_break_particles(10, MODEL_WHITE_PARTICLE_SMALL, 4.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
    }
}

void bhv_breakable_lantern_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);

    if (obj_check_if_collided_with_object(o, brick) || obj_check_if_collided_with_object(o, brick2)) {                         
        play_sound(SOUND_GENERAL_RACE_GUN_SHOT, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_SAND_DUST, 5.0f, 4);
        spawn_triangle_break_particles(10, MODEL_SAND_DUST, 3.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
        
    }
}

void bhv_breakable_statue_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);

    if (obj_check_if_collided_with_object(o, brick) || obj_check_if_collided_with_object(o, brick2)) {                         
        play_sound(SOUND_GENERAL_LOUD_POUND, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_SAND_DUST, 5.0f, 4);
        spawn_triangle_break_particles(10, MODEL_SAND_DUST, 3.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
        
    }
}

void bhv_breakable_vase_loop(void) {
    struct Object* brick = cur_obj_nearest_object_with_behavior(bhvBrick);
    struct Object* brick2 = cur_obj_nearest_object_with_behavior(bhvBrick2);

    if (obj_check_if_collided_with_object(o, brick) || obj_check_if_collided_with_object(o, brick2)) {                         
        play_sound(SOUND_GENERAL_BREAK_BOX, gGlobalSoundSource);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_triangle_break_particles(15, MODEL_SAND_DUST, 5.0f, 4);
        spawn_triangle_break_particles(10, MODEL_SAND_DUST, 3.0f, 4);
        
        obj_mark_for_deletion(o);

        gMarioState->numCoins++;
        
    }
}
// flame_mario.inc.c

extern Gfx burn_smoke_seg4_sub_dl_begin[];

void bhv_black_smoke_upward_loop(void) {
    spawn_object_with_scale(o, MODEL_BURN_SMOKE, bhvBlackSmokeBowser, o->header.gfx.scale[0]);
}

void bhv_black_smoke_bowser_loop(void) {
    if (o->oTimer == 0) {
        o->oForwardVel = random_float() * 2 + 0.5f;
        o->oMoveAngleYaw = random_u16();
        o->oVelY = 8.0f;

        o->oFlameScale = o->header.gfx.scale[0];
    }

    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
}

void bhv_black_smoke_mario_loop(void) {
    if (o->oTimer == 0) {
        cur_obj_set_pos_relative(gMarioObject, 0, 0, -30.0f);
        o->oForwardVel = random_float() * 2 + 0.5f;
        o->oMoveAngleYaw = (gMarioObject->oMoveAngleYaw + 0x7000) + random_float() * 8192.0f;
        o->oVelY = 8.0f;
    }

    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->oPosY += o->oVelY;
#ifdef BURN_SMOKE_FIX
    cur_obj_scale(1.0f + (o->oTimer / 16.0f));
    o->oOpacity -= 4;
    if (o->oOpacity < 10) {
        obj_mark_for_deletion(o);
    }
#endif
}

void bhv_flame_mario_loop(void) {
    cur_obj_scale(2.0f);

    if (o->oTimer & 1) {
        spawn_object(o, MODEL_BURN_SMOKE, bhvBlackSmokeMario);
    }

    gMarioObject->prevObj = o; // weird?
    obj_set_parent_relative_pos(o, 40, -120, 0);

    if (!(gMarioObject->oMarioParticleFlags & ACTIVE_PARTICLE_FIRE)) {
        o->parentObj->oActiveParticleFlags &= ~ACTIVE_PARTICLE_FIRE;
        obj_mark_for_deletion(o);
        gMarioObject->prevObj = NULL;
    }
}

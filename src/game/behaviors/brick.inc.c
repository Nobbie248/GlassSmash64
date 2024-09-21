
struct ObjectHitbox sBrickHitbox = { // hey hitbox!
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 100,
    /* height: */ 100,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
}; // bye hitbox..


void bhv_brick_init(void) {
    obj_set_hitbox(o, &sBrickHitbox); // lol
    o->oForwardVel = 80.0f;
    if (gMarioState->forwardVel >= 5.f) {
        o->oVelX = 100.0f * sins(gMarioState->faceAngle[1]);
        o->oVelZ = 100.0f * coss(gMarioState->faceAngle[1]);
    } else {
        o->oVelX = 50.0f * sins(gMarioState->faceAngle[1]);
        o->oVelZ = 50.0f * coss(gMarioState->faceAngle[1]);
    }
    
    o->oPosY = gMarioState->pos[1]; // now the brick can spawn at marios Y value :)
    o->oVelY = 38.0f;
    o->oGravity = -1.8f;
    o->oTimer = 0;
    o->oAngleVelPitch = 0x400;
}

void bhv_brick_loop(void) { 
    
    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(1);
    o->oVelY += o->oGravity;

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;

    o->oFaceAnglePitch += o->oAngleVelPitch;

    if (cur_obj_wait_then_blink(45, 0)) {
        obj_mark_for_deletion(o);
    }
    if (o->oForwardVel <= 20.0f) {
        o->oAngleVelPitch = 0x1200;
    }


    
    
}
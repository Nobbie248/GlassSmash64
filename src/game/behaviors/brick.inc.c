struct ObjectHitbox sBrickHitbox = { // hey hitbox!
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 80,
    /* hurtboxRadius: */ 80,
    /* hurtboxHeight: */ 80,
}; // bye hitbox..


void bhv_brick_init(void) {
    obj_set_hitbox(o, &sBrickHitbox);

    if (gMarioState->forwardVel >= 2.f) {
        o->oForwardVel = 120.0f;  
    } else {
        o->oForwardVel = 80.0f;
    } 
    o->oPosY = gMarioState->pos[1];
    o->oVelY = 38.0f;
    o->oGravity = -1.8f;
    o->oTimer = 0;
    o->oAngleVelPitch = 0x400;
}

void bhv_brick_loop(void) { 
    o->oCoinBounceTimer++;   
    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(1);
    o->oVelY += o->oGravity;
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;
    o->oFaceAnglePitch += o->oAngleVelPitch;
    
    if (cur_obj_wait_then_blink(80, 0)) {   
        obj_mark_for_deletion(o);
    }
    if (o->oCoinBounceTimer > 20) {
        o->oAngleVelPitch = 0x1300;        
    }
    if (o->oCoinBounceTimer > 40) {
        o->oAngleVelPitch = 0x600;           
    }    
    if (o->oMoveFlags & OBJ_MOVE_LANDED & o->oForwardVel < 70.0f) {
        o->oFaceAnglePitch = 0;
        o->oAngleVelPitch = 0;      
    }
    if (o->oCoinBounceTimer > 70) {
        o->oFaceAnglePitch = 0;
        o->oAngleVelPitch = 0;
        o->oVelY = 0.f;
        o->oDragStrength = 800.0f;
    }
}

void bhv_brick_init2(void) {
    obj_set_hitbox(o, &sBrickHitbox);
    o->oPosY = gMarioState->pos[1];
    o->oVelY = 50.f;
    o->oGravity = -1.8f;
    o->oTimer = 0;
    o->oAngleVelPitch = 0x400;
    
}
    
void bhv_brick_loop2(void) {
    o->oCoinBounceTimer++;   
    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(1);
    o->oVelY += o->oGravity;
    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;
    o->oFaceAnglePitch += o->oAngleVelPitch;

    if (cur_obj_wait_then_blink(80, 0)) {   
        obj_mark_for_deletion(o);
    }
    if (o->oCoinBounceTimer > 20) {
        o->oAngleVelPitch = 0x1300;       
    }
    if (o->oCoinBounceTimer > 50) {
        o->oAngleVelPitch = 0x600;         
    }
    if (o->oMoveFlags & OBJ_MOVE_LANDED) {
        o->oFaceAnglePitch = 0;
        o->oAngleVelPitch = 0;        
    }
    if (o->oCoinBounceTimer > 90) {
        o->oFaceAnglePitch = 0;
        o->oAngleVelPitch = 0;
        o->oVelY = 0.f;
        o->oDragStrength = 200.0f;
    } 
}



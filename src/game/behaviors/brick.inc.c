
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
    
    if (gMarioState->forwardVel >= 5.f) {
        o->oVelX = 100.0f * sins(gMarioState->faceAngle[1]);
        o->oVelZ = 100.0f * coss(gMarioState->faceAngle[1]);
    } else {
        o->oVelX = 50.0f * sins(gMarioState->faceAngle[1]);
        o->oVelZ = 50.0f * coss(gMarioState->faceAngle[1]);
    }
    
    o->oPosY = gMarioState->pos[1]; // now the brick can spawn at marios Y value :)
    o->oVelY = 45.0f;
    o->oGravity = -5.0f;
    o->oTimer = 0;
    o->oAngleVelPitch = 0x400;
}

void bhv_brick_loop(void) {
    o->oVelY += o->oGravity;

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;

    o->oFaceAnglePitch += o->oAngleVelPitch;

    struct Surface *surface;
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &surface); // not the final detection system i will make a better one if, i don't forget lol
    if (floorHeight < 0.0f) {
        obj_mark_for_deletion(o);
    }
}
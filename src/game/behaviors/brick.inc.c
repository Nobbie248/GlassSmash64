

void bhv_brick_init(void) {
    if (gMarioState->forwardVel >= 5.f) {
    o->oVelX = 100.0f * sins(gMarioState->faceAngle[1]);
    o->oVelZ = 100.0f * coss(gMarioState->faceAngle[1]);
    } else {
    o->oVelX = 50.0f * sins(gMarioState->faceAngle[1]);
    o->oVelZ = 50.0f * coss(gMarioState->faceAngle[1]);
    }
    
    
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
    f32 floorHeight = find_floor(o->oPosX, o->oPosY, o->oPosZ, &surface); // not the final detection system i will make a better one
    if (floorHeight < 0.0f) {
        obj_mark_for_deletion(o);
    }
}
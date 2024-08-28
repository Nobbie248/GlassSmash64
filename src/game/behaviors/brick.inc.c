// brick.inc.c

struct ObjectHitbox sBrickHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 150,
    /* height:            */ 250,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 250,
};

#define LOAD_OBJECT_FROM_GEO(MODEL_BRICK, brick_geo)

void bhv_brick_init(void) {
    o->oGravity = 2.5f;
    o->oFriction = 0.99f;
    o->oBuoyancy = 1.4f;
    
    obj_set_hitbox(o, &sBrickHitbox);
    o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_brick_loop(void) {
    switch (o->oHeldState) {
        create_respawner(MODEL_BRICK, bhvBrick, 3000);

        case HELD_FREE:
            brick_thrown();
            break;

    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void brick_thrown(void) {
    o->oForwardVel = 40.0f;
    o->oVelY = 20.0f;

    o->oVelX = 10.0f;  // adjust the value if you want idk if it’s right

    o->oFaceAngleYaw += 0x4000;  // rotation to make it a little realistic
}
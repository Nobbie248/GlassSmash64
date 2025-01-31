struct ObjectHitbox sClosehitHitbox = { 
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 100,
    /* hurtboxRadius: */ 80,
    /* hurtboxHeight: */ 100,
};

void bhv_close_hit_loop(void) {
    obj_set_hitbox(o, &sClosehitHitbox);
    if (o->oTimer >= 60) { 
        obj_mark_for_deletion(o);
    }
}

struct ObjectHitbox sClosehitHitbox = { 
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 80,
    /* height: */ 80,
    /* hurtboxRadius: */ 80,
    /* hurtboxHeight: */ 80,
};

void bhv_close_hit_loop(void) {
    obj_set_hitbox(o, &sClosehitHitbox);
    o->oTimer++;
    
    
    if (o->oTimer > 30) {
        
        obj_mark_for_deletion(o);
    }
}

struct ObjectHitbox sClosehitHitbox = { 
    /* interactType: */ INTERACT_COIN,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 0,
    /* health: */ 1,
    /* numLootCoins: */ 0,
    /* radius: */ 100,
    /* height: */ 100,
    /* hurtboxRadius: */ 100,
    /* hurtboxHeight: */ 100,
};

void bhv_close_hit_loop(void) {
    obj_set_hitbox(o, &sClosehitHitbox);
    o->oTimer++;
    
    
    if (o->oTimer > 30) {
        
        obj_mark_for_deletion(o);
    }
}

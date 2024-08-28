// breakable_box.inc.c

struct ObjectHitbox sBreakableBoxHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  20,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 150,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 200,
};

struct ObjectHitbox sWindowBoxHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */  200,
    /* damageOrCoinValue: */   0,
    /* health:            */   1,
    /* numLootCoins:      */   0,
    /* radius:            */ 200,
    /* height:            */ 400,
    /* hurtboxRadius:     */ 150,
    /* hurtboxHeight:     */ 400,
};

void breakable_box_init(void) {
    o->oHiddenObjectSwitchObj = NULL;
    o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    switch (o->oBehParams2ndByte) {
        case BREAKABLE_BOX_BP_NO_COINS: o->oNumLootCoins = 0; break;
        case BREAKABLE_BOX_BP_3_COINS:  o->oNumLootCoins = 3; break;
        case BREAKABLE_BOX_BP_5_COINS:  o->oNumLootCoins = 5; break;
        case BREAKABLE_BOX_BP_LARGE:    cur_obj_scale(1.5f);  break;
    }
}

void hidden_breakable_box_actions(void) {
    struct Object *switchObj;
    obj_set_hitbox(o, &sBreakableBoxHitbox);
    cur_obj_set_model(MODEL_BREAKABLE_BOX);
    switch (o->oAction) {
        case BREAKABLE_BOX_ACT_HIDDEN:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            if (o->oTimer == 0) {
                breakable_box_init();
            }
            if (o->oHiddenObjectSwitchObj == NULL) {
                o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvFloorSwitchHiddenObjects);
            }
            switchObj = o->oHiddenObjectSwitchObj;
            if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
                o->oAction = BREAKABLE_BOX_ACT_ACTIVE;
                cur_obj_enable_rendering();
                cur_obj_unhide();
            }
            break;
        case BREAKABLE_BOX_ACT_ACTIVE:
            cur_obj_become_tangible();
            int time = gCurrCourseNum == COURSE_JRB ? 600 : 400;
            if (cur_obj_wait_then_blink(time - 40, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
            if (cur_obj_was_attacked_or_ground_pounded()) {
                spawn_mist_particles();
                spawn_triangle_break_particles(30, MODEL_DIRT_ANIMATION, 3.0f, TINY_DIRT_PARTICLE_ANIM_STATE_YELLOW);
                o->oAction = BREAKABLE_BOX_ACT_BROKEN;
                cur_obj_play_sound_2(SOUND_GENERAL_BREAK_BOX);
            }
            load_object_collision_model();
            break;
        case BREAKABLE_BOX_ACT_BROKEN:
            cur_obj_become_intangible();
            cur_obj_disable_rendering();
            o->oInteractStatus = INT_STATUS_NONE;
            switchObj = o->oHiddenObjectSwitchObj;
            if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_IDLE)) {
                o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
            }
            break;
    }
}

extern const Collision c1_leaf_collision[];
extern const Collision c3_spin_collision[];
extern const Collision c3_spin_burn_collision[];
extern const Collision c4_platform_collision[];
static const void * kCollisions[] = {
    c1_leaf_collision,
    c3_spin_collision,
    c4_platform_collision,
};

static void hb_set_rendering(int enabled)
{
    if (enabled)
    {
        if (1 == o->oBehParams2ndByte)
        {
            obj_set_model(o, MODEL_C1_LEAF);
        }
        else
        {
            cur_obj_enable_rendering();
        }
    }
    else
    {
        if (1 == o->oBehParams2ndByte)
        {
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
            obj_set_model(o, MODEL_C1_LEAF_TR);
        }
        else
        {
            cur_obj_disable_rendering();
        }
    }
}

void hidden_unbreakable_box_actions(void) {
    struct Object *switchObj;
    if (o->oOpacity != 0)
        obj_set_collision_data(o, kCollisions[o->oBehParams2ndByte - 1]);
    else
        obj_set_collision_data(o, c3_spin_burn_collision);

    switch (o->oAction) {
        case BREAKABLE_BOX_ACT_HIDDEN:
            hb_set_rendering(0);
            cur_obj_become_intangible();
            if (o->oHiddenObjectSwitchObj == NULL) {
                o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvFloorSwitchHiddenObjects);
            }
            switchObj = o->oHiddenObjectSwitchObj;
            if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
                o->oAction = BREAKABLE_BOX_ACT_ACTIVE;
                hb_set_rendering(1);
                cur_obj_unhide();
            }
            break;
        case BREAKABLE_BOX_ACT_ACTIVE:
            cur_obj_become_tangible();
            int time = gCurrCourseNum == COURSE_JRB ? 600 : 400;
            if (cur_obj_wait_then_blink(time - 40, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
            load_object_collision_model();
            break;
    }
}

void bhv_hidden_object_init()
{
    o->oOpacity = 255;
    if (1 == o->oBehParams2ndByte)
    {
        o->oFaceAnglePitch = 0x623;
        o->oMoveAngleYaw = 1111 * (o->oPosZ + o->oPosY + o->oPosX);
        obj_scale(o, 0.9f);
    }

    if (3 == o->oBehParams2ndByte)
    {
        o->oDrawingDistance = 30000.f;
    }
}

void bhv_hidden_object_loop(void) {
    if (o->oBehParams2ndByte == BREAKABLE_BOX_BP_NO_COINS) {
        hidden_breakable_box_actions();
    } else {
        if (1 == o->oBehParams2ndByte)
        {
            o->oMoveAngleYaw += 0x99;
        }
        if (2 == o->oBehParams2ndByte)
        {
            o->oMoveAngleYaw += 0x69;
            f32 amt;
            if (o->oPosY < 2000.f)
                amt = CLAMP(2 * sins(o->oMoveAngleYaw), 0, 1.f);
            else
                amt = CLAMP(-2 * sins(o->oMoveAngleYaw), 0, 1.f);

            o->oOpacity = 255 * amt;
            //o->oFaceAngleRoll = -0x4000 * (1.f - amt);
            //obj_scale_xyz(o, amt, 1.f, 1.f);
        }

        hidden_unbreakable_box_actions();
    }
}

void bhv_breakable_box_loop(void) {
    if (o->behavior == segmented_to_virtual(bhvbreakwindow))
    {
        obj_set_hitbox(o, &sWindowBoxHitbox);
    }
    else
    {
        obj_set_hitbox(o, &sBreakableBoxHitbox);
    }
    if (o->oTimer == 0) breakable_box_init();
    if (cur_obj_was_attacked_or_ground_pounded()) {
        obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
        create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
    }
}

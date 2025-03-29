#include "src/game/ingame_menu.h"
int gIsArrow;
static struct Object *cur_obj_find_nearest_object_with_behaviors_y_biased(const BehaviorScript *behaviors[], s32 behaviorCount) {
    struct Object *closestObj = NULL;
    f32 minDist = 0x200000000;

    for (s32 i = 0; i < behaviorCount; i++) {
        uintptr_t *behaviorAddr = segmented_to_virtual(behaviors[i]);
        struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
        struct Object *obj = (struct Object *) listHead->next;

        while (obj != (struct Object *) listHead) {
            if (obj->behavior == behaviorAddr
                && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
                && obj != o) {
                
                f32 dx = o->oPosX - obj->oPosX;
                f32 dy = o->oPosY - obj->oPosY;
                f32 dz = o->oPosZ - obj->oPosZ;
                f32 objDist = dx * dx + 10 * dy * dy + dz * dz;

                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
            obj = (struct Object *) obj->header.next;
        }
    }

    return closestObj;
}

void bhv_red_coin_radar_init() {
    if (o->oBehParams2ndByte == gCurrActNum) {
        cur_obj_unhide();
    } else {
        cur_obj_hide();
    }
}

void bhv_red_coin_radar_loop() {
    if (gIsArrow == TRUE) {
        
        cur_obj_unhide();

    } else if (gIsArrow == FALSE) {
        cur_obj_hide();
    }


    obj_scale(o, 0.3f);

    const BehaviorScript *red_coin_targets[] = {
        bhvAztecPots, bhvBarrel, bhvKite, bhvDiamond, bhvOogaboogas,
        bhvChest, bhvBottle, bhvBallsaver, bhvVase,bhvStatue, bhvLantern,
        bhvGlass, bhvBubbly, bhvMushy, bhvBnet,bhvJStatues
    };

    struct Object *red = cur_obj_find_nearest_object_with_behaviors_y_biased(red_coin_targets, sizeof(red_coin_targets) / sizeof(red_coin_targets[0]));

    if (!red) {
        o->activeFlags = 0;
        return;
    }

    o->oPosX = gMarioStates->pos[0];
    o->oPosY = gMarioStates->pos[1] + 150.0f;
    o->oPosZ = gMarioStates->pos[2];

    f32 dx = o->oPosX - red->oPosX;
    f32 dy = o->oPosY - red->oPosY;
    f32 dz = o->oPosZ - red->oPosZ;
    f32 l = sqrtf(dx * dx + dz * dz);

    s16 yaw = atan2s(dz, dx) + 0x8000;
    s16 pitch = atan2s(l, dy);
    
    o->oFaceAngleYaw = yaw;
    o->oPosX += sins(yaw) * 80.0f;
    o->oPosZ += coss(yaw) * 80.0f;
    o->oFaceAnglePitch = pitch;
}

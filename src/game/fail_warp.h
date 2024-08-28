#pragma once

#include "types.h"

struct ObjectWarpNode* fail_warp_area_get_warp_node(void);
void fail_warp_pre_level_trigger_warp(struct MarioState *m, s32* warpOp);
void fail_warp_init_mario_after_quick_warp(struct MarioState *m);
void fail_warp_init_mario_after_quick_warp_reset_camera(struct Object* spawnObject);
void fail_warp_mario_set_safe_pos(struct MarioState *m, struct Surface *floor);

// Extra hook that can be used for custom coding
void fail_warp_trigger(struct MarioState* m);

extern struct Object gFailWarpSpoofedWarpObject;

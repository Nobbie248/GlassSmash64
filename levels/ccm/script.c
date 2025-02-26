#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common0.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bob, generic), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bob), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 32, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 31, WARP_NO_CHECKPOINT),
		WARP_NODE(25, LEVEL_CCM, 1, 26, WARP_NO_CHECKPOINT),
		WARP_NODE(26, LEVEL_CCM, 1, 25, WARP_NO_CHECKPOINT),
		WARP_NODE(24, LEVEL_CCM, 1, 23, WARP_NO_CHECKPOINT),
		WARP_NODE(23, LEVEL_CCM, 1, 24, WARP_NO_CHECKPOINT),
		WARP_NODE(19, LEVEL_CCM, 2, 18, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_CCM, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CCM, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_CCM, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CCM, 1, 0, WARP_NO_CHECKPOINT),
		MARIO_POS(1, 180, -3851, 173, 7738),
		OBJECT(0, -3851, 173, 7738, 0, 180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_BALL, 4917, 503, 3835, 0, 0, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_BALL, 59, 236, 7433, 0, 0, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_BALL, -2778, 474, 3807, 0, 0, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_BALL, -207, 276, -3025, 0, 0, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_BARREL, -761, 1004, 2105, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BARREL, 164, 536, 4796, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BARREL, 2346, 540, 4796, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BARREL, 2639, 466, 4796, 0, -120, 93, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BARREL, -2894, 454, 1128, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BARREL, 951, 622, 378, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_BOTTLE, -88, 744, -510, 0, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, -418, 536, -510, 76, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, 3399, 418, -193, 0, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, 3399, 407, 613, 76, -52, -11, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, -3009, 235, -967, 90, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, 996, 671, 5015, 0, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_BOTTLE, 1583, 671, 5015, 0, 0, 0, 0x00000000, bhvBottle),
		OBJECT(MODEL_CHEST, -629, 2041, 1393, 0, -180, 0, 0x00000000, bhvChestbarrel),
		OBJECT(MODEL_DIAMOND, -2120, 1142, 1269, 0, 0, 0, 0x00000000, bhvDiamond),
		OBJECT(MODEL_KITE, -988, 2565, 5420, 0, 84, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_KITE, -3256, 2565, 4484, 0, -52, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_KITE, 936, 2507, 6037, 0, -84, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_KITE, 2588, 2507, 5559, 0, 118, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_KITE, 2588, 1283, -1344, 0, 53, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_OOGABOOGA2, 3039, 463, 410, 0, 0, 0, 0x00000000, bhvOogaboogas),
		OBJECT(MODEL_OOGABOOGA, -2049, 1861, 1506, 0, -85, 0, 0x00000000, bhvOogaboogas),
		OBJECT(MODEL_OOGABOOGA, 822, 1851, 2475, 0, 85, 0, 0x00000000, bhvOogaboogas),
		OBJECT(MODEL_SAVER, -467, 893, 4674, 0, 128, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_SAVER, 5324, 226, -332, 82, -90, 0, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_SAVER, 1787, 170, 9992, 90, 0, 90, 0x00000000, bhvBallsaver),
		OBJECT(MODEL_NONE, 1727, -638, 3836, 0, 0, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_UNBRELLA_BLUE, -4473, 205, 4924, 0, 180, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_PINK, -3594, 346, 3057, 0, -180, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_PINK, -2626, 382, 5663, 0, -45, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_BLUE, -1641, 387, 4455, 0, -45, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_BLUE, 101, 346, 5816, 0, -90, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_PINK, 1819, 325, 5816, 0, 0, 0, 0x00000000, bhvBounce2),
		OBJECT(MODEL_UNBRELLA_BLUE, 3322, 344, 4993, 0, 0, 0, 0x00000000, bhvBounce2),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2E),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 180, -3851, 173, 7738),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
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

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0(0xa, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_C1_LEAF, c1_leaf_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C1_LEAF_TR, c1_leaf_tr_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_STAR, gem_star_green_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 3, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 9, WARP_NO_CHECKPOINT),
		WARP_NODE(9, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_BOB, 2, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_BOB, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1045, 3317, -6355, 0, 0, 0, 0x00000000, bhvCS),
		MARIO_POS(3, 0, -1345, -569, 841),
		MARIO_POS(0x01, 0, -1345, -569, 841),
		OBJECT(212, 706, -1933, -2490, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, 4386, -2727, -4168, 0, 0, 0, 0xe0000, bhvAirborneWarp),
		OBJECT(140, 1418, 1752, 2385, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(223, 1057, 3246, -6609, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 2574, 3246, -5908, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 4602, 3246, -1743, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(88, 1289, -3472, -5900, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(88, 4693, -3472, -1751, 0, -65, 0, 0x0, bhvClamShell),
		OBJECT(88, -3, -3472, -1612, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(0, 258, 1721, 1955, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -2938, 531, -5075, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(0, 1103, -2699, -1751, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(0, 746, 73, -2304, 0, 85, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3586, -11, -5280, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -2461, -3472, -2515, 0, 3, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 1102, 2931, -2012, 0, -64, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3328, 1752, 595, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4619, 3246, -4213, 0, 24, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -377, 4019, -6658, 0, 97, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3770, -84, -2750, 0, -10, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 5562, -2903, -1039, 0, -10, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 4802, 665, -4568, 0, -10, 0, 0x110000, bhvCoinFormation),
		OBJECT(137, 3058, 297, 1764, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(137, -3187, 297, -1290, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(0, 2394, 2353, 1894, 0, 48, 0, 0x90000, bhvFadingWarp),
		OBJECT(0, 1395, 405, -6895, 0, -39, 0, 0xb0000, bhvFadingWarp),
		OBJECT(207, -1189, -11, 1151, 0, -180, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 2450, -11, -3857, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1183, -1, -711, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 4609, 3246, -4277, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -3341, 1752, 228, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -753, 1752, 1917, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1539, 1752, 1827, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, -600, 2342, 2406, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -2054, 2342, 1320, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3194, 2342, 2035, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(MODEL_C1_LEAF_TR, -3289, 2366, -14, 0, -13, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_C1_LEAF_TR, -3361, 2088, 293, 0, -13, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_C1_LEAF_TR, -3430, 1822, 574, 0, -13, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_C1_LEAF_TR, -3006, 3022, -1055, 0, -19, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_C1_LEAF_TR, -2441, 291, 1026, 0, -13, 0, (1 << 16), bhvHiddenObject),
		OBJECT(0, 3588, 169, -5280, 0, -6, 179, 0x3000000, bhvHiddenRedCoinStar),
		OBJECT(190, 1332, -3472, -5898, 0, 0, 0, 0x0, bhvKoopaShellUnderwater),
		OBJECT(0, 200, -2753, 1047, 0, 0, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, 104, -3173, -3017, 0, 0, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, 3751, -3050, -1891, 0, 0, 0, 0x0, bhvLargeFishGroup),
		OBJECT(124, -1931, -11, -3538, 0, -90, 0, 0x320000, bhvMessagePanel),
		OBJECT(116, -2584, 1871, -1534, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -2710, 1655, -1358, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(215, 783, -217, -2302, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2652, 992, 634, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2708, 2188, -1662, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5301, 136, -6073, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -827, 610, 268, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2920, 545, -5057, 0, 74, 0, 0x0, bhvRedCoin),
		OBJECT(215, 182, -11, -6727, 0, 74, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3754, 406, -2742, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -2838, 248, -3961, 0, 77, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -2159, 3625, -5438, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 4924, 2654, -3726, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 1922, 375, -6419, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, -2803, 3601, -1516, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(86, 717, -2539, -2492, 0, 0, 0, 0x0, bhvSushiShark),
		OBJECT(85, 4436, -2833, -5106, 0, 0, 0, 0x0, bhvUnagi),
		OBJECT(0, 4379, -2773, -4932, 0, 0, 0, 0xc0000, bhvWarp),
		OBJECT(22, 909, 0, 1968, 0, 0, 0, 0x70000, bhvWarpPipe),
		OBJECT(0, 303, 904, 1139, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		OBJECT(MODEL_RED_COIN_ARROW, -1104, 2173, 1386, 0, 0, 0, (4 << 16), bhvRedCoinRadar),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_BOB, 1, 7, WARP_NO_CHECKPOINT),
		OBJECT(223, 1090, 140, -4778, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 1278, 137, -3326, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, 1201, 128, -2275, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1160, 107, -6503, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(101, 1557, 1642, -4831, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 695, 1650, -6735, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 896, 1718, -1934, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(122, 1132, 833, -10541, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(100, 1324, 2140, -1634, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1224, 2250, -7187, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1367, 806, -2210, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 1039, 507, -9106, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(22, 1215, 1570, -8015, 0, 0, 0, 0x80000, bhvWarpPipe),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 3, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, 240, 245, 1030, 0, 0, 0, 0x0, bhvGem),
		OBJECT(0, 582, -90, 2920, 0, -170, 0, 0xa0000, bhvAirborneWarp),
		OBJECT(0, 446, -597, 2211, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 395, -597, 1917, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 342, -597, 1621, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 135, -597, 438, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 291, -597, 1325, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 240, -597, 1030, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 186, -597, 732, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 82, -597, 142, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 727, 582, 2871, 0, 0, 0, 0xd0000, bhvWarp),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -1345, -569, 841),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

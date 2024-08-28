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

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bits, sky), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bits), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 38, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_BITS, 1, 15, WARP_NO_CHECKPOINT),
		WARP_NODE(15, LEVEL_BITS, 1, 16, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BITS, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BITS, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(69, LEVEL_BOWSER_3, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(39, LEVEL_BITS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(0x69, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HEART, 4496, 5016, -5040, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(212, -7270, 2454, 1180, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(212, 1135, 5267, -12010, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(65, 4500, 6138, 10183, 0, -90, 0, 0x0, bhvAnimatesOnFloorSwitchPress),
		OBJECT(0, 4495, 4098, -6049, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 4499, 7694, 12257, 0, 0, 0, 0x270000, bhvDeathWarp),
		OBJECT(0, 1758, 6492, -1470, 0, 0, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 4491, 6138, -5416, 0, 0, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 7253, 6492, -1469, 0, 0, 0, 0xf0000, bhvFadingWarp),
		OBJECT(0, 4491, 6138, -5416, 0, 0, 0, 0x100000, bhvFadingWarp),
		OBJECT(180, -614, 2519, -10171, 0, -37, 0, 0x0, bhvFireSpitter),
		OBJECT(0, -2786, 2274, -9786, 0, 89, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -732, 2274, -10241, 0, -129, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -419, 2334, -12316, 0, -4, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 2483, 3300, -10411, 0, 178, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 4065, 3504, -11635, 0, -38, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 3575, 3408, -9701, 0, 88, 0, 0x0, bhvFlamethrower),
		OBJECT(207, 4497, 6138, 8569, 0, -180, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(0, -10264, 365, 6375, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(124, 7246, 6258, -1472, 0, 0, 0, 0x3e0000, bhvMessagePanel),
		OBJECT(124, 1755, 6258, -1475, 0, 0, 0, 0x3e0000, bhvMessagePanel),
		OBJECT(124, 1136, 5135, -12233, 0, 0, 0, 0x400000, bhvMessagePanel),
		OBJECT(85, -4031, 2763, 668, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(85, -3835, 3267, 1363, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(85, -3237, 3771, 2151, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(MODEL_HEART, -1845, 4194, -447, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(MODEL_NONE, 3904, 7065, 5853, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(206, -10439, 419, 7875, 0, 15, 0, 0x0, bhvSnufit),
		OBJECT(206, -10034, 750, 5113, 0, -22, 0, 0x0, bhvSnufit),
		OBJECT(0, -10200, 0, 12457, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, 4494, 7670, 14457, 0, 0, 0, 0x450000, bhvWarpPipe),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2C),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

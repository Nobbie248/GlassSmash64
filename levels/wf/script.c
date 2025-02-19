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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_STAIRS, c2_ladders_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_STAR, gem_star_blue_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x02, LEVEL_WF, 0x02, 0x03, WARP_NO_CHECKPOINT),
		WARP_NODE(0x03, LEVEL_WF, 0x01, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_LEAVES_PILE, 2534, 1872, -4260, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 2662, 1983, -5646, 9, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 3515, 2066, -5932, 10, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -2919, 1053, 724, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -2619, 1053, 973, 0, 0, 0, 0x00000000, bhvPileLeaves),
		MARIO_POS(0x01, 0, -3258, 491, 3582),
		OBJECT(MODEL_RED_MUSHROOM, -869, 0, -13001, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 2509, 0, 843, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 398, 0, 1540, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 5044, 0, -562, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, -1464, 0, 496, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 223, 0, -14522, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_NONE, 580, 1701, -15786, 0, 0, 0, (0x02 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1216, 1701, -15724, 0, 0, 0, (0x02 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 1904, 1701, -15550, 0, 0, 0, (0x02 << 16), bhvWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		OBJECT(MODEL_NONE, 101, 1232, 0, 0, 0, 0, (0x03 << 16), bhvSpinAirborneWarp),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -3258, 491, 3582),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

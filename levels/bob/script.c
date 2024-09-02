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
		OBJECT(MODEL_NONE, 2046, 1079, 0, 0, 0, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_GLASS, 3177, 396, 327, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3177, 396, 1911, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3177, 396, -896, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3177, 396, -2479, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 4265, 396, -896, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 4265, 396, -2479, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3177, 396, -3454, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3721, 396, -896, 0, 0, 0, 0x00000000, bhvGlass),
		MARIO_POS(3, 0, 715, 203, 0),
		MARIO_POS(0x01, 0, 715, 203, 0),
		OBJECT(0, 713, 100, 0, 0, 0, 0, 0xe0000, bhvAirborneWarp),
		OBJECT(0, 724, 100, 0, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 1062, 790, 7274, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 715, 203, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

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
#include "actors/group0.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, castle_inside, inside), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_16), 
	JUMP_LINK(script_func_vo_castle_inside), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SL_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_L, beta_door_l_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_R, beta_door_r_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_BLUE, gem_blue_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_GREEN, gem_green_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_PURPLE, gem_purple_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_RED, gem_red_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_JABO, jabo_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 37, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 35, WARP_NO_CHECKPOINT),
		WARP_NODE(44, LEVEL_BBH, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(38, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(18, LEVEL_BITS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(37, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(32, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(31, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_CCM, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(17, LEVEL_JRB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(22, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(0, 0, 517, 0, 0, 48, 0, 0x60000, bhvAirborneDeathWarp),
		OBJECT(0, 0, 517, 0, 0, -55, 0, 0x40000, bhvAirborneDeathWarp),
		OBJECT(0, 0, 517, 0, 0, -90, 0, 0x80000, bhvAirborneDeathWarp),
		OBJECT(0, 0, 517, 0, 0, 90, 0, 0x200000, bhvAirborneDeathWarp),
		OBJECT(0, 0, 517, 0, 0, 49, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 517, 0, 0, -55, 0, 0x30000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 517, 0, 0, -90, 0, 0x70000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 517, 0, 0, 90, 0, 0x1f0000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 517, 0, 0, -180, 0, 0x250000, bhvDeathWarp),
		OBJECT(0, 0, 517, 0, 0, -180, 0, 0x260000, bhvDeathWarp),
		OBJECT(0, 0, 900, 0, 0, 0, 0, 0x2c1e00, bhvFadingWarp),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(0, 0, 0, 0, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 679, 0, -946, 0, 136, 0, 0xe0000, bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 0, 0, -710, 0, -39, 0, 0x100000, bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 558, 0, -710, 0, 0, 0, 0x110000, bhvWarpPipe),
		OBJECT(0, 0, 900, 654, 0, -90, 0, 0xd0000, bhvWarp),
		OBJECT(0, 0, 900, 654, 0, 0, 0, 0x120000, bhvWarp),
		OBJECT(0, 0, 900, 654, 0, 136, 0, (22 << 16), bhvDeathWarp),
		// OBJECT(MODEL_NONE, 0, 611, -946, 0, 0, 0, 0x00000000, ),
		// OBJECT(MODEL_NONE, 1128, 611, -440, 0, 0, 0, 0x00000000, ),
		// OBJECT(MODEL_NONE, -964, 611, -440, 0, 0, 0, 0x00000000, ),
		OBJECT(MODEL_NONE, 0, 124, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2b),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

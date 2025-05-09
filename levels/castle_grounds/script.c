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
		OBJECT(MODEL_4DCUBE, 1581, 293, 5883, 0, 0, 0, 0x00000000, bhv4dcube),
		MARIO_POS(0x01, 0, 0, 0, -334),
		OBJECT(0, 2730, 59, 1970, 0, 0, 0, 0x60000, bhvAirborneDeathWarp),
		OBJECT(0, -542, 59, 3959, 0, -90, 0, 0x40000, bhvAirborneDeathWarp),
		OBJECT(0, 920, 59, 5877, 0, 90, 0, 0x80000, bhvAirborneDeathWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x30000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x70000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x1f0000, bhvAirborneStarCollectWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x250000, bhvDeathWarp),
		OBJECT(0, 0, 2110, -334, 0, 0, 0, 0x260000, bhvDeathWarp),
		OBJECT(0, 0, 2493, -334, 0, 0, 0, 0x2c1e00, bhvFadingWarp),
		OBJECT(0, 0, 0, -334, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_PURPLE_PIPE, -953, 0, 1701, 0, 0, 0, 0xe0000, bhvWarpPipe),
		OBJECT(MODEL_PURPLE_PIPE, 956, 0, 3878, 0, 0, 0, 0x100000, bhvWarpPipe),
		OBJECT(MODEL_PURPLE_PIPE, -952, 0, 5791, 0, 0, 0, 0x110000, bhvWarpPipe),
		OBJECT(0, 0, 2493, 319, 0, -90, 0, 0xd0000, bhvWarp),
		OBJECT(0, 0, 2493, 319, 0, 0, 0, 0x120000, bhvWarp),
		OBJECT(0, 0, 2493, 319, 0, 136, 0, (22 << 16), bhvDeathWarp),
		OBJECT(MODEL_PURPLE_PIPE, 952, 0, 7700, 0, -90, 0, 0xd0000, bhvWarpPipe),
		OBJECT(MODEL_NONE, 0, 124, -665, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_CAR, 2738, 0, 1965, 0, 0, 0, 0x00000000, bhvCar),
		OBJECT(MODEL_NONE, -953, 0, 1701, 0, 0, 0, 0x00000000, bhvHubtext1),
		OBJECT(MODEL_NONE, 956, 0, 3879, 0, 0, 0, 0x00000000, bhvHubtext2),
		OBJECT(MODEL_NONE, -952, 0, 5790, 0, 0, 0, 0x00000000, bhvHubtext3),
		OBJECT(MODEL_NONE, 951, 0, 7701, 0, 0, 0, 0x00000000, bhvHubtext4),
		OBJECT(MODEL_NONE, 2734, 0, 1971, 0, 0, 0, 0x00000000, bhvHubtext5),
		OBJECT(MODEL_NONE, -990, 0, 3981, 0, 0, 0, 0x00000000, bhvHubtext6),
		OBJECT(MODEL_NONE, 1582, 0, 5886, 0, 0, 0, 0x00000000, bhvHubtext7),
		OBJECT(MODEL_MIXER, -987, 139, 3978, 0, 90, 0, 0x00000000, bhvMixer),
		OBJECT(MODEL_NONE, -441, 0, 7673, 0, 90, 0, (167 << 16), bhvMessagePanel),
		OBJECT(MODEL_TARGETS, 1201, 325, -594, 0, 0, 90, 0, bhvTarget),
		OBJECT(MODEL_TARGETS, 1201, 325, 239, 0, 0, 90, 0, bhvTarget),
		OBJECT(MODEL_TARGETS, -1211, 645, 239, 0, 0, 0, 0, bhvTarget),
		OBJECT(MODEL_TARGETS, -1211, 130, -590, 0, 0, 0, 0, bhvTarget),
		OBJECT(MODEL_TOAD, 0, 0, -1852, 0, 0, 0, 0x52000000, bhvToadMessage),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2b),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, -334),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
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
#include "make_const_nonconst.h"
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_JRB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_JRB, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_JRB, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 90, -2246, 1529, 0),
		OBJECT(0, -2246, 1528, 0, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_TARGET2, -1702, 1925, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, -1231, 2239, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, -1231, 2859, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, -326, 3271, 0, 0, 0, 90, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, 942, 3309, 0, 0, 0, 90, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, 941, 4509, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, 2940, 4139, 0, 0, 0, 90, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, 2135, 2235, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x0, 0x32),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -2246, 1529, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
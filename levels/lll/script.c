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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_JRB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_JRB, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_JRB, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 90, -2246, 5579, 0),
		OBJECT(0, -2246, 5578, 0, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_PLATFORM2D, -633, 2728, 0, 0, 0, 0, 0x00000000, bhvPlatform2dupdown),
		OBJECT(MODEL_PLATFORM2D, 1652, 2436, 0, 0, 0, 0, 0x00000000, bhvPlatform2dupdown),
		OBJECT(MODEL_TARGET2, -1901, 1943, 0, 0, 0, 90, 0x00000000, bhvTarget2side),
		OBJECT(MODEL_TARGET2, -1607, 4119, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, -1607, 3023, 0, 0, 0, 0, 0x00000000, bhvTarget2),
		OBJECT(MODEL_TARGET2, -1010, 2599, 0, 0, 0, 90, 0x00000000, bhvTarget2side),
		OBJECT(MODEL_TARGET2, 942, 3309, 0, 0, 0, 90, 0x00000000, bhvTarget2side),
		OBJECT(MODEL_TARGET2, 1278, 4387, 0, 0, 0, -90, 0x00000000, bhvTarget2side),
		OBJECT(MODEL_TARGET2, 1940, 6048, 0, 0, 0, 90, 0x00000000, bhvTarget2side),
		OBJECT(MODEL_TARGET2, 1946, 2802, 0, 0, 0, -90, 0x00000000, bhvTarget2side),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x0, 0x32),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -2246, 5579, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
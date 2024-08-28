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
#include "levels/pss/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pss_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 3, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(9, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_BOB, 2, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_BOB, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(1, 0, 0, 82, 0),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 5, 1918, 987, 0, 0, 0, (12 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -26, 1728, 1221, 0, 0, 0, (11 << 16), bhvFadingWarp),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 82, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

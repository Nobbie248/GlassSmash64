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
#include "levels/wmotr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
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
		MARIO_POS(3, 0, -2590, 95, 0),
		MARIO_POS(0x01, 0, -2590, 95, 0),
		OBJECT(0, 713, 100, 0, 0, 0, 0, 0xe0000, bhvAirborneWarp),
		OBJECT(118, 1650, 164, -2665, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1140, 164, -3751, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1185, 164, -3036, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 774, 164, -3036, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1494, 164, -3751, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2054, 164, -2665, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(0, 724, 100, 0, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 2046, 1079, 0, 0, 0, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 1612, 100, -3316, 0, -180, 0, 0x0, bhvBlueCoinSwitch),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0, 0x2C),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -2590, 95, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
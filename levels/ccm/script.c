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
#include "make_const_nonconst.h"
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bob, generic), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bob), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 32, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 31, WARP_NO_CHECKPOINT),
		WARP_NODE(25, LEVEL_CCM, 1, 26, WARP_NO_CHECKPOINT),
		WARP_NODE(26, LEVEL_CCM, 1, 25, WARP_NO_CHECKPOINT),
		WARP_NODE(24, LEVEL_CCM, 1, 23, WARP_NO_CHECKPOINT),
		WARP_NODE(23, LEVEL_CCM, 1, 24, WARP_NO_CHECKPOINT),
		WARP_NODE(19, LEVEL_CCM, 2, 18, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_CCM, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CCM, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_CCM, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CCM, 1, 0, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -10297, 5950, 21386),
		OBJECT(0, -10297, 5950, 21386, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 3798, 1793, 11526, 0, -19, 0, 0x00000000, bhvCS),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2E),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -10297, 5950, 21386),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
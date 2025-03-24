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
	JUMP_LINK(script_func_global_4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_C2_STAIRS, c2_ladders_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEM_STAR, gem_star_blue_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_WF, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_WF, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_LEAVES_PILE, 2534, 1867, -4260, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 2662, 1978, -5646, 9, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 3515, 2060, -5932, 10, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -2919, 1053, 724, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -2619, 1053, 973, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 419, 1755, 1360, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -130, 2477, 2305, -12, 1, -4, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -615, 2444, 1986, -5, 1, -4, 0x00000000, bhvPileLeaves),
		MARIO_POS(0x01, -180, -3260, 496, 3582),
		OBJECT(MODEL_BLUE_MUSHROOM, 2028, 0, 2131, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 5044, 0, -562, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, -1580, 0, 319, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 8736, 0, 2417, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, -3165, 0, -6565, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 1357, 0, -1161, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 999, 0, -5438, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(0, -3258, 496, 3582, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x00000000, bhvCS),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2D),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -3260, 496, 3582),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
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
	LOAD_MODEL_FROM_GEO(MODEL_KOOPY, koopy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_YOSHY, yoshy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TOADY, toady_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BNET, bnet_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CRUMBLES2, crumbles2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_POTTY, potty_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSHY, mushy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSHY_PARTICLE, mushy_particle_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BUBBLY, bubbly_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BUBBLY_POP, bubblypop_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_WF, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_WF, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BNET, -3792, 1609, 21, -8, 116, 16, 0x00000000, bhvBnet),
		OBJECT(MODEL_BNET, 5184, 2693, -5403, -14, 115, -2, 0x00000000, bhvBnet),
		OBJECT(MODEL_BNET, 7412, 1620, 1993, 15, 94, 7, 0x00000000, bhvBnet),
		OBJECT(MODEL_LEAVES_PILE, 2534, 1867, -4260, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 3191, 2051, -5962, 7, -5, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 10350, 2270, 2922, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, -2928, 1053, 854, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 419, 1755, 1360, 0, 0, 0, 0x00000000, bhvPileLeaves),
		OBJECT(MODEL_LEAVES_PILE, 3201, 1778, 4017, 0, 0, 0, 0x00000000, bhvPileLeaves),
		MARIO_POS(0x01, -180, -3260, 496, 3582),
		OBJECT(MODEL_BLUE_MUSHROOM, 2028, 0, 2131, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 7733, 0, 4754, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 5044, 0, -562, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, -1580, 0, 319, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 8736, 0, 2417, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, -3223, 0, -6178, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_BLUE_MUSHROOM, 1357, 0, -1161, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(MODEL_RED_MUSHROOM, 999, 0, -5438, 0, 0, 0, 0x00000000, bhvBounce),
		OBJECT(0, -3258, 496, 3582, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 6918, 2529, -3287, 0, -74, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 6435, 2529, -2486, 0, 35, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 11084, 2799, 1287, 0, 159, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 10395, 2799, 2028, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 3905, 1778, 3009, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 3557, 1778, 4445, 0, 143, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, -101, 1325, -3709, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 323, 2304, -7327, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, -1545, 2304, -5978, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 2966, 2003, -1625, 0, 16, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 3638, 2003, 1461, 0, 25, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 3433, 2003, -186, 0, 25, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 2768, 1983, -5600, 0, 25, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 2943, 1861, -4491, 0, 25, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, -3076, 1170, -3709, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, -3076, 1310, -4451, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_NONE, 10395, 2799, 1287, 0, 115, 0, 0x00000000, bhvJStatues),
		OBJECT(MODEL_BUBBLY, 1469, 2060, -4769, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_BUBBLY, 1216, 2664, -7526, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_BUBBLY, 8137, 3173, -1197, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_BUBBLY, -1784, 1750, -3586, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_BUBBLY, 2637, 2424, -3035, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_BUBBLY, 4671, 2097, 2766, 0, 0, 0, 0x00000000, bhvBubbly),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x00000000, bhvCS),
		OBJECT(MODEL_MUSHY, -2651, 1049, 699, 0, 0, 0, 0x00000000, bhvMushy),
		OBJECT(MODEL_MUSHY, -337, 2521, 2529, 0, 0, 0, 0x00000000, bhvMushy),
		OBJECT(MODEL_MUSHY, 2565, 1999, -5915, 0, 0, 0, 0x00000000, bhvMushy),
		OBJECT(MODEL_MUSHY, 3624, 1771, 3986, 0, 0, 0, 0x00000000, bhvMushy),
		OBJECT(MODEL_RED_COIN_ARROW, 4537, 3337, 5870, 0, 0, 0, 0x00000000, bhvRedCoinRadar),
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
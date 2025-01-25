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
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_18), 

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
		OBJECT(MODEL_GLASS, 3205, 396, 327, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3205, 396, 1911, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 4320, 396, 1911, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 4320, 396, 327, 0, 0, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3753, 396, -119, 0, -90, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, 3753, 396, 2355, 0, -90, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, -956, 396, 3221, 0, -90, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, -969, 396, 2102, 0, -90, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_GLASS, -1524, 396, 2673, 0, -180, 0, 0x00000000, bhvGlass),
		OBJECT(MODEL_LANTERN, -2472, 602, -2447, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 2297, 494, 4955, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 3291, 1497, 97, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 4234, 1497, 97, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 4234, 1497, 2141, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 3290, 1497, 2141, 0, -90, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 2052, 819, -1902, 0, -120, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 2496, 1004, -2658, 0, -120, 0, 0x00000000, bhvLantern),
		OBJECT(MODEL_LANTERN, 2962, 1315, -3451, 0, -120, 0, 0x00000000, bhvLantern),
		MARIO_POS(1, 0, -4476, 203, 1324),
		OBJECT(0, -4416, 100, 1355, 0, 90, 0, 0xe0000, bhvAirborneWarp),
		OBJECT(0, -4416, 100, 1344, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 1062, 34, 6266, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		OBJECT(0, -4355, 34, -2578, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		OBJECT(MODEL_STATUE, 3045, 234, 715, 0, -180, 0, 0x00000000, bhvStatue),
		OBJECT(MODEL_STATUE, 3045, 234, 1532, 0, -180, 0, 0x00000000, bhvStatue),
		OBJECT(MODEL_STATUE, -968, 1323, 2662, 0, 0, 0, 0x00000000, bhvStatue),
		OBJECT(MODEL_VASE, -3738, 169, -5053, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, -3410, 1073, 1137, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, 4122, 169, 795, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, 4122, 169, 1121, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, 4122, 169, 1450, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, -970, 169, 2435, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, -970, 169, 2885, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, 5195, 556, -1536, 0, -90, 0, 0x00000000, bhvVase),
		OBJECT(MODEL_VASE, -624, 967, -920, 0, -90, 0, 0x00000000, bhvVase),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, -4476, 203, 1324),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

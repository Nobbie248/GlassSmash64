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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_15), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		MARIO_POS(0x01, 0, -107, 34, -753),
		OBJECT(MODEL_NONE, -1123, 958, -546, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -2475, 1052, -1786, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -1411, 1052, -2273, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 427, -5, -2508, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1448, 1052, -2267, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1213, 958, -1075, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 2154, 1052, -958, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1496, 487, -135, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 2977, 1052, 240, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -2790, 933, 448, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -1021, 1542, -3356, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1957, 3, 1767, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1472, 475, 2225, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -1782, 470, 1454, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -987, -69, 2561, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -731, -69, 3131, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -220, -69, 3279, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1275, 12, 3712, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1521, 12, 3436, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1413, 12, 4007, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 1698, 1542, 4686, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 2348, 1052, 3604, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 3125, 1052, 3082, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 3218, 3, 859, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 685, -12, -4522, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -653, -12, -4522, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 6, -12, -3656, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -662, -12, -5545, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 695, -12, -5545, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 184, -2, 665, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, 6, 84, 156, 0, 0, 0, 0x00000000, bhvAztecPots),
		OBJECT(MODEL_NONE, -739, 1793, 5656, 0, -19, 0, 0x00000000, bhvCS),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -107, 34, -753),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
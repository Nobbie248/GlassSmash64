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
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_BBH, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BBH, 5, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BBH, 4, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BBH, 3, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BBH, 2, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BBH, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, 1215, 328, 438, 0, -180, 0, 0x70000, bhvDeathWarp),
		OBJECT(124, 1208, 0, -1447, 0, 0, 0, 0x950000, bhvMessagePanel),
		OBJECT(0, 1204, 328, 448, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 1200, 462, 1093, 0, 0, 0, 0x60000, bhvWarp),
		OBJECT(22, 301, 39, -1894, 0, 0, 0, 0x20000, bhvWarpPipe),
		OBJECT(22, 900, 39, -1894, 0, 0, 0, 0x30000, bhvWarpPipe),
		OBJECT(22, 1499, 48, -1894, 0, 0, 0, 0x40000, bhvWarpPipe),
		OBJECT(22, 2098, 48, -1894, 0, 0, 0, 0x50000, bhvWarpPipe),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x31),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bbh_area_2),
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BBH, 6, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BBH, 1, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 2, 0, WARP_NO_CHECKPOINT),
		OBJECT(124, -1524, 92, -2390, 0, 26, 0, 0x8a0000, bhvMessagePanel),
		OBJECT(0, -2349, 1170, -2765, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, -1955, 92, -2314, 0, 0, 0, 0x20000, bhvWarpPipe),
		OBJECT(22, 721, 1810, 2705, 0, 0, 0, 0x30000, bhvWarpPipe),
		TERRAIN(bbh_area_2_collision),
		MACRO_OBJECTS(bbh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 35),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bbh_area_3),
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BBH, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 3, 0, WARP_NO_CHECKPOINT),
		OBJECT(124, 6346, 89, -4157, 0, -32, 0, 0x8b0000, bhvMessagePanel),
		OBJECT(0, 6085, 89, -4297, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, 5912, 89, -4164, 0, 0, 0, 0x30000, bhvWarpPipe),
		TERRAIN(bbh_area_3_collision),
		MACRO_OBJECTS(bbh_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 37),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bbh_area_4),
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BBH, 1, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 4, 0, WARP_NO_CHECKPOINT),
		OBJECT(124, -9534, 95, -193, 0, -12, 0, 0x8c0000, bhvMessagePanel),
		OBJECT(0, -9708, 95, 785, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, -9172, 95, -37, 0, 0, 0, 0x40000, bhvWarpPipe),
		TERRAIN(bbh_area_4_collision),
		MACRO_OBJECTS(bbh_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 40),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, bbh_area_5),
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BBH, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 5, 0, WARP_NO_CHECKPOINT),
		OBJECT(124, -645, -254, 828, 0, -32, 0, 0x940000, bhvMessagePanel),
		OBJECT(0, -1583, 0, 1790, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, -411, -254, 1141, 0, 0, 0, 0x50000, bhvWarpPipe),
		TERRAIN(bbh_area_5_collision),
		MACRO_OBJECTS(bbh_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 41),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, bbh_area_6),
		WARP_NODE(241, LEVEL_BBH, 1, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BBH, 2, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 6, 0, WARP_NO_CHECKPOINT),
		OBJECT(124, -711, 1855, 3485, 0, 0, 0, 0x9d0000, bhvMessagePanel),
		OBJECT(0, -3486, 0, 3882, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, -95, 1802, 4289, 0, 0, 0, 0x30000, bhvWarpPipe),
		TERRAIN(bbh_area_6_collision),
		MACRO_OBJECTS(bbh_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 35),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

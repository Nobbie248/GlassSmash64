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
#include "levels/sa/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sa_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_VANILLA_OBJECTS(0, bob, generic), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_vo_bob), 
	LOAD_MODEL_FROM_GEO(MODEL_BREAKWINDOW, breakwindow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SA_LADDER, sa_ladder_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GEMMIES, gemmies_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 22, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_SA, 2, 33, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HEART, -1887, 3157, -7050, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_HEART, -4793, 4285, -4984, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_SA_LADDER, 0, 0, 0, 0, 0, 0, 0x0, bhvSALadder),
		MARIO_POS(0x01, 0, 4216, 177, -6481),
		OBJECT(212, 2341, 2742, 1699, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, -965, 5112, -6339, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(0, 712, 2770, 12267, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 541, 2770, 12854, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 792, 2822, 13378, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 253, 2854, 13726, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, 876, 2873, 14677, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, -4661, 4788, -4786, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, -4991, 5028, -4962, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(0, -4663, 5274, -5162, 0, -180, 0, 0x0, bhvBetaFishSplashSpawner),
		OBJECT(188, 3767, 88, -5282, 0, -180, 0, 0x0, bhvBobomb),
		OBJECT(129, 3400, 0, -3053, 0, -180, 0, 0x0, bhvBreakableBox),
		OBJECT(0, 4858, 78, -4679, 0, -180, 0, 0x20000, bhvCoinFormation),
		OBJECT(137, 560, 3296, 16033, 0, -180, 0, 0x30000, bhvExclamationBox),
		OBJECT(137, -5655, 3125, 6440, 0, -180, 0, 0x0, bhvExclamationBox),
		OBJECT(180, 603, 2839, 7838, 0, -180, 0, 0x0, bhvFireSpitter),
		OBJECT(144, -5101, 4911, -7577, 0, -180, 0, 0x0, bhvFlame),
		OBJECT(144, -5118, 4911, -8046, 0, -180, 0, 0x0, bhvFlame),
		OBJECT(144, -1740, 3707, -8047, 0, -180, 0, 0x0, bhvFlame),
		OBJECT(144, -1727, 3707, -7573, 0, -180, 0, 0x0, bhvFlame),
		OBJECT(0, 1135, 3178, 9216, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 44, 3112, 11122, 0, 90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -1387, 2758, 6846, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -4220, 2758, 5920, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(207, 3564, 88, -4270, 0, -180, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(207, 5025, 0, -3060, 0, -180, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(207, 5160, -72, -5560, 0, -180, 0, 0x0, bhvFloorSwitchAnimatesObject),
		OBJECT(MODEL_GOOMBA, 4854, 78, -4701, 0, -180, 0, 0x0, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 4854, 143, -4886, 0, -180, 0, 0x0, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3499, 78, -4383, 0, -180, 0, 0x0, bhvGoomba),
		OBJECT(0, 4498, 1094, 2352, 0, -180, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 3003, 1094, 2668, 0, -180, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 566, 2983, 16037, 0, -180, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1520, 3109, -5574, 0, -180, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1600, 3109, -6994, 0, -180, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -3818, 3024, -6930, 0, -180, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, -5418, 3024, -6012, 0, -180, 0, 0x0, bhvLargeFishGroup),
		OBJECT(0, 4230, -222, -3220, 0, -180, 0, 0x0, bhvOpenableGrill),
		OBJECT(120, 3397, 60, -3048, 0, -180, 0, 0x0, bhvRecoveryHeart),
		OBJECT(101, 701, 2839, 7616, 0, -180, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 585, 2983, 11157, 0, -180, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 599, 2839, 8063, 0, -180, 0, 0x0, bhvScuttlebug),
		OBJECT(0, 4216, 65, -6481, 0, 0, 180, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(100, 546, 3475, 10189, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 741, 3455, 13936, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 513, 3503, 15051, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 782, 2993, 4984, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 614, 2741, 3549, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 413, 2741, 1610, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(100, 617, 2807, -1431, 0, -180, 0, 0x0, bhvSwoop),
		OBJECT(0, 4254, 912, -3304, 0, -180, 0, 0x0, bhvWaterfallSoundLoop),
		OBJECT(MODEL_BREAKWINDOW, 5023, 264, -3274, 0, 0, 0, 0x00000000, bhvbreakwindow),
		OBJECT(MODEL_BREAKWINDOW, 3406, 264, -3274, 0, 0, 0, 0x00000000, bhvbreakwindow),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x32),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, sa_area_2),
		WARP_NODE(0xf1, LEVEL_SA, 2, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 3, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(33, LEVEL_SA, 2, 33, WARP_NO_CHECKPOINT),
		WARP_NODE(9, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_BOB, 2, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_BOB, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GEMMIES, 0, 2457, 1221, 0, 0, 0, 0x00000000, bhvGemmies),
		OBJECT(MODEL_HEART, -312, 1699, 5065, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		OBJECT(MODEL_HEART, 2, 87, 774, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		MARIO_POS(1, 0, 0, 82, 0),
		OBJECT(MODEL_STAR, 0, 1979, 1221, 0, 0, 0, 0x000A0000, bhvStar),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (33 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 23, 121, -177, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		TERRAIN(sa_area_2_collision),
		MACRO_OBJECTS(sa_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x32),
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

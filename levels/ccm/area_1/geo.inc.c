#include "src/game/envfx_snow.h"

const GeoLayout ccm_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_a_Non_Solid_Shit_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_FORCE, ccm_dl_a_Non_Solid_Shit_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_a_Non_Solid_Shit_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_FORCE, ccm_dl_a_Non_Solid_Shit_001_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_a_water_sheet_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_b_water_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_k_Actual_level_geo_solid__mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_k_Actual_level_geo_solid__mesh_layer_4),
		GEO_CULL(-32000, 32000, -32000, 32000, -32000, 5000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_k_Actual_level_geo_solid__001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_koopa_girls_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Leaves_non_solid__mesh_layer_5),
		GEO_CULL(-32000, 32000, -32000, 32000, -32000, 5000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Leaves_non_solid__001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -3687, 585, 5125, ccm_dl_light_beam_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -1016, 796, 3896, ccm_dl_light_beam_001_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -3014, 735, 3235, ccm_dl_light_beam_002_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 2018, 730, 5205, ccm_dl_light_beam_003_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 4218, 722, 2446, ccm_dl_light_beam_004_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 3253, 410, 278, ccm_dl_light_beam_005_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 3628, 651, -827, ccm_dl_light_beam_006_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -1821, 585, -1402, ccm_dl_light_beam_007_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -151, 858, 321, ccm_dl_light_beam_008_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_peir_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_z_flames_mesh_layer_5),
		GEO_CULL(-32000, 32000, -32000, 32000, -32000, 5000, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_z_flames_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccm_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 50000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ccm_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout bowser_3_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, bowser_3_dl_Bowser_Fight_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_ALPHA, 90, 0, 0, bowser_3_dl_Bowser_Fight_001_mesh_layer_4),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, bowser_3_dl_Bowser_Fight_002_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, 90, 0, 0, bowser_3_dl_Bowser_Fight_003_mesh_layer_5),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, 90, 0, 0, bowser_3_dl_Bowser_Fight_004_mesh_layer_5),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, 90, 0, 0, bowser_3_dl_Bowser_Fight_005_mesh_layer_5),
		GEO_ROTATION_NODE_WITH_DL(LAYER_FORCE, 90, 0, 0, bowser_3_dl_skybox1_mesh_layer_0),
		GEO_DISPLAY_LIST(LAYER_FORCE, bowser_3_dl_skybox2_mesh_layer_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bowser_3_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -80, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bowser_3_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_SNOW_NORMAL, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

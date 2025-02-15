#include "src/game/envfx_snow.h"

const GeoLayout schoom_red_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, schoom_red_Schroom_Red_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, schoom_red_Schroom_Red_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

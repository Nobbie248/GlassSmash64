#include "src/game/envfx_snow.h"

const GeoLayout c2_ladders_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, c2_ladders_Plane_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

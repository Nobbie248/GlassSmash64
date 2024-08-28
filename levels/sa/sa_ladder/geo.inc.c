#include "src/game/envfx_snow.h"

const GeoLayout sa_ladder_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sa_ladder_zone2_002_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

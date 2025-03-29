#include "src/game/envfx_snow.h"

const GeoLayout bnet_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bnet_Circle_001_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

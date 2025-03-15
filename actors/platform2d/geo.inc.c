#include "src/game/envfx_snow.h"

const GeoLayout platform2d_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, platform2d_platform2d_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, platform2d_platform2d_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

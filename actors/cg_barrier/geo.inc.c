#include "src/game/envfx_snow.h"

const GeoLayout cg_barrier_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cg_barrier_barrier_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

#include "src/game/envfx_snow.h"

const GeoLayout leaff_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, leaff_leaf_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

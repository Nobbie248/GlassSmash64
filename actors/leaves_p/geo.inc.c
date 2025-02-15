#include "src/game/envfx_snow.h"

const GeoLayout leaves_p_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, leaves_p_leaves_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

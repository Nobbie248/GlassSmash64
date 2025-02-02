#include "src/game/envfx_snow.h"

const GeoLayout target_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, target_retro_target_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

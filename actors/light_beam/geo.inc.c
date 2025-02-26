#include "src/game/envfx_snow.h"

const GeoLayout light_beam_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, light_beam_light_beam_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

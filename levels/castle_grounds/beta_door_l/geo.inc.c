#include "src/game/envfx_snow.h"

const GeoLayout beta_door_l_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, beta_door_l_HubWorld_012_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

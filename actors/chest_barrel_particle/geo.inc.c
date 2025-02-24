#include "src/game/envfx_snow.h"

const GeoLayout chest_barrel_particle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chest_barrel_particle_chest_barrel_particle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

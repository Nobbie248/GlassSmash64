#include "src/game/envfx_snow.h"

const GeoLayout mushy_particle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, mushy_particle_mushy_particle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

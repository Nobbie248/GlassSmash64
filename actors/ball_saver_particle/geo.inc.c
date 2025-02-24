#include "src/game/envfx_snow.h"

const GeoLayout ball_saver_particle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ball_saver_particle_ball_saver_particle_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

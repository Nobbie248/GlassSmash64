#include "src/game/envfx_snow.h"

extern const GeoLayout omm_geo_star_effects[];
const GeoLayout b3_crown_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, b3_crown_Crown_Model_mesh_layer_1),
		GEO_BILLBOARD(),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, omm_geo_star_effects),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

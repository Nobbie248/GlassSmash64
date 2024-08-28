#include "src/game/envfx_snow.h"

const GeoLayout gem_red_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gem_red_HubWorld_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

extern const GeoLayout omm_geo_star_effects[];
const GeoLayout gem_star_red_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
    GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 0x24000),
      GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gem_red_HubWorld_001_mesh_layer_1),
      GEO_CLOSE_NODE(),
      GEO_BILLBOARD(),
      GEO_OPEN_NODE(),
         GEO_BRANCH(1, omm_geo_star_effects),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

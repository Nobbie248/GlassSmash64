#include "src/game/envfx_snow.h"

extern Gfx *geo_update_layer_transparency_envcolor2(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout c3_spin_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_update_layer_transparency_envcolor2),
		GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, c3_spin_Plane_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

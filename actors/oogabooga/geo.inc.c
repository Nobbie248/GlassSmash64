#include "src/game/envfx_snow.h"

const GeoLayout oogabooga_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, oogabooga_oogabooga_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, oogabooga_oogabooga_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, oogabooga_oogabooga_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

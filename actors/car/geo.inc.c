#include "src/game/envfx_snow.h"

const GeoLayout car_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, car_car_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};

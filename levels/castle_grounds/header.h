#ifndef CASTLE_GROUNDS_HEADER_H
#define CASTLE_GROUNDS_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// script
extern const LevelScript level_castle_grounds_entry[];

extern const struct MovtexQuadCollection castle_grounds_movtex_water[];
extern Movtex castle_grounds_movtex_tris_waterfall[];

#include "levels/castle_grounds/header.inc.h"

#include "levels/castle_grounds/beta_door_l/collision_header.h"

#include "levels/castle_grounds/beta_door_l/geo_header.h"

#include "levels/castle_grounds/beta_door_r/geo_header.h"

#include "levels/castle_grounds/beta_door_r/collision_header.h"

#include "levels/castle_grounds/jabo/geo_header.h"

#endif

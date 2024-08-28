#ifndef CCM_HEADER_H
#define CCM_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

extern const Trajectory ccm_seg7_trajectory_snowman[];
extern const Trajectory ccm_seg7_trajectory_ropeway_lift[];
extern const struct MovtexQuadCollection ccm_movtex_penguin_puddle_water[];
extern const Trajectory ccm_seg7_trajectory_penguin_race[];

// script
extern const LevelScript level_ccm_entry[];

#include "levels/ccm/header.inc.h"

#include "levels/ccm/c4_ripple/collision_header.h"

#include "levels/ccm/c4_ripple/geo_header.h"

#include "levels/ccm/c4_platform/geo_header.h"

#include "levels/ccm/c4_platform/collision_header.h"

#endif

#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif


#include "liane/model.inc.c"
#include "liane/collision.inc.c"
#include "pipe/model.inc.c"
#include "pipe/collision.inc.c"

#include "d_hammer_mario/model.inc.c"
#include "hammer_mario/model.inc.c"
#include "mario/anims/data.inc.c"
#include "mario/anims/table.inc.c"
#include "target/collision.inc.c"
#include "target/model.inc.c"
#include "cg_barrier/model.inc.c"
#include "bounce/model.inc.c"
#include "bounce/collision.inc.c"
#include "schoom_blue/model.inc.c"
#include "schoom_red/model.inc.c"
#include "schoom_red/collision.inc.c"
#include "pleaves/model.inc.c"
#include "leaves_p/model.inc.c"
#include "palmleaf/model.inc.c"
#include "palmleaf/collision.inc.c"
#include "PotPlant/model.inc.c"
#include "PotOrnate/model.inc.c"
#include "PotFlowerOrnate/model.inc.c"
#include "PotFloral/collision.inc.c"
#include "PotFloral/model.inc.c"
#include "flamedl/model.inc.c"
#include "mask/model.inc.c"
#include "mask_hitbox/collision.inc.c"
#include "light_beam/model.inc.c"
#include "outrunisles/model.inc.c"
#include "aztecruins/model.inc.c"
#include "chinesevillage/model.inc.c"
#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "textures.h"

#include "make_const_nonconst.h"
#include "levels/jrb/areas/1/trajectory.inc.c"
#include "levels/jrb/areas/1/movtext.inc.c"
#include "levels/jrb/areas/2/movtext.inc.c"

// 0x070116A0
const Trajectory bob_seg7_trajectory_koopa[] = {
    TRAJECTORY_POS(0 /*pos*/, 913 - 494 - 7229, -94, -7771 + 7402-452),
    TRAJECTORY_POS(1 /*pos*/, -283 - 494 - 7229, -138, -7780 + 7402-452),
    TRAJECTORY_POS(2 /*pos*/, -135 - 494 - 7229, 317, -9670 + 7402-452),
    TRAJECTORY_POS(3 /*pos*/, 2781 - 494 - 7229, 679, -9921 + 7402-452),
    TRAJECTORY_POS(4 /*pos*/, 6502 - 494 - 7229, -161, -6762 + 7402-452),
    TRAJECTORY_POS(5 /*pos*/, 14018 - 494 - 7229, 2316, -7553 + 7402-452),
    TRAJECTORY_POS(6 /*pos*/, 14408 - 494 - 7229, 3722, -7540 + 7402-452),
    TRAJECTORY_POS(7 /*pos*/, 15717 - 494 - 7229, 3781, -6941 + 7402-452),
    TRAJECTORY_POS(8 /*pos*/, 16132 - 494 - 7229, 3781, -2799 + 7402-452),
    TRAJECTORY_POS(9 /*pos*/, 14003 - 494 - 7229, 3285, 522 + 7402-452),
    TRAJECTORY_POS(10 /*pos*/, 11917 - 494 - 7229, 2825, 2155 + 7402-452),
    TRAJECTORY_POS(11 /*pos*/, 9905 - 494 - 7229, 3067, 2624 + 7402-452),
    TRAJECTORY_POS(12 /*pos*/, 8057 - 494 - 7229, 2951, 2702 + 7402-452),
    TRAJECTORY_POS(13 /*pos*/, 6526 - 494 - 7229, 2945, 2682 + 7402-452),
    TRAJECTORY_POS(14 /*pos*/, 4404 - 494 - 7229, 3066, 2644 + 7402-452),
    TRAJECTORY_POS(15 /*pos*/, 2362 - 494 - 7229, 2854, 2085 + 7402-452),
    TRAJECTORY_POS(16 /*pos*/, 508 - 494 - 7229, 3274, 559 + 7402-452),
    TRAJECTORY_POS(17 /*pos*/, -991 - 494 - 7229, 3852, -1576 + 7402-452),

    TRAJECTORY_END(),
};

#include "levels/jrb/leveldata.inc.c"

#include "levels/jrb/c3_spin/collision.inc.c"
#include "levels/jrb/c3_spin/model.inc.c"
#include "levels/jrb/c3_spin_burn/collision.inc.c"
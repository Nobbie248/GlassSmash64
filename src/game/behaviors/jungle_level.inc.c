// all behaviors for jungle level

#include "game/interaction.h"
#include "game/mario.h"
#include "game/object_helpers.h"
#include "audio/external.h"
#include "engine/surface_collision.h"
#include "game/level_update.h"
#include "behavior_data.h"

void bhv_bounce_object_init(void) {
    o->oTimer = 0;
    o->oHomeY = o->header.gfx.scale[1];
}

void bhv_bounce_object_loop(void) {
    if (gMarioObject->platform == o && gMarioState->action != ACT_TRIPLE_JUMP) {
        o->header.gfx.scale[1] = o->oHomeY * 0.5f;
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = 1.2f * o->oHomeY;
        
        set_mario_action(gMarioState, ACT_TRIPLE_JUMP, 0);
        gMarioState->marioObj->header.gfx.animInfo.animFrame = 0;

        play_sound(SOUND_GENERAL_CRAZY_BOX_BOING_SLOW, gMarioObject->header.gfx.cameraToObject);
        spawn_object(gMarioState->marioObj, MODEL_SMOKE, bhvWhitePuffSmoke2);

        gMarioState->vel[1] = 120.0f;

        o->oTimer = 0;
    }
    
    if (o->oTimer > 5) {
        o->header.gfx.scale[1] = approach_f32(o->header.gfx.scale[1], o->oHomeY, 0.1f, 0.1f);
        o->header.gfx.scale[0] = o->header.gfx.scale[2] = approach_f32(o->header.gfx.scale[0], o->oHomeY, 0.1f, 0.1f);
    }
    
    o->oTimer++;
}

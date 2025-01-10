#include "src/game/save_file.h"
#include "src/game/level_update.h"
#include "src/game/mario.h"
#include "src/audio/external.h"
#define o (gCurrentObject)
void bhv_delete_save_file_a_and_warp_loop(void) {
    
    if (o->oAction == 0 && o->oDistanceToMario < 200.0f && gPlayer1Controller->buttonPressed & A_BUTTON) {
        play_sound(SOUND_MENU_MESSAGE_APPEAR, gGlobalSoundSource);
        o->oAction = 1;
    } else if (o->oAction == 1) {
        print_text(100, 150, "ARE YOU SURE?\nA: YES  B: NO");
        if (gPlayer1Controller->buttonPressed & A_BUTTON) {
            play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
            save_file_erase(0);
            initiate_warp(LEVEL_CASTLE_GROUNDS, 1, 0x0A);
        }
        if (gPlayer1Controller->buttonPressed & B_BUTTON || gPlayer1Controller->buttonPressed & A_BUTTON) o->oAction = 0;
    }
};
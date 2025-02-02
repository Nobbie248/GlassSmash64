

#include "game/game_init.h"
#include "game/level_update.h"
#include "src/engine/level_script.h"
#include "level_commands.h"
#include "src/game/level_update.h"
#include "src/game/ingame_menu.h"

// #include "print.h"


static int lTrigCooldown;


char gIsCs = 0;

static void resetFlags()
{
    gBorderHeight = 0;
    gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
    gIsCs = 0;
}

static void disableHud()
{
    gHudDisplay.flags &= ~(HUD_DISPLAY_FLAG_LIVES | HUD_DISPLAY_FLAG_COIN_COUNT | HUD_DISPLAY_FLAG_STAR_COUNT | HUD_DISPLAY_FLAG_CAMERA_AND_POWER);
    gIsCs = 1;
}

static char sCsShown[4] = {};
extern struct CreditsEntry *gCurrCreditsEntry;


void bhv_cs_init()
{
        gMarioState->numCoins = 0;
        
        
    if (gCurrCreditsEntry)

    {
        disableHud();
        o->activeFlags = 0;
        return;
    }

    if (gCurrCourseNum == COURSE_NONE)
    {
        resetFlags();
        o->activeFlags = 0;
        return;        
    }
    // this code allows cs to happen only once per savefile
    // int idx = gCurrCourseNum - 1;
    // int flags = save_file_get_star_flags(gCurrSaveFileNum - 1, idx);
    // if (flags)
    // {
    //     resetFlags();
    //     o->activeFlags = 0;
    //     return;
    // }

    // if (sCsShown[idx])
    // {
    //     resetFlags();
    //     o->activeFlags = 0;
    //     return;
    // }
    // else
    // {
    //     sCsShown[idx] = 1;
    // }

    disableHud();
}

static int delayTimer = 0;
void bhv_cs_loop()
{

    s32 mode = MENU_OPT_NONE;

    create_dl_ortho_matrix();

    if (!o->activeFlags)
        return;
    if (gCurrCourseNum == COURSE_WMOTR)
    {
    int buttonPressed = gMarioStates->controller->buttonPressed;
    gMarioStates->input = 0;
    gMarioStates->controller->rawStickX = 0;
    gMarioStates->controller->rawStickY = 0;
    gMarioStates->controller->stickX = 0;
    gMarioStates->controller->stickY = 0;
    gMarioStates->controller->stickMag = 0;
    gMarioStates->controller->buttonDown = 0;
    gMarioStates->controller->buttonPressed = 0;

    if (delayTimer == 0)
{
    delayTimer = 5; // Delay for 5 frames (adjust as needed)
}

// Count down the delay timer
if (delayTimer > 0)
{
    delayTimer--;

    // Execute the switch statement only after the delay
    if (delayTimer == 0)
    {
        switch (gCurrCourseNum)
        {
            case COURSE_WMOTR:
                gCamera->cutscene = CUTSCENE_INTRO;
                break;
            
            // Add more cases if needed
        }
    }
}
    if (buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON))
    {
        initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAG_EXIT_COURSE);
            fade_into_special_warp(WARP_SPECIAL_NONE, 0);
            gSavedCourseNum = COURSE_NONE;
    }

    }
    else{
    if (gCurrCourseNum == COURSE_NONE)
    {
        resetFlags();
        o->activeFlags = 0;
        return;        
    }
    
    int buttonPressed = gMarioStates->controller->buttonPressed;
    gMarioStates->input = 0;
    gMarioStates->controller->rawStickX = 0;
    gMarioStates->controller->rawStickY = 0;
    gMarioStates->controller->stickX = 0;
    gMarioStates->controller->stickY = 0;
    gMarioStates->controller->stickMag = 0;
    gMarioStates->controller->buttonDown = 0;
    gMarioStates->controller->buttonPressed = 0;

    switch (gCurrCourseNum)
    {
        case COURSE_BOB:
            gCamera->cutscene = CUTSCENE_C1;
                print_text(30, 40, "China");
            break;
        case COURSE_WF:
            gCamera->cutscene = CUTSCENE_C2;
            break;
        case COURSE_JRB:
            gCamera->cutscene = CUTSCENE_C3;
            break;
        case COURSE_CCM:
            gCamera->cutscene = CUTSCENE_C4;
            break;
    }

    if (gBorderHeight < 33)
        gBorderHeight++;

    if (buttonPressed & (A_BUTTON | B_BUTTON))
{
    if (delayTimer == 0)
    {
        // Start the delay timer
        delayTimer = 5; // Delay for 5 frames (adjust as needed)
    }
}

// Count down the delay timer
if (delayTimer > 0)
{
    delayTimer--;

    // Execute the original code when the timer reaches zero
    if (delayTimer == 0)
    {
        resetFlags();
        reset_camera(gCamera);
        o->activeFlags = 0;
        level_control_timer(TIMER_CONTROL_SHOW);
        level_control_timer(TIMER_CONTROL_START);
        play_sound(SOUND_OBJ2_PIRANHA_PLANT_DYING, gGlobalSoundSource); 
        gTotalBrokenObjects = 0;
        gHudDisplay.coins = 0;
    }
}

    if (o->oTimer > 290 || (o->oSubAction > 2))
    {
        
        resetFlags();
        reset_camera(gCamera);
        o->activeFlags = 0;
        level_control_timer(TIMER_CONTROL_SHOW);
        level_control_timer(TIMER_CONTROL_START);
        play_sound(SOUND_OBJ2_PIRANHA_PLANT_DYING, gGlobalSoundSource);
        gTotalBrokenObjects = 0;
        gHudDisplay.coins = 0;
    }
    }
}

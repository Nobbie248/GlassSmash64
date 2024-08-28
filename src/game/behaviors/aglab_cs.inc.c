#include "game/game_init.h"
#include "game/level_update.h"

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
    
    int idx = gCurrCourseNum - 1;
    int flags = save_file_get_star_flags(gCurrSaveFileNum - 1, idx);
    if (flags)
    {
        resetFlags();
        o->activeFlags = 0;
        return;
    }

    if (sCsShown[idx])
    {
        resetFlags();
        o->activeFlags = 0;
        return;
    }
    else
    {
        sCsShown[idx] = 1;
    }

    disableHud();
}

void bhv_cs_loop()
{
    if (!o->activeFlags)
        return;

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
        o->oSubAction++;
    }

    if (o->oTimer > 290 || (o->oSubAction > 2))
    {
        resetFlags();
        reset_camera(gCamera);
        o->activeFlags = 0;
    }
}

#include "game/game_init.h"
#include "game/level_update.h"
#include "src/engine/level_script.h"
#include "level_commands.h"
#include "src/game/level_update.h"
#include "src/game/ingame_menu.h"
#include "src/game/mario.h"
#include "src/game/hud.h"
#include "actors/group0.h"

static int delayTimer = 0;
char gIsCs = 0;
int gIstitle;
static void resetFlags(void) {
    gBorderHeight = 0;
    gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
    gIsCs = 0;
}

static void disableHud(void) {
    gHudDisplay.flags &= ~(HUD_DISPLAY_FLAG_LIVES | HUD_DISPLAY_FLAG_COIN_COUNT | HUD_DISPLAY_FLAG_STAR_COUNT | HUD_DISPLAY_FLAG_CAMERA_AND_POWER);
    gIsCs = 1;
}

static void resetMarioState(void) {
    struct Controller *c = gMarioStates->controller;
    gMarioStates->input = 0;
    c->rawStickX = c->rawStickY = c->stickX = c->stickY = c->stickMag = c->buttonDown = c->buttonPressed = 0;
}

static void handleCutscene(void) {
    if (!delayTimer) delayTimer = 5;
    if (delayTimer && --delayTimer == 0) gCamera->cutscene = CUTSCENE_INTRO;
}

static void warpIfButtonPressed(int buttonPressed) {
    if (buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAG_EXIT_COURSE);
        fade_into_special_warp(WARP_SPECIAL_NONE, 0);
    }
}

extern struct CreditsEntry *gCurrCreditsEntry;

void bhv_cs_init(void) {
    gHudDisplay.coins = 0;
    gTotalBrokenObjects = 0;
    delayTimer = 0;
    gMarioState->numCoins = 0;
    countdownStage = 0;
    frameCount = 0; 
    if (gCurrCreditsEntry) { disableHud(); o->activeFlags = 0; return; }
    if (gCurrCourseNum == COURSE_NONE) { resetFlags(); o->activeFlags = 0; return; }
    disableHud();
}

void bhv_cs_loop(void) {
    create_dl_ortho_matrix();
    if (!o->activeFlags) return;
    int buttonPressed = gMarioStates->controller->buttonPressed;
    resetMarioState();
    if (gCurrCourseNum == COURSE_WMOTR) { handleCutscene(); warpIfButtonPressed(buttonPressed); return; }
    if (gCurrCourseNum == COURSE_NONE) { resetFlags(); o->activeFlags = 0; return; }

    switch (gCurrCourseNum) {
        case COURSE_BOB: gCamera->cutscene = CUTSCENE_C1; gIstitle = 1; break;
        case COURSE_WF: gCamera->cutscene = CUTSCENE_C2; gIstitle = 2; break;
        case COURSE_JRB: gCamera->cutscene = CUTSCENE_C3; gIstitle = 3; break;
        case COURSE_CCM: gCamera->cutscene = CUTSCENE_C4; gIstitle = 4; break;
    }

    if (gBorderHeight < 33) gBorderHeight++;

    if (buttonPressed & (A_BUTTON | B_BUTTON)) {
        resetFlags(); reset_camera(gCamera); o->activeFlags = 0;
        countdownStage = 1;
        frameCount = 0;
        isCountdown = 1;
        gIstitle = 0;
    }

    if (o->oTimer > 290 || (o->oSubAction > 2)) {
        resetFlags(); reset_camera(gCamera); o->activeFlags = 0;
        countdownStage = 1;
        frameCount = 0;
        isCountdown = 1;
        gIstitle = 0;
    }
}

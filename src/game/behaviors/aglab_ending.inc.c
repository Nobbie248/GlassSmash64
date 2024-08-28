void bhv_ending_player_init()
{
    set_cam_angle(2); // lakitu cam
    gHudDisplay.flags = HUD_DISPLAY_NONE;
    o->oHealth = 0x880;
}

void bhv_ending_player_loop()
{
    struct MarioStates* m = gMarioStates;
    set_mario_action(m, 0, 0);
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[0];
    gPlayer1Controller->buttonDown = 0;
    gPlayer1Controller->buttonPressed = 0;
    gPlayer1Controller->stickX = 0;
    gPlayer1Controller->stickY = 0;
    gPlayer1Controller->rawStickX = 0;
    gPlayer1Controller->rawStickY = 0;
    auto camera = gCurrentArea->camera;
    set_camera_mode_8_directions(camera);
    reset_camera(camera);

    if (60 == o->oTimer)
    {
        cur_obj_play_sound_2(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME);
    }
}

void bhv_sparkler_loop()
{
    if ((o->oTimer % 16) == 0)
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX = o->oPosX + random_f32_around_zero(100.f);
        spark->oPosY = o->oPosY + random_f32_around_zero(100.f);
        spark->oPosZ = o->oPosZ + random_f32_around_zero(100.f);
    }
}

extern struct ObjectHitbox sCollectStarHitbox;

// 0xFF, 0xc3, 0x0b
extern Gfx omm_star_glow_gfx[];
// 0xFF, 0xba, 0x01
extern Gfx omm_star_ray_0_gfx[];
extern Gfx omm_star_ray_1_gfx[];
extern Gfx omm_star_ray_2_gfx[];
extern Gfx omm_star_ray_3_gfx[];
extern Gfx omm_star_ray_4_gfx[];
extern Gfx omm_star_ray_5_gfx[];

static void set_color(Gfx* gfx, u8 r, u8 g, u8 b) {
    u8* color = (u8*) segmented_to_virtual(gfx) + 12;
    color[0] = r;
    color[1] = g;
    color[2] = b;
}

extern char gGrandStar;
void bhv_gem_init()
{
    o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_GEM_STAR];
    obj_set_hitbox(o, &sCollectStarHitbox);
    o->oInteractionSubtype |= (INT_SUBTYPE_NO_EXIT | INT_SUBTYPE_GEM);

    if (!gGrandStar)
    {
        uint32_t flags = save_file_get_flags();
        if (!(flags & SAVE_FILE_RL_BOWSER_DEAD)) {
            o->activeFlags = 0;
            return;
        }

        if (gMarioStates->numStars < 30)
        {
            o->activeFlags = 0;
            return;
        }

        if (save_file_is_gem_collected())
        {
            o->activeFlags = 0;
            return;
        }
    }

    u8 darkR = 0, darkG = 0, darkB = 0;
    u8 lightR = 0, lightG = 0, lightB = 0;

    switch (gCurrCourseNum)
    {
        case 1:
            // #116530
            darkR = 0x11;
            darkG = 0x65;
            darkB = 0x30;
            // #18A558
            lightR = 0x18;
            lightG = 0xA5;
            lightB = 0x58;
        break;
        case 2:
            // #7EC8E3
            darkR = 0x7E;
            darkG = 0xC8;
            darkB = 0xE3;
            // #050A30
            lightR = 0x05;
            lightG = 0x0A;
            lightB = 0x30;
        break;
        case 3:
            // #DF362D
            darkR = 0xDF;
            darkG = 0x36;
            darkB = 0x2D;
            // #FF4500
            lightR = 0xFF;
            lightG = 0x45;
            lightB = 0x00;
        break;
        case 4:
            // #51087E
            darkR = 0x51;
            darkG = 0x08;
            darkB = 0x7E;
            // #6C0BA9
            lightR = 0x6C;
            lightG = 0x0B;
            lightB = 0xA9;
        break;
    }

    set_color(omm_star_glow_gfx, lightR, lightG, lightB);
    set_color(omm_star_ray_0_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_1_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_2_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_3_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_4_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_5_gfx, darkR, darkG, darkB);
}

void bhv_fight_spawner_init()
{
    u8 darkR = 0xFF, darkG = 0xba, darkB = 0x01;
    u8 lightR = 0xFF, lightG = 0xc3, lightB = 0x0b;
    set_color(omm_star_glow_gfx, lightR, lightG, lightB);
    set_color(omm_star_ray_0_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_1_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_2_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_3_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_4_gfx, darkR, darkG, darkB);
    set_color(omm_star_ray_5_gfx, darkR, darkG, darkB);
}

void bhv_gem_loop()
{
    o->oFaceAngleYaw += 0x800;

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

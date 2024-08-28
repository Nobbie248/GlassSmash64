static const Vtx omm_star_glow_vertices[] = {
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 128.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 118.256577, 48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 85.959549, 94.841743, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 48.983479, 118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 0.000000, 128.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -48.983479, 118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -90.509666, 90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -118.256577, 48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -128.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -118.256577, -48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -90.509666, -90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -48.983479, -118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 0.000000, -128.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 48.983479, -118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 90.509666, -90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 118.256577, -48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 512.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 473.026306, 195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 362.038666, 362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 195.933914, 473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 512.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -195.933914, 473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -362.038666, 362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -473.026306, 195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -512.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -473.026306, -195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -362.038666, -362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -195.933914, -473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, -512.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 195.933914, -473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 362.038666, -362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 473.026306, -195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
};

static const Gfx omm_star_glow_triangles[] = {
    gsSPVertex(omm_star_glow_vertices, 32, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSP1Triangle(0, 3, 4, 0),
    gsSP1Triangle(0, 4, 5, 0),
    gsSP1Triangle(0, 5, 6, 0),
    gsSP1Triangle(0, 6, 7, 0),
    gsSP1Triangle(0, 7, 8, 0),
    gsSP1Triangle(0, 8, 9, 0),
    gsSP1Triangle(0, 9, 10, 0),
    gsSP1Triangle(0, 10, 11, 0),
    gsSP1Triangle(0, 11, 12, 0),
    gsSP1Triangle(0, 12, 13, 0),
    gsSP1Triangle(0, 13, 14, 0),
    gsSP1Triangle(0, 14, 15, 0),
    gsSP1Triangle(0, 15, 16, 0),
    gsSP1Triangle(0, 16, 1, 0),
    gsSP2Triangles(1, 17, 2, 0, 2, 17, 18, 0),
    gsSP2Triangles(2, 18, 3, 0, 3, 18, 19, 0),
    gsSP2Triangles(3, 19, 4, 0, 4, 19, 20, 0),
    gsSP2Triangles(4, 20, 5, 0, 5, 20, 21, 0),
    gsSP2Triangles(5, 21, 6, 0, 6, 21, 22, 0),
    gsSP2Triangles(6, 22, 7, 0, 7, 22, 23, 0),
    gsSP2Triangles(7, 23, 8, 0, 8, 23, 24, 0),
    gsSP2Triangles(8, 24, 9, 0, 9, 24, 25, 0),
    gsSP2Triangles(9, 25, 10, 0, 10, 25, 26, 0),
    gsSP2Triangles(10, 26, 11, 0, 11, 26, 27, 0),
    gsSP2Triangles(11, 27, 12, 0, 12, 27, 28, 0),
    gsSP2Triangles(12, 28, 13, 0, 13, 28, 29, 0),
    gsSP2Triangles(13, 29, 14, 0, 14, 29, 30, 0),
    gsSP2Triangles(14, 30, 15, 0, 15, 30, 31, 0),
    // thanks pc port
    gsSPVertex(omm_star_glow_vertices + 32, 1, 2),
    gsSP2Triangles(15, 31, 16, 0, 16, 31, 2, 0),
    gsSP2Triangles(16, 2, 1, 0, 1, 2, 17, 0),
    gsSPEndDisplayList(),
};

Gfx omm_star_glow_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xc3, 0x0b, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
	gsSPDisplayList(omm_star_glow_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

static const Vtx omm_star_rays_vertices[] = {
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1198.554565, 58.881210, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1198.554565, -58.881210, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1196.748535, 88.277481, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1196.748535, -88.277481, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1194.221680, 117.620567, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1194.221680, -117.620567, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1190.975464, 146.892807, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1190.975464, -146.892807, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1187.011841, 176.076569, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1187.011841, -176.076569, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1182.333130, 205.154266, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1182.333130, -205.154266, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
};

const Gfx omm_star_ray_0_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_1_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 3, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_2_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 6, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_3_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 9, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_4_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 12, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_5_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 15, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_0_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_0_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_1_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_1_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_2_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_2_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_3_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_3_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_4_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_4_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_5_gfx[] = {
    gsDPPipeSync(),
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_5_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

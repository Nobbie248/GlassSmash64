
Gfx diamond_particle_skyfc_ci4_aligner[] = {gsSPEndDisplayList()};
u8 diamond_particle_skyfc_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx diamond_particle_skyfc_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 diamond_particle_skyfc_pal_rgba16[] = {
	0x5f, 0xff, 
};

Vtx diamond_particle_diamond_particle_mesh_layer_5_vtx_cull[8] = {
	{{ {-5, 1, 5}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-5, 6, 5}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-5, 6, -11}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-5, 1, -11}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {11, 1, 5}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {11, 6, 5}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {11, 6, -11}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {11, 1, -11}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx diamond_particle_diamond_particle_mesh_layer_5_vtx_0[12] = {
	{{ {-5, 6, -3}, 0, {165, 165}, {243, 131, 239, 255} }},
	{{ {5, 6, -11}, 0, {315, 165}, {243, 131, 239, 255} }},
	{{ {11, 3, 5}, 0, {315, 315}, {243, 131, 239, 255} }},
	{{ {11, 3, 5}, 0, {315, 315}, {183, 93, 46, 255} }},
	{{ {5, 6, -11}, 0, {315, 165}, {183, 93, 46, 255} }},
	{{ {0, 1, -7}, 0, {315, 165}, {183, 93, 46, 255} }},
	{{ {5, 6, -11}, 0, {315, 165}, {80, 0, 99, 255} }},
	{{ {-5, 6, -3}, 0, {165, 165}, {80, 0, 99, 255} }},
	{{ {0, 1, -7}, 0, {315, 165}, {80, 0, 99, 255} }},
	{{ {-5, 6, -3}, 0, {165, 165}, {53, 92, 186, 255} }},
	{{ {11, 3, 5}, 0, {315, 315}, {53, 92, 186, 255} }},
	{{ {0, 1, -7}, 0, {165, 165}, {53, 92, 186, 255} }},
};

Gfx diamond_particle_diamond_particle_mesh_layer_5_tri_0[] = {
	gsSPVertex(diamond_particle_diamond_particle_mesh_layer_5_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_diamond_particle_f3dlite_material_011[] = {
	gsSPGeometryMode(G_CULL_BACK, 0),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x7f7f7fff),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 126),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, diamond_particle_skyfc_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 0),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, diamond_particle_skyfc_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 63, 2048),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 1, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 60),
	gsSPEndDisplayList(),
};

Gfx mat_revert_diamond_particle_f3dlite_material_011[] = {
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx diamond_particle_diamond_particle_mesh_layer_5[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(diamond_particle_diamond_particle_mesh_layer_5_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_diamond_particle_f3dlite_material_011),
	gsSPDisplayList(diamond_particle_diamond_particle_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_diamond_particle_f3dlite_material_011),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};


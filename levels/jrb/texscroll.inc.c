void scroll_jrb_dl_Brimstone_Banks_Definitive_Edition_mesh_layer_1_vtx_32() {
	int i = 0;
	int count = 109;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Brimstone_Banks_Definitive_Edition_mesh_layer_1_vtx_32);

	deltaX = (int)(0.0 * 0x20) % width;
	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_jrb_dl_skybox2_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 26;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_skybox2_mesh_layer_0_vtx_0);

	deltaY = (int)(0.009999999776482582 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_jrb_dl_LavaPools__noflow__001_f3d_001() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_LavaPools__noflow__001_f3d_001);

	shift_t(mat, 12, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_jrb_dl_AlsoFlowingLava_001_f3d_001() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_AlsoFlowingLava_001_f3d_001);

	shift_t_down(mat, 12, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_jrb_dl_f3dlite_material_layer1() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3dlite_material_layer1);

	shift_t(mat, 17, PACK_TILESIZE(0, 4));

};

void scroll_gfx_mat_jrb_dl_f3dlite_material_005_layer0() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3dlite_material_005_layer0);


	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 2));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));

};

void scroll_jrb() {
	scroll_jrb_dl_Brimstone_Banks_Definitive_Edition_mesh_layer_1_vtx_32();
	scroll_jrb_dl_skybox2_mesh_layer_0_vtx_0();
	scroll_gfx_mat_jrb_dl_LavaPools__noflow__001_f3d_001();
	scroll_gfx_mat_jrb_dl_AlsoFlowingLava_001_f3d_001();
	scroll_gfx_mat_jrb_dl_f3dlite_material_layer1();
	scroll_gfx_mat_jrb_dl_f3dlite_material_005_layer0();
};

void scroll_bowser_3_dl_Bowser_Fight_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_Bowser_Fight_mesh_layer_1_vtx_0);

	deltaY = (int)(0.3400000333786011 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bowser_3_dl_Bowser_Fight_002_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 11;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_Bowser_Fight_002_mesh_layer_1_vtx_0);

	deltaX = (int)(0.04999999701976776 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bowser_3_dl_Bowser_Fight_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_Bowser_Fight_003_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bowser_3_dl_skybox1_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 87;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_skybox1_mesh_layer_0_vtx_0);

	deltaY = (int)(0.3400000333786011 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bowser_3_dl_skybox2_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 53;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bowser_3_dl_skybox2_mesh_layer_0_vtx_0);

	deltaY = (int)(0.009999999776482582 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_bowser_3_dl__9_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bowser_3_dl__9_f3d_layer1);


	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bowser_3_dl_f3dlite_material_005_layer0() {
	Gfx *mat = segmented_to_virtual(mat_bowser_3_dl_f3dlite_material_005_layer0);


	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));

};

void scroll_bowser_3() {
	scroll_bowser_3_dl_Bowser_Fight_mesh_layer_1_vtx_0();
	scroll_bowser_3_dl_Bowser_Fight_002_mesh_layer_1_vtx_0();
	scroll_bowser_3_dl_Bowser_Fight_003_mesh_layer_5_vtx_0();
	scroll_bowser_3_dl_skybox1_mesh_layer_0_vtx_0();
	scroll_bowser_3_dl_skybox2_mesh_layer_0_vtx_0();
	scroll_gfx_mat_bowser_3_dl__9_f3d_layer1();
	scroll_gfx_mat_bowser_3_dl_f3dlite_material_005_layer0();
};

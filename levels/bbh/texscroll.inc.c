void scroll_bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_1_vtx_16() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_1_vtx_16);

	deltaY = (int)(-0.31999993324279785 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 54;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_5_vtx_0);

	deltaY = (int)(0.2200000286102295 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_1_vtx_110() {
	int i = 0;
	int count = 105;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_1_vtx_110);

	deltaY = (int)(-0.25999999046325684 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 62;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_5_vtx_0);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh() {
	scroll_bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_1_vtx_16();
	scroll_bbh_dl_DL_bbh_2_0xe01eb90_Obj_mesh_layer_5_vtx_0();
	scroll_bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_1_vtx_110();
	scroll_bbh_dl_DL_bbh_6_0xe044ab0_Obj_mesh_layer_5_vtx_0();
};

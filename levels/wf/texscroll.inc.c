void scroll_wf_dl_WinterLevel_2020version_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 9;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_WinterLevel_2020version_001_mesh_layer_5_vtx_0);

	deltaY = (int)(0.05000000074505806 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 281;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_0);

	deltaX = (int)(0.1599999964237213 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_1() {
	int i = 0;
	int count = 103;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_1);

	deltaY = (int)(0.12999999523162842 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_wf_dl_WinterLevel_2020version_001_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(wf_dl_WinterLevel_2020version_001_mesh_layer_5);

	shift_s(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_wf() {
	scroll_wf_dl_WinterLevel_2020version_001_mesh_layer_5_vtx_0();
	scroll_wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_0();
	scroll_wf_dl_zzWinterLevel_2020version_013_mesh_layer_0_vtx_1();
	scroll_gfx_wf_dl_WinterLevel_2020version_001_mesh_layer_5();
};

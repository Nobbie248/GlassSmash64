void scroll_bob_dl_ground_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 26;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_ground_001_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_ground_001_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 12;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_ground_001_mesh_layer_5_vtx_1);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_bob_dl_ground_001_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(bob_dl_ground_001_mesh_layer_5);

	shift_t(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_bob_dl_ground_001_mesh_layer_5_vtx_0();
	scroll_bob_dl_ground_001_mesh_layer_5_vtx_1();
	scroll_gfx_bob_dl_ground_001_mesh_layer_5();
};

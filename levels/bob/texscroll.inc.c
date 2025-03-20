void scroll_bob_dl_water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 38;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_water_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_water3_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 17;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_water3_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_zsplash_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_zsplash_mesh_layer_5_vtx_0);

	deltaX = (int)(0.30000001192092896 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_zsplash_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_zsplash_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.30000001192092896 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_bob_dl_water_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(bob_dl_water_mesh_layer_5);

	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_bob_dl_water2_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(bob_dl_water2_mesh_layer_5);


	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 20, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 20, PACK_TILESIZE(0, 2));

};

void scroll_gfx_bob_dl_water3_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(bob_dl_water3_mesh_layer_5);

	shift_s(mat, 14, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_bob_dl_water_mesh_layer_5_vtx_0();
	scroll_bob_dl_water3_mesh_layer_5_vtx_0();
	scroll_bob_dl_zsplash_mesh_layer_5_vtx_0();
	scroll_bob_dl_zsplash_001_mesh_layer_5_vtx_0();
	scroll_gfx_bob_dl_water_mesh_layer_5();
	scroll_gfx_bob_dl_water2_mesh_layer_5();
	scroll_gfx_bob_dl_water3_mesh_layer_5();
};

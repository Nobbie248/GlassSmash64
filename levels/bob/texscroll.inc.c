void scroll_bob_dl_water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 32;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_water_mesh_layer_5_vtx_0);

	deltaX = (int)(0.5 * 0x20) % width;

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

	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_bob_dl_water_mesh_layer_5_vtx_0();
	scroll_gfx_bob_dl_water_mesh_layer_5();
};

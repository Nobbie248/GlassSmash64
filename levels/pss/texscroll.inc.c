void scroll_pss_dl_skybox4sh_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 178;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(pss_dl_skybox4sh_mesh_layer_0_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_pss() {
	scroll_pss_dl_skybox4sh_mesh_layer_0_vtx_0();
};

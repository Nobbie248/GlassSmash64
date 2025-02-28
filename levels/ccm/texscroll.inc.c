void scroll_ccm_dl_z_flames_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 192;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 2.049999713897705;
	float frequencyY = 1.0;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(ccm_dl_z_flames_mesh_layer_5_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_ccm_dl_z_flames_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 153;
	int height = 128 * 0x20;

	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 2.049999713897705;
	float frequencyY = 1.0;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(ccm_dl_z_flames_001_mesh_layer_5_vtx_0);

	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;	timeY += 1;
}

void scroll_gfx_mat_ccm_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Water_layer5);


	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 2));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_f3dlite_material_044() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_f3dlite_material_044);

	shift_s(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_ccm() {
	scroll_ccm_dl_z_flames_mesh_layer_5_vtx_0();
	scroll_ccm_dl_z_flames_001_mesh_layer_5_vtx_0();
	scroll_gfx_mat_ccm_dl_Water_layer5();
	scroll_gfx_mat_ccm_dl_f3dlite_material_044();
};

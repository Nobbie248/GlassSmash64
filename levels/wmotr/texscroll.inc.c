void scroll_wmotr_dl_Plane_mesh_layer_7_vtx_0() {
	int i = 0;
	int count = 177;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Plane_mesh_layer_7_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr() {
	scroll_wmotr_dl_Plane_mesh_layer_7_vtx_0();
};

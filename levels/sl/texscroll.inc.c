void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 139;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_8);

	deltaY = (int)(0.10000002384185791 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_9() {
	int i = 0;
	int count = 53;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_9);

	deltaY = (int)(0.12999999523162842 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 42;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_11);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_22() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_22);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_25() {
	int i = 0;
	int count = 72;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_25);

	deltaY = (int)(-0.31999993324279785 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_30() {
	int i = 0;
	int count = 164;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_mesh_layer_1_vtx_30);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 1536;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000002384185791 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Bowser_Level_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 91;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Bowser_Level_003_mesh_layer_1_vtx_0);

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

void scroll_sl_dl_Icosphere_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 26;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Icosphere_mesh_layer_0_vtx_0);

	deltaY = (int)(0.009999999776482582 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Icosphere_001_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 11;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(sl_dl_Icosphere_001_mesh_layer_0_vtx_0);

	deltaY = (int)(0.009999999776482582 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sl_dl_Icosphere_002_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 26;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(sl_dl_Icosphere_002_mesh_layer_0_vtx_0);

	deltaX = (int)(-0.009999999776482582 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_sl_dl_Bowser_Level_003_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(sl_dl_Bowser_Level_003_mesh_layer_1);

	shift_t(mat, 19, PACK_TILESIZE(0, 4));

};

void scroll_gfx_sl_dl_Icosphere_mesh_layer_0() {
	Gfx *mat = segmented_to_virtual(sl_dl_Icosphere_mesh_layer_0);

	shift_s(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_gfx_sl_dl_Icosphere_002_mesh_layer_0() {
	Gfx *mat = segmented_to_virtual(sl_dl_Icosphere_002_mesh_layer_0);

	shift_s(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_sl() {
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_8();
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_9();
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_11();
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_22();
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_25();
	scroll_sl_dl_Bowser_Level_mesh_layer_1_vtx_30();
	scroll_sl_dl_Bowser_Level_001_mesh_layer_1_vtx_0();
	scroll_sl_dl_Bowser_Level_003_mesh_layer_1_vtx_0();
	scroll_sl_dl_Icosphere_mesh_layer_0_vtx_0();
	scroll_sl_dl_Icosphere_001_mesh_layer_0_vtx_0();
	scroll_sl_dl_Icosphere_002_mesh_layer_0_vtx_0();
	scroll_gfx_sl_dl_Bowser_Level_003_mesh_layer_1();
	scroll_gfx_sl_dl_Icosphere_mesh_layer_0();
	scroll_gfx_sl_dl_Icosphere_002_mesh_layer_0();
};

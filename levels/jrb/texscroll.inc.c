void scroll_gfx_jrb_dl_Map_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(jrb_dl_Map_mesh_layer_5);


	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 20, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 20, PACK_TILESIZE(0, 2));

};

void scroll_jrb() {
	scroll_gfx_jrb_dl_Map_mesh_layer_5();
};

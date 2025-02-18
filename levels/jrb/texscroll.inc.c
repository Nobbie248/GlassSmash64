void scroll_gfx_mat_jrb_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_Water_layer5);


	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 2));

};

void scroll_jrb() {
	scroll_gfx_mat_jrb_dl_Water_layer5();
};

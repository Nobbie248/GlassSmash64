void scroll_gfx_mat_wf_dl_Water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Water_layer5);


	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 2));

};

void scroll_wf() {
	scroll_gfx_mat_wf_dl_Water_layer5();
};

void scroll_gfx_mat_ddd_dl_f3dlite_material_026() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_f3dlite_material_026);


	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 2));

};

void scroll_ddd() {
	scroll_gfx_mat_ddd_dl_f3dlite_material_026();
};

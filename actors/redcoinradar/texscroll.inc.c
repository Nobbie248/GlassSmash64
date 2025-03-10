void scroll_gfx_mat_redcoinradar_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_redcoinradar_f3dlite_material);

	shift_s(mat, 14, PACK_TILESIZE(0, 4));

};

void scroll_actor_geo_redcoinradar() {
	scroll_gfx_mat_redcoinradar_f3dlite_material();
};

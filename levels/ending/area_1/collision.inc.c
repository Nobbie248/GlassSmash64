const Collision ending_area_1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-428, -132, 33),
	COL_VERTEX(-228, -132, 33),
	COL_VERTEX(-228, -132, -167),
	COL_VERTEX(-428, -132, -167),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};

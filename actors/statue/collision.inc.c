const Collision statue_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(8),
	COL_VERTEX(-71, -152, 71),
	COL_VERTEX(-71, 102, 71),
	COL_VERTEX(-71, 102, -71),
	COL_VERTEX(-71, -152, -71),
	COL_VERTEX(71, 102, -71),
	COL_VERTEX(71, -152, -71),
	COL_VERTEX(71, 102, 71),
	COL_VERTEX(71, -152, 71),
	COL_TRI_INIT(SURFACE_HARD_NOT_SLIPPERY, 10),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 4, 5),
	COL_TRI(5, 4, 6),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 6, 1),
	COL_TRI(7, 1, 0),
	COL_TRI(4, 2, 1),
	COL_TRI(4, 1, 6),
	COL_TRI_STOP(),
	COL_END()
};

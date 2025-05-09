const Collision bnet_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(20),
	COL_VERTEX(1, 16, -120),
	COL_VERTEX(105, 16, -60),
	COL_VERTEX(1, 26, 0),
	COL_VERTEX(105, 16, 60),
	COL_VERTEX(125, 65, 72),
	COL_VERTEX(1, 65, 143),
	COL_VERTEX(1, 16, 120),
	COL_VERTEX(-103, 16, 60),
	COL_VERTEX(-123, 65, 72),
	COL_VERTEX(-123, 65, -72),
	COL_VERTEX(-103, 16, -60),
	COL_VERTEX(1, 65, -143),
	COL_VERTEX(125, 65, -72),
	COL_VERTEX(1, 48, 0),
	COL_VERTEX(1, 90, 142),
	COL_VERTEX(124, 90, 71),
	COL_VERTEX(124, 90, -71),
	COL_VERTEX(1, 90, -142),
	COL_VERTEX(-122, 90, 71),
	COL_VERTEX(-122, 90, -71),
	COL_TRI_INIT(SURFACE_DEFAULT, 36),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 5),
	COL_TRI(3, 5, 6),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 10),
	COL_TRI(10, 9, 11),
	COL_TRI(10, 11, 0),
	COL_TRI(0, 11, 12),
	COL_TRI(0, 12, 1),
	COL_TRI(1, 12, 4),
	COL_TRI(1, 4, 3),
	COL_TRI(6, 5, 8),
	COL_TRI(6, 8, 7),
	COL_TRI(3, 6, 2),
	COL_TRI(7, 10, 2),
	COL_TRI(1, 3, 2),
	COL_TRI(6, 7, 2),
	COL_TRI(5, 4, 13),
	COL_TRI(4, 12, 13),
	COL_TRI(9, 8, 13),
	COL_TRI(12, 11, 13),
	COL_TRI(8, 5, 13),
	COL_TRI(11, 9, 13),
	COL_TRI(10, 0, 2),
	COL_TRI(4, 5, 14),
	COL_TRI(4, 14, 15),
	COL_TRI(11, 12, 16),
	COL_TRI(11, 16, 17),
	COL_TRI(5, 8, 18),
	COL_TRI(5, 18, 14),
	COL_TRI(9, 11, 17),
	COL_TRI(9, 17, 19),
	COL_TRI(12, 4, 15),
	COL_TRI(12, 15, 16),
	COL_TRI(8, 9, 19),
	COL_TRI(8, 19, 18),
	COL_TRI_STOP(),
	COL_END()
};

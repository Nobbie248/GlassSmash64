const Collision mixer_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-148, -25, 111),
	COL_VERTEX(-148, 0, 111),
	COL_VERTEX(-148, 0, 41),
	COL_VERTEX(-148, -25, 41),
	COL_VERTEX(134, 0, 41),
	COL_VERTEX(134, -25, 41),
	COL_VERTEX(134, 0, 111),
	COL_VERTEX(134, -25, 111),
	COL_VERTEX(-148, -25, 22),
	COL_VERTEX(-148, 140, 22),
	COL_VERTEX(-148, 140, -49),
	COL_VERTEX(-148, -25, -49),
	COL_VERTEX(134, 140, -49),
	COL_VERTEX(134, -25, -49),
	COL_VERTEX(134, 140, 22),
	COL_VERTEX(134, -25, 22),
	COL_TRI_INIT(0x007E, 24),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 4, 5),
	COL_TRI(5, 4, 6),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 6, 1),
	COL_TRI(7, 1, 0),
	COL_TRI(3, 5, 7),
	COL_TRI(3, 7, 0),
	COL_TRI(4, 2, 1),
	COL_TRI(4, 1, 6),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(11, 10, 12),
	COL_TRI(11, 12, 13),
	COL_TRI(13, 12, 14),
	COL_TRI(13, 14, 15),
	COL_TRI(15, 14, 9),
	COL_TRI(15, 9, 8),
	COL_TRI(11, 13, 15),
	COL_TRI(11, 15, 8),
	COL_TRI(12, 10, 9),
	COL_TRI(12, 9, 14),
	COL_TRI_STOP(),
	COL_END()
};

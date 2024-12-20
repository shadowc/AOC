#pragma once

enum class SearchDirection : int {
	LeftToRight = 0,
	RightToLeft = 1,
	TopToBottom = 2,
	BottomToTop = 3,
	TopLeftToBottomRight = 4,
	BottomRightToTopLeft = 5,
	TopRightToBottomLeft = 6,
	BottomLeftToTopRight = 7
};

struct SearchOffset {
	SearchOffset() {
		OffsetX = 0;
		OffsetY = 0;
	}

	SearchOffset(int x, int y) {
		OffsetX = x;
		OffsetY = y;
	}

	int OffsetX;
	int OffsetY;
};

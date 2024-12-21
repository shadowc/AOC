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

/**
 * M   M  -1 -1   1 -1
 *   A
 * S   S  -1  1   1  1
 * 
 * S   M  
 *   A
 * S   M
 * 
 * S   S
 *   A
 * M   M
 * 
 * M   S
 *   A
 * M   S
 */


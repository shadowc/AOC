#pragma once

struct Numbers {
	Numbers() {
		Left = 0;
		Right = 0;
		Sum = abs(Left - Right);
	}

	Numbers(int l, int r) {
		Left = l;
		Right = r;
		Sum = abs(Left - Right);
	}

	int Left;
	int Right;
	int Sum;
};

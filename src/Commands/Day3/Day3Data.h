#pragma once

struct Mults {
	Mults() {
		Left = 0;
		Right = 0;
		Mul = Left * Right;
		Ignored = false;
	}

	Mults(int l, int r, bool i) {
		Left = l;
		Right = r;
		Ignored = i;
		Mul = Left * Right;
	}

	int Left;
	int Right;
	int Mul;
	bool Ignored;
};

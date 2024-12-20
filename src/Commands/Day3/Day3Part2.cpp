#include "Day3Part2.h"
#include "Day3Data.h"
#include <iostream>

using std::cout;

void Day3Part2Command::Run()
{
	int mulTotal = 0;

	for (Mults datum : Data) {
		if (!datum.Ignored) {
			mulTotal += datum.Mul;
		}
	}

	cout << "\n  *** The total of all the mul instructions not ignored is " << mulTotal << "\n";
}

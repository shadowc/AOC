#include "Day3Part1.h"
#include "Day3Data.h"
#include <iostream>

using std::cout;

void Day3Part1Command::Run()
{
	int mulTotal = 0;

	for (Mults datum : Data) {
		mulTotal += datum.Mul;
	}

	cout << "\n  *** The total of all the mul instructions is " << mulTotal << "\n";
}

#include "Day2Part1.h"
#include <iostream>

using std::cout;

void Day2Part1Command::Run()
{
	int safeReports = 0;

	for (vector<char> datum : Data) {
		if (CheckReport(datum)) {
			safeReports++;
		}
	}

	cout << "\n  *** The number of safe reports is " << safeReports << "\n";
}

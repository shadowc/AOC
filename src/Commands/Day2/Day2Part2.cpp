#include "Day2Part2.h"
#include <iostream>

using std::cout;

void Day2Part2Command::Run()
{
	int safeReports = 0;

	for (vector<char> datum : Data) {
		if (CheckReport(datum)) {
			safeReports++;
			continue;
		}

		for (size_t i = 0; i < datum.size(); i++) {
			if (CheckReport(datum, i)) {
				safeReports++;
				break;
			}
		}
	}

	cout << "\n  *** The number of safe reports is " << safeReports << "\n";
}

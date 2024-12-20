#include "Day1Part2.h"
#include <iostream>

using std::cout;

void Day1Part2Command::Run()
{
	int result = 0;

	for (Numbers datum : Data) {
		int left = datum.Left;
		int appearances = 0;

		for (Numbers rightSide : Data) {
			if (left == rightSide.Right) {
				appearances++;
			}
		}

		result += left * appearances;
	}

	cout << "\n  *** The similarity score is " << result << "\n";
}

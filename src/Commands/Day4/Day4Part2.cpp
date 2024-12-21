#include "Day4Part2.h"
#include <iostream>

using std::cout;

void Day4Part2Command::Run()
{
	int result = 0;

	for (size_t y = 0; y < Data.size(); y++) {
		string line = Data.at(y);

		for (size_t x = 0; x < line.size(); x++) {
			if (line.at(x) == 'A') {
				// search X-MAS cross here!
				if (XMasCrossExists(x, y)) {
					result++;
				}
			}
		}
	}

	cout << "\n  *** The number of X-MAS crosses is " << result << "\n";
}

bool Day4Part2Command::XMasCrossExists(size_t x, size_t y)
{
	if (y < 1 || y >= Data.size() - 1) {
		return false;
	}

	string line = Data.at(y);

	if (x < 1 || x >= line.size() - 1) {
		return false;
	}
	
	for (size_t xmasPatternIndex = 0; xmasPatternIndex < 4; xmasPatternIndex++) {
		int correctLetters = 0;
		// cout << "Trying secuence " << (xmasPatternIndex+1) << " at(" << (x+1) << ", " << (y+1) << ") [" << XMasSequence[xmasPatternIndex] << "]  ";

		for (size_t offsetIndex = 0; offsetIndex < 4; offsetIndex++) {
			char letter = Data.at(y + XMasOffsets[offsetIndex].OffsetY).at(x + XMasOffsets[offsetIndex].OffsetX);

			if (letter == XMasSequence[xmasPatternIndex].at(offsetIndex)) {
				correctLetters++;
				// cout << "*";
			}
			else {
				// cout << ".";
			}
		}

		if (correctLetters == 4) {
			// cout << " [!] Found!\n";
			return true;
		}

		// cout << " [x]\n";
	}
	
	return false;
}

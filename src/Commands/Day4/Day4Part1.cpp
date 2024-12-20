#include "Day4Part1.h"
#include "Day4Data.h"
#include <iostream>

using std::cout;

void Day4Part1Command::Run()
{
	int result = 0;

	for (int i = 0; i < 8; i++) {
		result += SearchXMAS((SearchDirection)i);
	}

	cout << "\n  *** The number of times XMAS appears is " << result << "\n";
}

int Day4Part1Command::SearchXMAS(SearchDirection direction)
{
	int occurrences = 0;
	string wordToSearch = "XMAS";

	SearchOffset offsets = SearchOffsets[(size_t)direction];

	for (size_t y = 0; y < Data.size(); y++) {
		string line = Data.at(y);

		for (size_t x = 0; x < line.size(); x++) {
			if (line.at(x) == wordToSearch.at(0)) {
				// search xmas here!
				if (WordExists(wordToSearch, x, y, offsets)) {
					occurrences++;
				}
			}
		}
	}

	return occurrences;
}

bool Day4Part1Command::WordExists(string word, size_t x, size_t y, SearchOffset offset)
{
	for (size_t i = 0; i < word.size(); i++) {
		size_t offsetY = y + (offset.OffsetY * i);
		size_t offsetX = x + (offset.OffsetX * i);

		if (offsetY < 0 || offsetY >= Data.size()) {
			return false;
		}

		string line = Data.at(offsetY);

		if (offsetX < 0 || offsetX >= line.size()) {
			return false;
		}

		if (line.at(offsetX) != word.at(i)) {
			return false;
		}
	}

	return true;
}

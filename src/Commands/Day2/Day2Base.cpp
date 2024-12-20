#include "Day2Base.h"
#include <vector>

using std::vector;
using std::isspace;

void Day2Base::ParseInput(vector<string> lines)
{
	Data = vector<vector<char>>();

	for (string line : lines) {
		vector<char> numbers = vector<char>();

		size_t nextNumber = 0;
		size_t fromIndex = 0;
		for (size_t cursor = 0; cursor < line.size(); cursor++) {
			char c = line.at(cursor);

			if (isspace(c)) {
				numbers.push_back(atoi(line.substr(fromIndex, cursor - fromIndex).c_str()));
				fromIndex = cursor + 1;
			}
		}

		if (fromIndex < line.size()) {
			numbers.push_back(atoi(line.substr(fromIndex, fromIndex - line.size()).c_str()));
		}

		Data.push_back(numbers);
	}
}

bool Day2Base::CheckReport(vector<char> Datum)
{
	bool ascending = Datum.at(1) > Datum.at(0);
	for (size_t i = 2; i < Datum.size(); i++) {
		if ((ascending && Datum.at(i) < Datum.at(i - 1)) || !ascending && Datum.at(i) > Datum.at(i - 1)) {
			return false;
		}
	}

	for (size_t i = 1; i < Datum.size(); i++) {
		if (Datum.at(i) == Datum.at(i - 1) || abs(Datum.at(i) - Datum.at(i - 1)) > 3) {
			return false;
		}
	}

	return true;
}

bool Day2Base::CheckReport(vector<char> Datum, size_t skipIndex)
{
	vector<char> DatumCopy = vector<char>();

	for (size_t i = 0; i < Datum.size(); i++) {
		if (i != skipIndex) {
			DatumCopy.push_back(Datum.at(i));
		}
	}

	return CheckReport(DatumCopy);
}

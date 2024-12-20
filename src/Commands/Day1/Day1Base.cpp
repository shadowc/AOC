#include "Commands/Day1/Day1Base.h"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;

void Day1BaseCommand::ParseInput(vector<string> lines)
{
	Data = vector<Numbers>();

	vector<int> LeftEntries = vector<int>();
	vector<int> RightEntries = vector<int>();

	for (string line : lines) {
		size_t sep = line.find(" ");

		LeftEntries.push_back(atoi(line.substr(0, sep).c_str()));
		RightEntries.push_back(atoi(line.substr(sep, line.size() - sep).c_str()));
	}

	sort(LeftEntries.begin(), LeftEntries.end());
	sort(RightEntries.begin(), RightEntries.end());

	for (size_t i = 0; i < LeftEntries.size(); i++) {
		Data.push_back(Numbers(LeftEntries.at(i), RightEntries.at(i)));
	}
}

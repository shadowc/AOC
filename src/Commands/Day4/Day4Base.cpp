#include "Day4Base.h"
// #include "Commands/Day4/Day4Data.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

void Day4BaseCommand::ParseInput(vector<string> lines)
{
	Data = vector<string>();

	for (string line : lines) {
		Data.push_back(line);
	}
}

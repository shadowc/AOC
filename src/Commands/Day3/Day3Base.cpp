#include "Day3Base.h"
#include "Commands/Day1/Day1Data.h"
#include <vector>
#include <string>
#include <regex>

using std::vector;
using std::string;
using std::sregex_iterator;
using std::smatch;

void Day3BaseCommand::ParseInput(vector<string> lines)
{
	Data = vector<Numbers>();

	for (string line : lines) {
		ParseLine(line);
	}
}

void Day3BaseCommand::ParseLine(string line)
{
	auto MulBegin = sregex_iterator(line.begin(), line.end(), MulRegex);
	auto MulEnd = sregex_iterator();

	for (std::sregex_iterator i = MulBegin; i != MulEnd; ++i)
	{
		smatch match = *i;
		string match_str = match.str();

		size_t leftParen = match_str.find("(");
		size_t comma = match_str.find(",");
		size_t rightParen = match_str.find(")");

		Data.push_back(Numbers(
			atoi(match_str.substr(leftParen+1,comma-1).c_str()),
			atoi(match_str.substr(comma+1, rightParen-1).c_str())
		));
	}
}

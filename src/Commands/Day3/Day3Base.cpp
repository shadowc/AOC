#include "Day3Base.h"
#include "Commands/Day3/Day3Data.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using std::vector;
using std::string;
using std::sregex_iterator;
using std::smatch;

using std::cout;

void Day3BaseCommand::ParseInput(vector<string> lines)
{
	Data = vector<Mults>();

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

		cout << match_str << "   ";

		size_t leftParen = match_str.find("(");
		size_t comma = match_str.find(",");
		size_t rightParen = match_str.find(")");
		size_t doCommand = match_str.find("do()");
		size_t dontCommand = match_str.find("don't()");

		if (doCommand != string::npos) {
			DatumIgnored = false;
			
			cout << "Enabling... \n";
			continue;
		}

		if (dontCommand != string::npos) {
			DatumIgnored = true;
			
			cout << "Disabling... \n";
			continue;
		}

		cout << (DatumIgnored ? "Ignored" : "Not ignored") << "\n";
		Data.push_back(Mults(
			atoi(match_str.substr(leftParen + 1, comma - 1).c_str()),
			atoi(match_str.substr(comma + 1, rightParen - 1).c_str()),
			DatumIgnored
		));
	}
}

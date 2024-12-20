#pragma once
#include "Commands/BaseCommand.h"
#include "Commands/Day3/Day3Data.h"
#include <vector>
#include <string>
#include <regex>

using std::string;
using std::vector;
using std::regex;

class Day3BaseCommand : public BaseCommand
{
public:
	virtual void ParseInput(vector<string> lines) override;

protected:
	void ParseLine(string line);

	vector<Mults> Data;

	bool DatumIgnored = false;

	regex MulRegex = regex("mul\\(\\d{1,3}\\,\\d{1,3}\\)|do\\(\\)|don\\'t\\(\\)");
};

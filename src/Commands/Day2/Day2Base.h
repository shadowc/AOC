#pragma once
#include "Commands/BaseCommand.h"
#include <vector>
#include <string>

using std::string;
using std::vector;


class Day2Base : public BaseCommand
{
public:
	virtual void ParseInput(vector<string> lines) override;

protected:
	vector<vector<char>> Data;

	bool CheckReport(vector<char> Datum);
	bool CheckReport(vector<char> Datum, size_t skipIndex);
};

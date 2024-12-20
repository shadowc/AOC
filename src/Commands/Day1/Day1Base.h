#pragma once
#include "Commands/BaseCommand.h"
#include "Commands/Day1/Day1Data.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Day1BaseCommand : public BaseCommand
{
public:
	virtual void ParseInput(vector<string> lines) override;

protected:
	vector<Numbers> Data;
};

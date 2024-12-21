#pragma once
#include "Commands/BaseCommand.h"
#include "Commands/Day4/Day4Data.h"
#include <vector>
#include <string>


using std::string;
using std::vector;

class Day4BaseCommand : public BaseCommand
{
public:
	virtual void ParseInput(vector<string> lines) override;

protected:
	vector<string> Data;

	SearchOffset SearchOffsets[8];

	string XMasSequence[4];

	SearchOffset XMasOffsets[4];
};


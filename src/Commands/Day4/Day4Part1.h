#pragma once
#include "Commands/Day4/Day4Base.h"
#include "Commands/Day4/Day4Data.h"
#include <string>

using std::string;

class Day4Part1Command : public Day4BaseCommand
{
public:
	virtual void Run() override;

protected:
	int SearchXMAS(SearchDirection direction);

	bool WordExists(string word, size_t x, size_t y, SearchOffset offset);

};

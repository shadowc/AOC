#pragma once

#include "Commands/Day4/Day4Base.h"

class Day4Part2Command : public Day4BaseCommand
{
public:
	virtual void Run() override;

	bool XMasCrossExists(size_t x, size_t y);
};

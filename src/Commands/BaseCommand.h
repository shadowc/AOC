#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class BaseCommand {
public:
	virtual void ParseInput(vector<string> lines) = 0;

	virtual void Run() = 0;
};

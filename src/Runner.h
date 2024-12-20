#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class BaseCommand;

class Runner {
public:
	Runner();
	~Runner();

	void InitArgs(int const argc, char* const argv[]);
	void PrintOptions() const;

	void RunCommand() const;

private:
	size_t Day;
	size_t Part;

	vector<vector<BaseCommand*>> Commands;

	bool IsParameterValid(char* const param);

	string GetFilePath() const;
};

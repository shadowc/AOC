#include "Runner.h"
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <vector>
#include "Commands/BaseCommand.h"
#include "Commands/Day1/Day1Part1.h"
#include "Commands/Day1/Day1Part2.h"
#include "Commands/Day2/Day2Part1.h"
#include "Commands/Day2/Day2Part2.h"

using std::cout;
using std::vector;
using std::runtime_error;
using std::to_string;
using std::getline;
using std::ifstream;
using std::exception;

Runner::Runner()
{
	Commands = {
		{
			new Day1Part1Command(),
			new Day1Part2Command()
		},
		{
			new Day2Part1Command(),
			new Day2Part2Command()
		}
	};
}

Runner::~Runner()
{
	for (vector<BaseCommand*> Day : Commands) {
		for (BaseCommand* Command : Day) {
			delete Command;
		}
	}
}

void Runner::InitArgs(int const argc, char* const argv[])
{
	if (argc != 3) {
		throw runtime_error("Invalid number of parameters given. This command accepts exactly 2 parameters.");
	}

	if (!IsParameterValid(argv[1]) || !IsParameterValid(argv[2])) {
		throw runtime_error("Invalid parameter type. Parameters must be numbers.");
	}

	Day = (size_t) atoi(argv[1]);
	Part = (size_t) atoi(argv[2]);

	if (Day > Commands.size()) {
		throw runtime_error("The day specified hasn't been coded yet.");
	}

	if (Part > Commands[Day - 1].size()) {
		throw runtime_error("The day specified doesn't contain the part specified.");
	}
}

void Runner::PrintOptions() const
{
	cout << " Currently available options are:\n\n";

	for (size_t d = 0; d < Commands.size(); d++) {
		for (size_t p = 0; p < Commands[d].size(); p++) {
			cout << (p > 0 || d > 0 ? ", " : " ") << (d+1) << " " << (p+1);
		}
	}

	cout << "\n";
}

void Runner::RunCommand() const
{
	try {
		cout << "  Running command for Day " << Day << ", Part " << Part << "\n\n";

		auto CommandToRun = Commands[Day - 1][Part - 1];

		cout << "  Reading file " << GetFilePath() << "...\n";

		ifstream File(GetFilePath());

		if (!File.is_open()) { // always check whether the file is open
			cout << "  Error! File could not be read (" << GetFilePath() << ")!\n\n";
			return;
		}

		cout << "  Parsing the file...\n";

		string line;
		vector<string> lines;
		while (getline(File, line)) {
			lines.push_back(string(line));
		}

		CommandToRun->ParseInput(lines);

		cout << "  File parsed. Running computation...\n";

		File.close();

		CommandToRun->Run();

		cout << "\n";
	}
	catch (exception& e) {
		cout << "  Error running the command.\n";
		cout << e.what() << "\n\n";
	}
}

bool Runner::IsParameterValid(char* const param)
{
	size_t i = 0;

	while (param[i] != '\0') {
		if (!isdigit(param[i])) {
			return false;
		}

		i++;
	}
	return true;
}

string Runner::GetFilePath() const
{
	return "DataFiles/Day" + to_string(Day) + ".txt";
}

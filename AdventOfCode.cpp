// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include "src/Runner.h"

using std::runtime_error;
using std::cout;

int main(int argc, char* argv[])
{
    Runner* runner = new Runner();

    cout << "=== ADVENT OF CODE RUNNER ===\n\n";

    try {
        runner->InitArgs(argc, argv);

        runner->RunCommand();

        delete runner;

        cout << "=== END ===\n";

        return 0;
    }
    catch (runtime_error e) {
        cout << " Usage: \n\n";
        cout << "  AdventOfCode.exe <day> <part>\n\n";
        cout << "    Where <day> and <part> are numbers for the day and the part you want to run.\n\n";

        runner->PrintOptions();

        cout << "\n\n Error: " << e.what() << "\n\n";

        delete runner;

        return 1;
    } 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

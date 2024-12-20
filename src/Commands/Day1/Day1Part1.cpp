#include "Commands/Day1/Day1Part1.h"
#include <iostream>

using std::cout;
void Day1Part1Command::Run()
{
    int result = 0;

    int curline = 1;
    for (Numbers datum : Data) {
        curline++;
        result += datum.Sum;
    }

    cout << "\n  *** The sum of the sorted diffs is " << result << "\n";
}

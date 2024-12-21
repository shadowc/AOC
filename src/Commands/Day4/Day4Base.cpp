#include "Day4Base.h"
#include "Commands/Day4/Day4Data.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

void Day4BaseCommand::ParseInput(vector<string> lines)
{
	SearchOffsets[0] = SearchOffset(1, 0);
	SearchOffsets[1] = SearchOffset(-1, 0);
	SearchOffsets[2] = SearchOffset(0, 1);
	SearchOffsets[3] = SearchOffset(0, -1);
	SearchOffsets[4] = SearchOffset(1, 1);
	SearchOffsets[5] = SearchOffset(-1, -1);
	SearchOffsets[6] = SearchOffset(-1, 1);
	SearchOffsets[7] = SearchOffset(1, -1);

	XMasOffsets[0] = SearchOffset(-1, -1);
	XMasOffsets[1] = SearchOffset(1, -1);
	XMasOffsets[2] = SearchOffset(1, 1);
	XMasOffsets[3] = SearchOffset(-1, 1);

	XMasSequence[0] = "MMSS";
	XMasSequence[1] = "MSSM";
	XMasSequence[2] = "SSMM";
	XMasSequence[3] = "SMMS";

	Data = vector<string>();

	for (string line : lines) {
		Data.push_back(line);
	}
}

#include "pch.h"
#include <string>
#include "Hanoi.h"

using namespace std;

Hanoi::Hanoi(std::vector<int> disks) {
	towers[0] = Tower();
	towers[1] = Tower();
	towers[2] = Tower();
	errorMsg = "";
	for (int i = 0; i < (int)disks.size(); i++)
	{
		if (!towers[0].add(disks[i]))
		{
			errorMsg = "Disks are not in proper order";
			break;
		}
	}
}

int Hanoi::moveDisks(int diskstoMove, int first, int last, int middle) {
	if (errorMsg != "") return 0;
	int count = 0;
	if (diskstoMove > 1)
	{
		count = moveDisks(diskstoMove - 1, first, middle, last);
	}
	int disk = towers[first].removeLast();
	if (disk < 0)
	{
		errorMsg = errorMsg + "| no disk found";
		return 0;
	}
	if (!towers[last].add(disk))
	{
		errorMsg = errorMsg + "| disk " + std::to_string(diskstoMove) + " from " + to_string(first) + " to " + to_string(first) + ": wrong disk insertion";
		return 0;
	}
	count += 1;
	if (diskstoMove > 1 && towers[middle].getSize() > 0)
	{
		count = count + moveDisks(diskstoMove - 1, middle, last, first);
	}
	return count;
}

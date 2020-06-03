#pragma once
#include <vector>
#include "Tower.h"

class Hanoi {
public:
	Hanoi() = delete;
	Hanoi(std::vector<int> disks);

	int calculateSteps()
	{
		return moveDisks(towers[0].getSize(),0,2,1);
	}

	std::string getErrorMsg() {
		return errorMsg;
	}

	const std::vector<int> getResult()
	{
		return towers[2].getDisks();
	}

private:
	int moveDisks(int diskstoMove, int first, int last, int middle);
	Tower towers[3];
	std::string errorMsg;
};


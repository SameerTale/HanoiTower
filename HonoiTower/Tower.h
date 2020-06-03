#pragma once

#include <vector>

class Tower {
public:
	Tower();
	bool add(int disk);
	int removeLast();
	int getSize()
	{
		return (int)disks.size();
	}
	std::vector<int> getDisks() {
		return disks;
	}

private:
	std::vector<int> disks;
};


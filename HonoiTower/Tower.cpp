#include "pch.h"
#include "Tower.h"


Tower::Tower()
{
	disks = std::vector<int>();
}

bool Tower::add(int disk) {
	if (disk <= 0) return false;
	if (disks.size() == 0 || disks.back() > disk)
		disks.push_back(disk);
	else
		return false;
	return true;
}

int Tower::removeLast()
{
	if (disks.size() == 0) return -1;
	int last = disks.back();
	disks.pop_back();
	return last;
}

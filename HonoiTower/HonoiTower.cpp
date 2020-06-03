// HonoiTower.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "Hanoi.h"
#include <assert.h>

using namespace std;

int main()
{
	std::cout << "Hello This is new Hanoi Tower solver!\n" << "Provide array size: ";
	int size;
	std::vector<int> disks;
	cin >> size;
	cout << "Provide disks sizes in descending order:\n";
	for (int i = 0; i < size; i++)
	{
		int disk;
		cin >> disk;
		if (disks.size() > 0)
			assert(disks.back() > disk);
		disks.push_back(disk);
	}
	Hanoi hanoi = Hanoi(disks);
	cout << "Total steps are: " << hanoi.calculateSteps() << "\n";
	cout << "2^n-1: " << to_string(pow(2.0, (double)size)-1) <<"\n";
	cout << "Error Message: " << hanoi.getErrorMsg() << "\n";
	auto output = hanoi.getResult();
	cout << "Result: \n";

	for(int disk : output)
	{
		cout << to_string(disk) << "\n";
	}
	cout << "press any key to exit";
	string r;
	cin >> r;
}


//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

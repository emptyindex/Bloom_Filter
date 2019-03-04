#pragma once
#include <vector>

using namespace std;
#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

class Hash
{
public:
	Hash() //constructor for the class
	{
		for (int  i = 0; i < 100; i++) //for loop that iterates up to the size of array
		{
			cells[i] = false; //sets each index equal to false
		}
	}

	string hash_1(int); //declares first hash function with 1 parameter

	string hash_2(int); //declares second hash function with 1 parameter

	void addToFilter(int input, bool *); //declares add to bloom filter function

	bool checkIfEntered(int, bool *); //declares search method

	bool cells[100]; //declares array of size 100 and type bool
};

#endif // !BLOOM_FILTER_H





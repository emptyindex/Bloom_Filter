// BloomFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "bloomfilter.h" //in order to use bloom filter header
#include <bitset> //in order to use bitset for conversions

using namespace std;

string Hash::hash_1(int input) //first hash function that returns a string value and takes an integer as a parameter
{
	string binary = bitset<8>(input).to_string(); //instantializes string variable set equal to the binary equivalent of input

	string temp; //declares string variable

	for (int i = 0; i < binary.size(); i++) //for loop that iterates through the length of binary
	{
		if (i % 2 != 0) //checks to see if the index of binary is odd
		{
			temp.push_back(binary[i]); //if the index is odd then push the value of that index into the temp variable
		}
	}

	return temp; //return value of temp
}

string Hash::hash_2(int input) //second hash function that returns a string value and takes an integer as a parameter
{
	string binary = bitset<8>(input).to_string();  //instantializes string variable set equal to the binary equivalent of input

	string temp; //declares string variable

	for (int i = 0; i < binary.size(); i++) //for loop that iterates through the length of binary
	{
		if (i % 2 == 0) //checks to see if the index of binary is even
		{
			temp.push_back(binary[i]); //if the index is odd then push the value of that index into the temp variable
		}
	}

	return temp; //return value of temp
}

void Hash::addToFilter(int input, bool * table) //add function that takes 2 parameters, an integer and an array of type bool
{
	string hashed = hash_1(input); //initializes string variable set equal to the hashed function of input (first hash)
	string hashed_2 = hash_2(input); //initializes string variable set equal to the hashed function of input (second hash)

	unsigned long index = bitset<8>(hashed).to_ulong(); //instantializes unsigned long variable set equal to the decimal equivalent of the 1st binary hash
	unsigned long index_2 = bitset<8>(hashed_2).to_ulong(); //instantializes unsigned long variable set equal to the decimal equivalent of the 2st binary hash

	table[index] = true; //sets the index (number found in 1st hash) of table equal to true
	table[index_2] = true; //sets the index (number found in 2st hash) of table equal to true
}

bool Hash::checkIfEntered(int input, bool * table) //search function that takes 2 parameters, an integer and an array of type bool
{
	string hashed = hash_1(input); //initializes string variable set equal to the hashed function of input (first hash)
	string hashed_2 = hash_2(input); //initializes string variable set equal to the hashed function of input (second hash)

	unsigned long index = bitset<8>(hashed).to_ulong(); //instantializes unsigned long variable set equal to the decimal equivalent of the 1st binary hash
	unsigned long index_2 = bitset<8>(hashed_2).to_ulong(); //instantializes unsigned long variable set equal to the decimal equivalent of the 2st binary hash

	if (table[index] == true && table[index_2] == true) //uses if loop to check whether the indexes 1 and 2 are set to true in the table
	{
		return 1; //if they are return 1, or true the item exists
	}

	return 0; //if not return 0, or false the item does not exist
}

int main()
{
	Hash call; //call to hash header
	int input; //declare integer variable

	cout << "Please enter a value to be entered in the bloom filter" << endl; //ask user to input a value
	cin >> input; //reads user input and save into input variable
	call.addToFilter(input, call.cells); //use the call varible to use add method, filling parameters with user input and a call to the table

	cout << "Please enter value to be searched: " << endl; //ask user to input a value
	cin >> input; //reads user input and save into input variable

	bool result = call.checkIfEntered(input, call.cells); //saves the result of search function to a bool variable
	if (result == 1) //checks if the result of the search is true
	{
			cout << "The element: " << input << " exists in the filter" << endl; //if it is, then write to the user that the element exists
	}
	else
	{
			cout << "The element: " << input << " does not exist in the filter" << endl; //if it is not true, write to the user that the element does not exist 
	}

	return 0;
}





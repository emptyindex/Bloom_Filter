// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "table.h" //includes header file

using namespace std;


Hash_Table::Hash_Table() //constructor with call to class in header
{
	table = new Hash * [size]; //instantializes table with the value of size
	for (int i = 0; i < size; i++) //for loop that iterates up to 100 (value of size)
	{
		table[i] = NULL; //sets index of i equal to NULL
	}
}

int Hash_Table::hash_Fun(int key) //hash function with call to class in header
{
	return key % size; //returns mod of key and size
}

void Hash_Table::insert(int key, int value) //insert function with call to header and 2 parameters
{
	int index = hash_Fun(key); //instantializes new variable equal to the hashed value of key

	while (table[index] != NULL && table[index]->key != key) //while loop that checks if the index of table isn't empty and the key isn't equal to key
	{
		index = hash_Fun(index + 1); //sets the value of index equal to the hashed function of index plus 1
	}

	table[index] = new Hash(key, value); //
}

int Hash_Table::search(int key) //search function with call to header with 1 parameter
{
	int index = hash_Fun(key); //instantializes new variable equal to hashed value of key

	while (table[index] != NULL && table[index]->key != key) //while loop that checks if the index of table isn't empty and the key isn't equal to key
	{
		index = hash_Fun(index + 1); //sets the value of index equal to the hashed function of index plus 1
	}

	if (table[index] == NULL) //checks if the index is empty
		return -1; //if it is then return -1
	else //if the index is not empty
		return table[index]->value; //return the value of the index
}
int main()
{
	Hash_Table hash; //variable with call to Header
	int key, value; //2 integer variables 

	cout << "Insert new element value: " << endl; //asks for value
	cin >> value; //sets value equal to whatever was entered by users 

	cout << "Enter new element key: " << endl; //asks for key 
	cin >> key; //sets value equal to whatever was entered

	hash.insert(key, value); //insert the key and value into insert function

	cout << "Enter key of element to be searched: " << endl; //asks for key 
	cin >> key; //sets value equal to whatever was entered

	if (hash.search(key) == -1) //checks is the value of the key was equal to -1
		cout << "Element could not be found at key: " << key << endl; //writes that the element cannot be found
	else //if the element was found
	{ 
		cout << "The element at key: " << key << " is : "; //print the key entered
		cout << hash.search(key) << endl; //print the value at that key location 
	}

	return 0;
}



#include <iostream>
#include <string>

using namespace std;

#pragma once
#ifndef TABLE_H
#define TABLE_H

class Hash 
{
public:

	Hash(int k, int v) //Hash Table constructor with 2 parameters of type int k and v
	{
		key = k; //sets the value of key equal to parameter k
		value = v; //sets the value of value equal to parameter v
	}

	int key; //variable of type integer named key
	int value; //variable of type integer named value
};

class Hash_Table
{
public:
	Hash_Table(); //declares constructor

	void insert(int, int); //declares insert method with 2 parameters

	int search(int); //declares search method with 1 parameter

	int hash_Fun(int); //declares the hash function method with 1 parameter 

	//void remove(int key);

private:
	const int size = 100; //instantiates an integer variable with a value of 100
	Hash * * table; //declares double pointer of type Hash 
};

#endif // !TABLE_H



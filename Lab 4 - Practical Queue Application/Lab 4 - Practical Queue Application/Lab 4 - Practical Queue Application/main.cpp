//
//  main.cpp
//  Lab 4 - Practical Queue Application
//
//  Created by Rachel Vancleave on 11/9/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
	// Variables
	string tempStr;			// Stores a temporary string
	int	wordCount = 0;		// Stores total ammount of words sucessfully copied into the queue
	
	// Objects
	LinkedQueue <string>myQueue;
	ifstream fin;		// Creates a input filestream Object
	
	// Opens file
	fin.open("inputfile.txt");
	if (!fin.is_open())
	{
		cout << "File failed to open." << endl;
		return 1;
	}
	
	/*
    for (int i = 0; i < 10; i++)
    {
		cout << "Input string " << i << ": ";
		cin  >> inputStr;
        myQueue.enqueue(inputStr);
    }*/


	while (fin >> tempStr)
	{
		//fin >> tempStr;
		cout << "input" << endl;
		myQueue.enqueue(tempStr);
		wordCount++;
	}

	for (int i = 0; i < wordCount; i++)
    {
        cout << myQueue.peekFront() << " ";
        myQueue.dequeue();
    }






    // Ends program
    return 0;
}

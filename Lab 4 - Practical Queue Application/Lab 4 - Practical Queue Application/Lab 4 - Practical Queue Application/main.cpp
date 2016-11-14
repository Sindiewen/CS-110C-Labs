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

// Function Prototypes
void ReadFile(LinkedQueue<string> &endNoteQueue, ifstream &fin, ofstream &fout);
void printToFile(LinkedQueue<string> &endNoteQueue, ofstream &fout);

int main()
{
	
	// Variables
	string tempStr;					// Stores a temporary string from the input file
	int endNoteCount = 1;			// Stores a count for how many EndNotes there are in a file
	
	// OPTIONAL: Some text editors don't have text wrapping when the text reaches to the end of the window.
	//	This forces, when a specific count has been met, adds a newline to the file to ensure readability.
	//	Can remove in the base code to allow no text wrapping.
	int whenToAddNewLine = 0;		// Counter of how many string has been entered
	const int newLineCount = 12;	// When to add a newline to the file
	
	size_t ifOpenBraceFound;		// A value to store when a open curly brace has been found
	size_t ifCloseBraceFound;		// A value to store then a closed curly brace has been found
	
	bool bracefound = false;		// If a brace has been found
	
	
	// Class Objects
	LinkedQueue<string> endNoteQueue;				// Creates a queue to store values from the file
	
	ifstream fin;									// Creates a input filestream Object
	ofstream fout ("OutFile.txt", ios::out);		// Creates file output object
	
	
	/* Test Implementation */
	
	
	// Opens file
	fin.open("SampleInputFile.txt");
	if (!fin.is_open())
	{
		cout << "File failed to open." << endl;
		return 1;
	}
	
	// Logic to open from a specified file, print values into a new file,
	// and if any value is inside curly braces, place them into a queue
	// to be printed into the file at a later time
	while (fin >> tempStr)
	{
		
		// Finding a curly brace inside a string
		ifOpenBraceFound = tempStr.find("{");		// Finding a "{"
		ifCloseBraceFound = tempStr.find("}");		// Finding a "}"
		
		// If a open curly brace has been found
		if (ifOpenBraceFound != string::npos)
		{
			// Set the brace found flag to true
			bracefound = true;
		}
		// Else if a closebrace has been found
		else if (ifCloseBraceFound != string::npos)
		{
			// Enque's the close brace into the queue, will be removed later
			endNoteQueue.enqueue(tempStr);
			// Sets the brace found flag to false
			bracefound = false;
		}
		
		
		// Inserting into queue
		if (bracefound == true)
		{
			// Inserts value into the queue
			endNoteQueue.enqueue(tempStr);
		}
		// Prints the values from the old file to the new file
		else
		{
			// If theres a closed curly brace inside the text, replace it with
			// a corresponding int value where you can find the text in the endnotes
			if (ifCloseBraceFound != string::npos)
			{
				// Prints the EndNote value where the closed curly brace was
				tempStr = to_string(endNoteCount);
				fout << "(" << tempStr << ") ";
				
				// Increments the endNoteCount corresponding to how many endNotes there are
				endNoteCount++;
			}
			// Otherwise, just print the line as it to the file
			else
			{
				// Prints the file as is to the new file
				fout << tempStr << " ";
				// Increments when to add a newLine for non-non textwrapping text editors
				whenToAddNewLine++;
			}
			
			// Adds a newline character after a set number of strings have been added to the file
			if (whenToAddNewLine == newLineCount)
			{
				// Sets the whenToAddNewLine to 0
				whenToAddNewLine = 0;
				// Adds a newline to the file
				fout << "\n";
			}
		}
	}

	
	/*  Adds the values from the queue into the file */

	whenToAddNewLine = 0;	// Resets when to add a new line
	endNoteCount = 1;
	
	fout << "\n\nEndnotes:\n";
	
	while (!endNoteQueue.isEmpty())
	{
		tempStr = endNoteQueue.peekFront();	// Adds the frontmost value to a temp string
		
		// Finds curly braces inside string
		ifOpenBraceFound = tempStr.find("{");		// Finding a "{"
		ifCloseBraceFound = tempStr.find("}");		// Finding a "}"
		
		// If a open curly brace has been found
		if (ifOpenBraceFound != string::npos)
		{
			// Adds newline
			fout << "\n";
			// Replaces the current tempStr to the endNote count
			tempStr = to_string(endNoteCount);
			// Prints endnote count to the file
			fout << "(" << tempStr << ")";
			
			// Empties the temp string
			tempStr = "";
			
			// Increments endNote Count
			endNoteCount++;
			// Resets when to add a newLine
			whenToAddNewLine = 0;
		}
		
		// If a closed curly brace has been found
		else if (ifCloseBraceFound != string::npos)
		{
			// Replace the closed curly brace with an empty character
			tempStr = " ";
		}
		
		// Prints the tempString to the file
		fout << tempStr << " ";					// Adds the value inside the temp string into the file
		endNoteQueue.dequeue();					// Dequeues the queue
		whenToAddNewLine++;						// WHen to add a newLine get incremented
		
		// Adds a newline character after a set number of strings have been added to the file
		if (whenToAddNewLine == newLineCount)
		{
			// Resets whenToAddNewLine to 0
			whenToAddNewLine = 0;
			// Adds a newline to the file
			fout << "\n";
		}
	}




    // Ends program
    return 0;
}



void ReadFile(LinkedQueue<string> &endNoteQueue, ifstream &fin, ofstream &fout)
{
	
	
	
}
void printToFile(LinkedQueue<string> &endNoteQueue, ofstream &fout)
{
	
	
}


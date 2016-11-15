/*
 * @name	Rachel Vancleave
 * @date	11/9/16
 * @class	CS 100C
 * 
 * @Summary This program uses a pointer based queue. Using the Linked Queue, this program sortes
 * an input file, prints any data that is not inside a curly brace into an output file 'OutFile.txt.
 * Any data inside the curly brace gets placed inside a Queue to be printed into EndNotes
 * at the bottom of the output file 'OutFile.txt'
 *
 * NOTE: Some text editors don't handle text wrapping well, or at all. I implemented a functionality
 * to the text output to print the text in a pseudo-text wrapping matter to avoid long single lines
 * of text for many text editors.
 * 
 */

#include <iostream>
#include <fstream>
#include "LinkedQueue.h"

using namespace std;

// Function Prototypes
bool sortFile			(LinkedQueue<string> &endNoteQueue, ifstream &fin, ofstream &fout);
void printEndNotes		(LinkedQueue<string> &endNoteQueue, ofstream &fout);

int main()
{
	
	// Class Objects
	LinkedQueue<string> endNoteQueue;				// Creates a queue to store values from the file
	
	ifstream fin;									// Creates a input filestream Object
	ofstream fout ("OutFile.txt", ios::out);		// Creates file output object and a file to open from (if none exsists)
	
	// Starting program
	
	if (sortFile(endNoteQueue, fin, fout))
	{
		// SampleInput.txt Successfully opened
		printEndNotes(endNoteQueue, fout);
		
		// End program
		cout << "File sorting completed successfully. Closing program..." << endl;
		return 0;
	}

	// Program ends, if reached here, program ended unsuccesfully
	return 0;
	
}


// Sorts the input file - Returning a bool
//		The program opens the SampleInput.txt and sorts out the text outside of any curly braces and
//	any text inside curly braces. Text inside curly braces gets placed inside a queue to be printed
//	out into EndNotes at the bottom of the file. Sorted and numbered acordingly. Where the curly braced
//	text was gets replaced by a number in parenthesis as the rest of the outside text gets
//	printed to the file
//
//	@param	Passing in the string Linked Queue endNoteQueue, and the fileInput and fileOutput objects as references
//
//	@pre	endNoteQueue is a queue of strings, fin and fout are file input and file output stream objects respectivley
//
//	@post	This function reads from the 'SampleInput.txt'. It reads any text from the outside of the curly braces
//	and prints them to the output file. If it finds open curly braces, the program will store the text
//	that was inside the curly braces into a queue, replacing the curly braced text with a number in parens.
//	It will continue doing that untill the program cannot find any more text to read.
//			The program will return a bool if the program successfully opens the file.
//	False if file did not open successfully, True if file opened successfully
bool sortFile(LinkedQueue<string> &endNoteQueue, ifstream &fin, ofstream &fout)
{
	// Variables
	string tempStr;					// Stores a temporary string from the input file
	int endNoteCount = 1;			// Stores a count for how many EndNotes there are in a file

	size_t ifOpenBraceFound;				// A value to store when a open curly brace has been found
	size_t ifCloseBraceFound;				// A value to store then a closed curly brace has been found
	
	bool bracefound = false;				// If a brace has been found
	
	
	// OPTIONAL: Some text editors don't have text wrapping when the text reaches to the end of the window.
	//	When a specific count has been met, adds a newline to the file to ensure readability.
	int			whenToAddNewLine = 0;		// Counter of how many string has been entered
	const int	newLineCount = 12;			// When to add a newline to the file
	
	
	// Implementation of sorting the input file //
	
	// Opening file to read from
	cout << "Opening SampleInput.txt..." << endl;
	
	fin.open("SampleInput.txt");
	
	if (!fin.is_open())
	{
		// Returns false, program unsuccessfully ran
		cout << "SampleInput.txt failed to open. Ensure theres a file called 'SampleInput.txt' to read from."
			<< "\n Closing program..."<< endl;
		return false;
	}
	
	cout << "SampleInput.txt successfully opened. " << endl;
	
	//	Logic to open from the specified file, print values into a new file,
	// and if any value is inside curly braces, place them into a queue
	// to be printed into the file at a later time
	
	// Loops file input untill the file has been successfully looped through
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
	// Fuction sucessfully ran
	return true;
}


// printEndNotes prints the EndNotes of the input file
//		The program prints the stores EndNotes inside the endNoteQueue that was stored.
//	It will peek the top most value in the queue and store it into tempStr. Once stored, it will check
//	to ensure that the EndNotes will be sorted correctly. Starting from the top of the queue.
//	If it happens to find a string that has a curly brace, it will take out the opening brace,
//	replace it with a number in parenthesis and align the line on that line. Once it reaches the
//	close curly brace, the program will replace that with white space and move onto the next brace.
//	It will repeat untill the queue is empty.
//
//	@param	Passing the LinkedQueue endNoteQueue and the output File Stream object as reference.
//
//	@pre	endNoteQueue is a queue of strings, fout is the File Output Stream object
//
//	@post	This function read from the EndNoteQueue and sorts out each of the lines in Curly Braces
//	into numbered rows that correspond to the places in the  output file where the curly braces used to be,
//	where there are now parenthesis with numbers.
void printEndNotes(LinkedQueue<string> &endNoteQueue, ofstream &fout)
{
	// Function Variables
	string tempStr;					// Stores a temporary string from the input file
	int endNoteCount = 1;			// Stores a count for how many EndNotes there are in a file
	
	// OPTIONAL: Some text editors don't have text wrapping when the text reaches to the end of the window.
	//	This forces, when a specific count has been met, adds a newline to the file to ensure readability.
	//	Can remove in the base code to allow no text wrapping.
	int whenToAddNewLine = 0;		// Counter of how many string has been entered
	const int newLineCount = 12;	// When to add a newline to the file
	
	size_t ifOpenBraceFound;		// A value to store when a open curly brace has been found
	size_t ifCloseBraceFound;		// A value to store then a closed curly brace has been found
	
	/*  Adds the values from the queue into the file */
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
}














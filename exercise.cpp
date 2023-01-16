/*
 * File: malloc Exercise (Week 1 Data Structures: SENG 1050)
 * Programmer: Nat Smolcic
 * Date: Jan 09 2023
 */

/* Write a program gets a C-style string from the user and prints it.
   Before getting the string, ask the user how long it is. 
   Then allocate a block of memory that is that length + 1 more byte for the null-termination. 
   Get the string using that block and fgets().
   Print the string.
   Free the memory once completely done.
   Remember to error-check in case you run out of memory.*/

#include <stdlib.h>
#include <iostream>
#include <ctype.h>

using namespace std;

#define kMaxSize 1000

int main() {

	// ask user how long their string will be using fgets()
	cout << "How many characters long is your string? Please include whitespaces and punctuation in this count. Write the count in digits not in words." << endl;
	
	char length[kMaxSize] = "\0";
	fgets(length, kMaxSize, stdin);

	// convert string to an integer
	int stringLength = atoi(length);

	cout << "You inputted a length of " << length << "Now, we are allocating the memory for your string." << endl;

	// allocate enough memory for the string and check that the calloc() worked
	char* pBlock = NULL;
	if ((pBlock = (char *) calloc((int) stringLength + 1, 4)) == NULL) {
		cout << "Error: Unable to allocate memory for input string of length " << stringLength << endl;
		return 0;
	}

	cout << "Allocation of memory successful." << endl;

	// get C-style string from user input using fgets() and error check in case memory overflows
	cout << "Please type your string of length " << stringLength << endl;

	if (fgets(pBlock, stringLength + 1, stdin) == NULL) {
		cout << "Error: Not enough memory was allocated for the string inputted." << endl;
		return 0;
	}

	// print the user inputted string
	cout << "Your string: " << pBlock << endl;

	// free the memory
	free(pBlock);
	return 0;
}

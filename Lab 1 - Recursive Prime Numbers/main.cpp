/*
 * @name Rachel Vancleave
 * @date 9/9/16
 * @class CS 110C
 *
 * @summary This program recursively prints the prime factorization of a number
 * the user inputs.
 */

#include <iostream>

using namespace std;

// Function Prototypes
void showFactors(int numberToFactor, int factor);

int main()
{
    // Variables
    int numberToFactor; // Stores the number the user wants to factor out

    // Stores number the user wants to factor out
    cout << "Enter a number you want to get the prime factors of or type 0 to exit:\n> ";
    cin  >> numberToFactor;

    while (numberToFactor > 0)
    {
        // Print the prime factors of a number
        cout << "The prime factors of " << numberToFactor << " are: ";
        showFactors(numberToFactor, 2);

        cout << endl << endl;

        // Stores number the user wants to factor out
        cout << "Enter a number you want to get the prime factors of or type 0 to exit:\n> ";
        cin  >> numberToFactor;
    }



    // Ends program
    return 0;
}

// Recursive function:
    // Iterates and solves a number to see how many prime factorizations you can get.
    // @param Takes the number the user wants to factor out, and the base factor to start.
    // @pre none.
    // @post Recursively calls the function numerous times until the base case is met. Where number to factor = 1.
void showFactors(int numberToFactor, int factor)
{
    // Base Case
        // If number to factor = 1 when divided by factor, end the recursion.
    if (numberToFactor / factor == 1)
    {
        // No point to go any farther, print last factor, end recursion
        cout << numberToFactor << " ";
        return;
    }

    // Prints the prime factors of the number
    if (numberToFactor % factor == 0)
    {
        // recursively calls function, divides number by the factor
        showFactors(numberToFactor / factor, factor);

        // Prints the prime factors after the recursion call
        cout << factor << " ";
    }

   // Iterates factor by 1, Ensures the possibilities of getting to the lowest factor
    else if (numberToFactor % factor != 0)
    {
        // Recursively calls function, adds 1 to factor
        showFactors(numberToFactor, factor + 1 );
    }

    return;
}
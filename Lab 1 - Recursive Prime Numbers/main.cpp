#include <iostream>

using namespace std;

// Function Prototypes
void showFactors(int numberToFactor, int factor);

int main()
{

    int numberToFactor;

    // Stores number the user wants to factor out
    cout << "Enter a number you want to factor out: ";
    cin  >> numberToFactor;

    // Sets display up for prime factors
    cout << "Number  Factor" << endl;
    cout << numberToFactor << endl;

    showFactors(numberToFactor, 2);
}

// Recursive function:
    // Iterates and solves a number to see how many prime factorizations you can get
void showFactors(int numberToFactor, int factor)
{
    // Base Case - If factor hits 13
    if (factor >= 13 || numberToFactor <= 1)
    {
        // No point to go any farther, ends recursion
        return;
    }

    // Prints the prime factors of the number
    if (numberToFactor % factor == 0)
    {
        // Prints current number and prime factor
        cout << numberToFactor / factor << "    " << factor << endl;

        // recursively calls function, divides number by the factor
        showFactors(numberToFactor / factor, factor);

    }
        // Iterates factor by 1, Ensures the possibilities of getting to the lowest factor
    else if (numberToFactor % factor != 0)
    {
        //cout << "Factor + 1" << endl;
        // Recursively calls function, adds 1 to factor
        showFactors(numberToFactor, factor + 1);
    }

    return;
}
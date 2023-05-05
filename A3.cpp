// James Sieben 200455325
// CS 310 A3

#include <iostream>
using namespace std;

void arrayCycle(int, int, int, int[]);
void arrayPrint(int, int[]);

// Both global variables are used for printing
const int OUTPUT_ROW_MAX = 10;
int printTally = 0;

int main() 
{
    int k = 0, n = 0;

    // Get the value for n and check that it's at least 2.
    while (n < 2)
    {
        cout << "Please enter the value for n: ";
        cin >> n;
        if (n < 2)
            cout << "Sorry, n cannot be less than 2.\n";
    }

    // Get the value for k and check that it's at least 2 and at least n.
    while (k < 2 || k < n)
    {
        cout << "Please enter the value for k: ";
        cin >> k;
        if (k < 2)
            cout << "Sorry, k cannot be less than 2.\n";
        else if (k < n)
            cout << "Sorry, k cannot be less than n.\n";
    }

    // Create a dynamically sized array of format {0,0,0,...,0}
    int* x;
    x = new int[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;

    // Call function arrayCycle with the value of 0 for m 
    cout << "Solutions:\n";
    arrayCycle(k, 0, n, x);

    cout << "\n\n";

    delete[] x;
    return 0;
}

// Function arrayCycle cycles through all array possibilities and checks if they solve the problem
// Variables: k for desired sum, m is a pointer to an array element, n is the number of terms, and x is the array.
// Returns nothing
void arrayCycle(int k, int m, int n, int x[])
{
    // If the pointer m is past the last array element, return.
    if (m == n)
    {
        return;
    } else if (k == 0) {   // If desired sum has been reached, print the current array and return.
        arrayPrint(n, x);
        return;
    }

    // The for loop will reset the array element pointed to by m to 0. 
    // It will then recursively call arrayCycle with k decreased by i, and the pointer m moved to the next array element.
    // This method should prevent the program from checking unnecessary combinations.
    for (int i = 0; i < k; i++)
    {
        x[m] = i;
        arrayCycle(k-i, m+1, n, x);
    }
    // After the loop has cycled through, set element m to the current value of k. Then, print the current array and reset element to 0.
    x[m] = k;
    arrayPrint(n, x);
    x[m] = 0;
}

// Function arrayPrint prints array solutions to the problem
// Takes an int variable for n, and an int array for x
// Returns nothing
void arrayPrint(int n, int x[])
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
            cout << x[i] << "}";
        else
            cout << x[i] << ",";
    }
    cout << ", ";

    printTally++;
    if (printTally == OUTPUT_ROW_MAX)
    {
        cout << "\n";
        printTally = 0;
    }

    return;
}
//James Sieben 200455325
//CS310 A5

#include <iostream>
using namespace std;

int read();
void genStrings(int[], int, int);
void printString(int[], int);

int main()                               // Driver function
{
    int n = read();
    int *arr = new int[n];
    genStrings(arr, n, 0);
    delete []arr;

    return 0;
}

int read()                               // Function to take a user value for n
{
    int n;
    do
    {
        cout << "What is n? ";
        cin >> n;
        if (n < 3)
            cout << "n must be at least 3\n";
    } while (n < 3);

    return n;
}

void genStrings(int arr[], int n, int i) // Function generates a permutation of length n and checks for two 0s in a row
{                                        // arr is the vector representing permutations, n is its size, i is a counter to watch for the end of arr
    if (i == n)                    // If statement is used so the permutation of the string will only be printed when it is length n
    {
        int j = 0, cnt = 0;
        for (j; j<i; j++)          // Loop checks if string is valid and calls printString function if it is
        {
            if (arr[j] == 0)       // Increase the count if element is 0
                cnt++; 
            else if (arr[j] == 1)  // Reset the count if element is 1
                cnt = 0;
            if (cnt == 2)          // If two 0s are found in a row, break from the loop and do not print
                break;
            else if (j == i-1)     // Print the string after all elements have been checked
                printString(arr, n);
        }
        return;
    }
    arr[i] = 0;              // Set 0 at position i and generate remaining elements
    genStrings(arr, n, i + 1);
    arr[i] = 1;
    genStrings(arr, n, i + 1);     // Set 1 at position i and generate remaining elements
}

void printString(int arr[], int n)       // Prints the accepted permutation
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return;
}
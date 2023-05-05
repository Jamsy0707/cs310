//James Sieben 200455325
//CS310 A4

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int  bubbleSort(vector<vector<int>> &, int, int);
void push(vector<int> &, int);
int  read (char);
void shuffle(vector<int> &);
void twoDPush (vector<vector<int>> &, vector<int> &);

int main()                                                      //Driver function
{
    int i, j, comp, avg, n = read('n'), m = read('m');  //Variable declarations
    vector<int> arr = {1,2,3,4,5};                      //Initialized to the smallest possible array
    vector<vector<int>> twoDArr;                        //Vector of vectors to hold every permutation

    push(arr, n);                                       //Build the vector arr so it has n elements
    for (i = 0; i < m; i++)                             //Loop m times for each permutation
    {
        shuffle(arr);                                   //Creates a new permutation
        twoDPush(twoDArr, arr);                         //Saves permutation to vector twodarr
    }

    avg = (comp = bubbleSort(twoDArr, m, n)) / m;       //Sort each permutation and return comparison total, then calculate the average number of comparisons

    cout << "\nThe total number of comparisons is: " << comp 
         << "\nThe average number of comparisons is: " << avg
         << "\n\n";
         
    return 0;
}
int bubbleSort(vector<vector<int>> &twoDArr, int m, int n)      //Sort permutations using bubble sort. Returns total comparisons.
{
    int comp = 0;                                           //Variable to count the number of comparisons
    for (int i = 0; i < m; i++)                             //Loop rows
        for (int j = 0; j < n; j++)                         //Loop columns
            for (int k = 0; k < n - j - 1; k++)             //Loop again for comparisons
                if (twoDArr[i][k] > twoDArr[i][k + 1])
                {
                    comp++;                                 //Increase comparison counter
                    swap(twoDArr[i][k], twoDArr[i][k + 1]); //Swap elements
                }

    return comp;
}
void push (vector<int> &arr, int n)                             //Function to build the array
{
    for (int i = 6; i <= n; i++)  //Increase array size to match n
        arr.push_back(i);         //Push each int to the back of the vector

    return;
}
int read (char var)                                             //Function to read values for n and m from user. 
{
    int num;
    if (var == 'n')                                 //Read value for n
        do
        {
            cout << "What is n? ";
            cin >> num;
            if (num < 5)
                cout << "n must be at least 5\n";
        } while (num < 5);                          //Loop until a valid m is entered
    else if (var == 'm')                            //Read value for m
        do
        {
            cout << "What is m? ";
            cin >> num;
            if (num < 10)
                cout << "m must be at least 10\n";
        } while (num < 10);                         //Loop until a valid m is entered

    return num;                                     //Return either n or m
}
void shuffle(vector<int> &arr)                                  //Creates a random permutation of the array
{
    random_shuffle(arr.begin(), arr.end());  //random_shuffle creates a random permutation

    return;
}
void twoDPush (vector<vector<int>> &twoDArr, vector<int> &arr)  //Function to push each permutation into a vector of vectors
{
    twoDArr.push_back(arr);  //push_back pushes the new permutation to the back of the vector of permutations

    return;
}
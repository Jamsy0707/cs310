// James Sieben 200455325
// CS 310 A2

#include <iostream>
#include <math.h>
using namespace std;

int** createBoard(int);
int** setTile (int**, int, int);
int** placeTiles (int**, int, int, int, int, int, int);
void build (int**, int, int, int);
void print (int**, int);
void destroyBoard(int**, int);

// Global variable used to differentiate triominoes
int tileCount = 0;

int main()
{
    int n, x, y;
    int** board;

    cout << "What is the size of the board? (2^n, n>=3) ";
    cin >> n;
    if (n < 3)
    {
        cout << "Sorry, n needs to be at least 3." << endl;
        return 0;
    }

    int size = pow(2, n);

    board = createBoard(size);

    // Read user input for blank tile location
    cout << "What is the x coordinate? ";
    cin >> x;
    cout << "What is the y coordinate? ";
    cin >> y;
    cout << endl;
    if (x > size-1 || y > size-1)
    {
        cout << "Sorry, the empty tile must be within (0,0) and (" << size-1 << "," << size-1 << ")." << endl;
        return 0; 
    }

    board = setTile(board, x, y);   // Set the blank tile
    build(board, size, 0, 0);       // Build the board around the blank tile
    print(board, size);             // Print the board
    destroyBoard (board, size);     // Deallocate memory

    return 0;
}

// createBoard creates a dynamic array of user defined size. Returns a pointer to the board.
int** createBoard (int size)
{
     // Initialize the board w/ dynamic mem
    int** board = new int*[size];
    for (int i = 0; i < size; i++)
        board[i] = new int[size];

    // Set the board to 0
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            int board[i][j] = {0};

    return board;
}

// setTile changes the value of a user selected tile to -1. Returns a pointer to the board.
int** setTile (int** board, int x, int y)
{
    // Set user defined tile as -1
    board[x][y] = -1;

    return board;
}

// Places a triomino and increases the tileCount. Returns pointer to board.
int** placeTiles (int** board, int a, int b, int c, int d, int e, int f)
{
    // Increase the tile count to differentiate different tiles.
    tileCount++;

    // Place the triomino
    board[a][b] = tileCount;
    board[c][d] = tileCount;
    board[e][f] = tileCount;

    return board;
}

// build is a recursive function that splits the board into four and places triominoes
// x and y are the upper-left coordinates of the board being worked on
void build (int** board, int size, int x, int y)
{
    int xhole, yhole;

    // Base case where the board is 2 x 2
    if (size == 2)
    {
        tileCount++;    // Increase the tile number so that a unique tile can be placed
        for (int x1 = 0; x1 < 2; x1++)
            for (int y1 = 0; y1 < 2; y1++)
                if (board[x+x1][y+y1] == 0) // If the spot does not contain the user selected spot
                    board[x+x1][y+y1] = tileCount; // Place a part of the triomino
        return;
    }else{
        // Determine the coordinates of the hole
        for (int x1 = x; x1 < (x + size); x1++)
            for (int y1 = y; y1 < (y + size); y1++)
                if (board[x1][y1] != 0)
                {
                    xhole = x1;
                    yhole = y1;
                }
    }

    /*
    The following steps split the board into four smaller boards and searches for 
    It then calls the function placeTiles to place a triomino so that each quadrant
    of the board / mini-board has a one non-zero spot. This process keeps happening
    until the base case is reached. The trick is to place the triomino in the center 
    of the board / mini-board so that it points away from the non-zero spot.
    */

    // Top Left Quadrant:
    if (xhole < x + size/2 && yhole < y + size/2) // Compares the hole coords to the Q1 boundaries
        placeTiles (board, x+(size/2), y+(size/2)-1, x+(size/2), y+(size/2), x+(size/2)-1, y+(size/2));

    // Top Right Quadrant:
    else if (xhole < x + size/2 && yhole >= y + size/2) // Compares the hole coords to the Q2 boundaries
        placeTiles (board, x+(size/2), y+(size/2)-1, x+(size/2), y+(size/2), x+(size/2)-1, y+(size/2)-1);

    // Bottom Left Quadrant:
    else if (xhole >= x + size/2 && yhole < y + size/2) // Compares the hole coords to the Q3 boundaries
        placeTiles (board, x+(size/2)-1, y+(size/2), x+(size/2), y+(size/2), x+(size/2)-1, y+(size/2)-1);

    // Bottom Right Quadrant:
    else if (xhole >= x + size/2 && yhole >= y + size/2) // Compares the hole coords to the Q4 boundaries
        placeTiles (board, x+(size/2)-1, y+(size/2), x+(size/2), y+(size/2)-1, x+(size/2)-1, y+(size/2)-1);

    // Recursively divide the board into 4 new boards of equal size so that each new board has one non-zero spot
    build (board, size/2, x, y);                   // Top left
    build (board, size/2, x+(size/2), y);          // Top right
    build (board, size/2, x, y+(size/2));          // Bottom left
    build (board, size/2, x+(size/2), y+(size/2)); // Bottom right
}

// Prints the board
void print (int** board, int size)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
            cout << board[x][y] << "   ";
        cout << endl;
    }
    cout << endl;
}

// Deallocates memory
void destroyBoard (int** board, int size)
{
    for (int i = 0; i < size; i++)
        delete board[i];
    delete board;
}
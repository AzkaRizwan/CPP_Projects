#include <iostream>

using namespace std;

const int SIZE = 9;

/* ---------- Function Prototypes ---------- */
void inputGrid(int grid[SIZE][SIZE]);
void printGrid(int grid[SIZE][SIZE]);
bool findEmptyCell(int grid[SIZE][SIZE], int &row, int &col);
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int grid[SIZE][SIZE]);

/* ---------- Input Grid ---------- */
void inputGrid(int grid[SIZE][SIZE])
{
    cout << "Enter Sudoku grid (9x9). Use 0 for empty cells:\n";

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] < 0 || grid[i][j] > 9)
            {
                cout << "Invalid input. Only numbers 0–9 allowed.\n";
                exit(1);
            }
        }
    }
}

/* ---------- Print Grid ---------- */
void printGrid(int grid[SIZE][SIZE])
{
    cout << "\nSolved Sudoku:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
            cout << "---------------------\n";

        for (int j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0 && j != 0)
                cout << "| ";

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

/* ---------- Find Empty Cell ---------- */
bool findEmptyCell(int grid[SIZE][SIZE], int &row, int &col)
{
    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false; // No empty cell → solved
}

/* ---------- Check if Safe ---------- */
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{

    // Row check
    for (int x = 0; x < SIZE; x++)
        if (grid[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < SIZE; x++)
        if (grid[x][col] == num)
            return false;

    // 3x3 Box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

/* ---------- Backtracking Solver ---------- */
bool solveSudoku(int grid[SIZE][SIZE])
{

    int row, col;

    // If no empty cell → puzzle solved
    if (!findEmptyCell(grid, row, col))
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {

        if (isSafe(grid, row, col, num))
        {

            grid[row][col] = num; // Place number

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; // Backtrack
        }
    }

    return false; // Trigger backtracking
}

/* ---------- Main Function ---------- */
int main()
{

    int grid[SIZE][SIZE];

    inputGrid(grid);

    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "\nNo solution exists for this Sudoku.\n";
    }

    return 0;
}
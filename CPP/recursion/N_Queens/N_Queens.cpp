#include <iostream>
#include <vector>

// Function to print the bord
void printBoard(std::vector<std::vector<int>> &board, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1)
            {
                std::cout << 'Q' << ' ';
            }
            else
            {
                std::cout << '_' << ' ';
            }
        }
        std::cout << std::endl;
    }
}

// Function for checking valid squares.
bool canBePlaced(std::vector<std::vector<int>> &board, int i, int j, int n)
{

    // Vertical check.
    for (int v = 0; v < i; ++v)
    {
        if (board[v][j] == 1)
        {
            return false;
        }
    }

    // Copy variables for checking the right upper diagonal.
    int u = i, v = j;

    // Upper left diagonal check.
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        --i;
        --j;
    }

    // Upper right diagonal.
    while (u >= 0 && v < n)
    {
        if (board[u][v] == 1)
        {
            return false;
        }
        --u;
        ++v;
    }

    // Return true for possibility.
    return true;
}

// Main recursive function.
bool N_Queens(std::vector<std::vector<int>> &board, int n, int row)
{
    // --> base case
    // When row becomes equal to n
    // means all queens have been placed in the right manner.
    if (row == n)
    {
        // Print the first possible way.
        printBoard(board, n);
        // Endl for printing the next possible board
        // std::cout << std::endl;
        // Return true for returning to main.
        return true;
        // Return false for printing all possibilities.
        // return false;
    }

    // --> recursive case
    for (int column = 0; column < n; ++column)
    {
        // Check if the queen can be placed at the ith row and jth column.
        if (canBePlaced(board, row, column, n))
        {
            // Mark that place as 1.
            board[row][column] = 1;
            // Check for further positions.
            bool remaining_positions = N_Queens(board, n, row + 1);
            if (remaining_positions)
            {
                // If queens can be placed in the remaining positions
                // it means the placing of queens can proceed further.
                // return true
                return true;
            }
            else
            {
                // If queens cannot be placed further in the right way
                // backtrack to the previous position.
                board[row][column] = 0;
            }
        }
    }

    return false;
}

int main()
{

    int n = 0;
    // Input Size of the chessboard
    // No of queens will be the same as size n.
    std::cin >> n;
    if (n <= 3)
    {
        std::cout << "No solution exists for n = " << n << std::endl;
    }
    // 2D vector for storing board having size max size of nXn.
    // First create a column vector of size n.
    std::vector<int> column(n);
    // Create Row vectors and fill rows with columns.
    std::vector<std::vector<int>> board(n, column);

    // Function call for
    // Arguments passed are : 2D vector board
    //                      : No of queens
    //                      : Starting row.
    N_Queens(board, n, 0);

    return 0;
}

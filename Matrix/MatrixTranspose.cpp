#include <iostream>
using namespace std;

int main() {
    int row, column;
    cout << "Enter rows and columns of matrix: ";
    cin >> row >> column;

    int a[row][column], transpose[column][row];
    
    cout << "\nEnter elements of matrix:\n";
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j) {
            cout << "Element a[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a[i][j];
        }

    cout << "\nEntered Matrix:\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }

    // Compute transpose
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < column; ++j)
            transpose[j][i] = a[i][j];

    cout << "\nTranspose of Matrix:\n";
    for (int i = 0; i < column; ++i) {
        for (int j = 0; j < row; ++j)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    return 0;
}

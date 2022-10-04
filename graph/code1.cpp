// Code for Adjacency Matrix
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int main()
{
    int v;
    v = 5;
    int mat[v][v];
    memset(mat, 0, sizeof(mat));
    // adding edges
    // 0-1 0-4 1-3 3-4 2-3

    mat[0][1] = mat[1][0] = 1;
    mat[0][4] = mat[4][0] = 1;
    mat[1][3] = mat[3][1] = 1;
    mat[3][4] = mat[4][3] = 1;
    mat[2][3] = mat[3][2] = 1;

    // if graph is undirected then mat is symmetric otherwise it depends on edges

    cout << "CHECK MATRIX: " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
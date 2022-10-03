// 79. Word Search
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>> &board, string &word, int index, int x, int y) {

    if(index == word.length()) {
        return true;
    }

    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '*') 
        return false;

    if(board[x][y] != word[index])
        return false;

    char temp = board[x][y];
    board[x][y] = '*';

    if  (
            solve(board, word, index+1, x-1, y) ||
            solve(board, word, index+1, x+1, y) ||
            solve(board, word, index+1, x, y-1) ||
            solve(board, word, index+1, x, y+1)
        ) {
            return true;
        }

    board[x][y] = temp;
       
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    
    for(int i=0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(solve(board, word, 0, i, j))
                return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'}, 
        {'S','F','C','S'}, 
        {'A','D','E','E'}
    };
    string word = "ABCB";

    cout << exist(board, word) << endl;

    return 0;
}

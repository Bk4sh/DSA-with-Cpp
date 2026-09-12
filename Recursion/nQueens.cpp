#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    //Horizontal
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    //Vertical
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    //left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    //Right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board, int n, int row) {
    if (row == n) {
        for (string val : board) {
            cout << val << endl;
        }
        cout << "---------" << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, n, row+1);
            board[row][j] = '.';
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    nQueens(board, n, 0);
    return 0;
}
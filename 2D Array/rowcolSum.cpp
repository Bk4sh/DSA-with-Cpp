#include <iostream>
using namespace std;

int maxRowSum(int matrix[][3], int rows, int cols) {
    int maxRowSum = INT_MIN;

    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }

    return maxRowSum;
}

int maxColSum(int matrix[][3], int rows, int cols) {
    int maxColSum = INT_MIN;

    for (int i = 0; i < cols; i++) {
        int colSum = 0;
        for (int j = 0; j < rows; j++) {
            colSum += matrix[j][i];
        }
        maxColSum = max(maxColSum, colSum);
    }

    return maxColSum;
}

int main() {
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int rows = 4, cols = 3;

    cout << maxRowSum(matrix, rows, cols) << endl;
    cout << maxColSum(matrix, rows, cols) << endl;

    return 0;
}
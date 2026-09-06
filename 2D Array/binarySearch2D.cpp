#include <iostream>
#include <vector>
using namespace std;

pair<int, int> searchInRow(vector<vector<int>> &matrix, int target, int row) {
    int cols = matrix[0].size();
    int start = 0, end = cols-1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if (target == matrix[row][mid]) {
            return {row, mid};
        } else if (target > matrix[row][mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return {-1, -1};
}

pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target) {
    int rows = matrix.size(), cols = matrix[0].size();
    int startRow = 0, endRow = rows-1;

    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow)/2;

        if (target >= matrix[midRow][0] && target <= matrix[midRow][cols-1]) {
            return searchInRow(matrix, target, midRow);
        } else if (target <= matrix[midRow][0]) {
            endRow = midRow - 1;
        } else {
            startRow = midRow + 1;
        }
    }

    return {-1, -1};
}

pair<int, int> searchMatrixx(vector<vector<int>> &matrix, int target) {                 //another type
    int rows = matrix.size(), cols = matrix[0].size();
    int startRow = 0, endCol = cols-1;
    
    while (startRow < rows && endCol >= 0) {
        if (target == matrix[startRow][endCol]) {
            return {startRow, endCol};
        } else if (target < matrix[startRow][endCol]) {
            endCol--;
        } else {
            startRow++;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 20;

    pair<int, int> result = searchMatrix(matrix, target);
    cout << result.first << ", " << result.second << endl;

    vector<vector<int>> matrixx = {{1, 4, 7, 11}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int targett = 16;

    pair<int, int> resultt = searchMatrixx(matrixx, targett);
    cout << resultt.first << ", " << resultt.second << endl;

    return 0;
}
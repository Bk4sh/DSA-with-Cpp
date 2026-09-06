#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> ans;

    int startRow = 0, endRow = rows-1, startCol = 0, endCol = cols-1;

    while ((startRow <= endRow) && (startCol <= endCol)) {
        for (int i = startCol; i <= endCol; i++) {
            ans.push_back(matrix[startRow][i]);
        }

        for (int j = startRow+1; j <= endRow; j++) {
            ans.push_back(matrix[j][endCol]);
        }

        for (int i = endCol-1; i >= startCol; i--) {
            if (startRow == endRow) {
                break;
            }
            ans.push_back(matrix[endRow][i]);
        }

        for (int j = endRow-1; j >= startRow+1; j--) {
            if (startCol == endCol) {
                break;
            }
            ans.push_back(matrix[j][startCol]);
        }

        startRow++; endRow--; startCol++; endCol--;
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {  {1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15, 16}};

    vector<int> ans = spiralOrder(matrix);

    for (int val: ans) {
        cout << val << " ";
    }

    return 0;
}
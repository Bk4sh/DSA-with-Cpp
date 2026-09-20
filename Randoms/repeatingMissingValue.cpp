#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

pair<int, int> findRepeatedAndMissingValue(vector<vector<int>> &matrix) {
    unordered_set<int> s;
    int n = matrix.size();
    int repeating, missing;
    int expSum = 0, actualSum = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            actualSum += matrix[i][j];

            if (s.find(matrix[i][j]) != s.end()) {
                repeating = matrix[i][j];
            }

            s.insert(matrix[i][j]);
        }
    }

    expSum = (n*n) * ((n*n) + 1) / 2;
    missing = expSum + repeating - actualSum;

    return {repeating, missing};
}

int main() {
    vector<vector<int>> matrix = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};

    pair<int, int> ans = findRepeatedAndMissingValue(matrix);
    cout << ans.first << ", " << ans.second << endl;

    return 0;
}
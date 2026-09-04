#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxWater = 0;
    int start = 0, end = heights.size()-1;

    while (start < end) {
        int width = end - start;
        int height = min(heights[start], heights[end]);
        int currWater = width * height;
        maxWater = max(maxWater, currWater);

        heights[start] < heights[end] ? start++ : end--;
    }

    cout << "Maximum water " << maxWater;
    return 0;
}
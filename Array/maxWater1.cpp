#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxWater = 0;

    for (int i = 0; i < heights.size(); i++) {
        for (int j = i+1; j < heights.size(); j++) {
            int width = j-i;
            int height = min(heights[i], heights[j]);
            int currWater = height * width;
            maxWater = max(maxWater, currWater);
        }
    }

    cout << "Maximum water " << maxWater;
    return 0;

}
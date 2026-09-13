#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortArray(vector<int> &nums) {
    int count0 = 0, count1 = 0, count2 = 0;             //count 0s, 1s, 2s

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }

    int idx = 0;
    for (int i = 0; i < count0; i++) {
        nums[idx] = 0;
        idx++;
    }

    for (int i = 0; i < count1; i++) {
        nums[idx] = 1;
        idx++;
    }

    for (int i = 0; i < count2; i++) {
        nums[idx] = 2;
        idx++;
    }
}

int main() {
    vector<int> nums = {2, 1, 0, 1, 1, 0, 2, 2};

    sortArray(nums);

    for (int val : nums) {
        cout << val << " ";
    }

    return 0;
}
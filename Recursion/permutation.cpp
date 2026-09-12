#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPermutation(vector<int> &nums, int idx) {
    if (idx == nums.size()) {
        for (int val : nums) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getPermutation(nums, idx+1);
        swap(nums[idx], nums[i]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    getPermutation(arr, 0);

    return 0;
}
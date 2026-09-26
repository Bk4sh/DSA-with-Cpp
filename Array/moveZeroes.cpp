#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;

    while(j < nums.size()) {
        if (nums[j] == 0) {
            j++;
        } else {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }

    for (int num : nums) {
        cout << num << " ";
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    return 0;
}
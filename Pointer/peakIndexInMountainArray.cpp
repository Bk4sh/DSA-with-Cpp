#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> nums) {
    int start = 1, end = nums.size()-2;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid-1] < nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {0, 3, 9, 8, 5, 2};

    cout << peakIndexInMountainArray(nums);

    return 0;
}
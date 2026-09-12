#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target) {
    int start = 0, end = nums.size()-1;

    while (start <= end) {
        int mid = start + (end - start) / 2; //Optimzed mid formula

        if (target > nums[mid]) {
            start = mid + 1;
        } else if (target < nums[mid]) {            
            end = mid - 1;
        } else {
            return mid;
        }
    }
    
    return -1;
}

int recBinarySearch(vector<int> nums, int target, int start, int end) {
    
    if (start <= end) {
        int mid = start + (end - start) / 2;

        if (target > nums[mid]) {
            return recBinarySearch(nums, target, mid+1, end);
        } else if (target < nums[mid]) {
            return recBinarySearch(nums, target, start, mid-1);
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int target = 5, start = 0, end = nums.size()-1;

    cout << binarySearch(nums, target) << endl;
    cout << recBinarySearch(nums, target, start, end);

    return 0;
}
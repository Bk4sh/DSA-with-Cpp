#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> nums, int n, int m, int mid) {
    int painters = 1, time = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > mid) {
            return false;
        }

        if (time + nums[i] <= mid) {
            time += nums[i];
        } else {
            painters++;
            time = nums[i];
        }
    }

    return painters > m ? false : true; 
}

int minTimetoPaint(vector<int> nums, int n, int m) {
    if (m > n) {
        return -1;
    }

    int maxTime = 0, maxVal = nums[0];
    for (int i = 0; i < n; i++) {
        maxTime += nums[i];
        maxVal = max(maxVal, nums[i]);
    }

    int start = maxVal, end = maxTime, ans = -1;
    while (start <= end) {
        int mid = start + (end-start)/2;

        if (isPossible(nums, n, m, mid)) {
            ans = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {40, 30, 10, 20};
    int n = 4, m = 2;
    cout << minTimetoPaint(nums, n, m) << endl;
    
    vector<int> nums1 = {11, 15, 5, 10};
    int n1 = 4, m1 = 2;
    cout << minTimetoPaint(nums1, n1, m1);

    return 0;
}
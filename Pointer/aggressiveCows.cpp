#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> nums, int n, int c, int mid) {
    int cows = 1, laststallpos = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] - laststallpos >= mid) {
            cows++;
            laststallpos = nums[i];
        }

        if (cows == c) {
            return true;
        }
    }

    return false;
}

int getLargestMinDistance(vector<int> nums, int n, int c) {
    sort(nums.begin(), nums.end());

    int start = 1, end = nums[n-1] - nums[0];       //distance range
    int ans = -1;

    while(start <= end) {
        int mid = start + (end-start)/2;

        if (isPossible(nums, n, c, mid)) {
            ans = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 8, 4, 9};
    int n = 4, c = 3;
    cout << getLargestMinDistance(nums, n, c) << endl;

    vector<int> nums1 = {1, 5, 2, 7, 10, 14, 20};
    int n1 = 7, c1 = 5;
    cout << getLargestMinDistance(nums1, n1, c1);

    return 0;
}
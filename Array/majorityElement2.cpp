#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {                                                //optimized O(nlogn)
    vector<int> nums = {1, 2, 2, 1, 1, 1};

    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];

    for (int i=1; i<nums.size(); i++) {
        
        if (nums[i] == nums[i-1]) {
            freq++;
        } else {
            freq = 1;
            ans = nums[i];
        }

        if (freq > nums.size()/2) {
            cout << "Majority element is " << ans;
            return 0;
        }
    }

    return 0;
}
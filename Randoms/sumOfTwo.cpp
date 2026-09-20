#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

pair<int, int> bruteForce(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        int first = nums[i];
        
        for (int j = i+1; j < nums.size(); j++) {
            int sum = first + nums[j];

            if (target == sum) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

pair<int, int> betterApproach(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int start = 0, end = nums.size()-1;

    while (start < end) {
        int sum = nums[start] + nums[end];

        if (sum == target) {
            return {start, end};
        } else if (sum > target) {
            end--;
        } else {
            start++;
        }
    }

    return {-1, -1};
}

pair<int, int> optimizedApproach(vector<int> &nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        int first = nums[i];
        int second = target - first;

        if (m.find(second) != m.end()) {
            return {i, m[second]};
            break;
        }

        m[first] = i;
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {5, 2, 11, 7, 15};
    vector<int> nums1 = {5, 2, 11, 7, 15};
    int target = 9;

    pair<int, int> result = bruteForce(nums, target);
    cout << result.first << ", " << result.second << endl;

    pair<int, int> result1 = betterApproach(nums, target);
    cout << result1.first << ", " << result1.second << endl;

    pair<int, int> result2 = optimizedApproach(nums1, target);
    cout << result2.first << ", " << result2.second << endl;

    return 0;
}
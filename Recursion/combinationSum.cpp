#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<vector<int>> s;

void helper(vector<int> &nums, int target, vector<int> &combination, int idx, vector<vector<int>> &ans) {
    if (idx == nums.size() || target < 0) {
        return;
    }

    if (target == 0) {
        if (s.find(combination) == s.end()) {
            ans.push_back(combination);
            s.insert(combination);
        }
        return;
    }

    combination.push_back(nums[idx]);
    helper(nums, target-nums[idx], combination, idx+1, ans);    //single inclusion of each nums
    helper(nums, target-nums[idx], combination, idx, ans);      //multiple inclusion of nums
    
    combination.pop_back();
    helper(nums, target, combination, idx+1, ans);              //exclude the num             
}

vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<int> combination;
    vector<vector<int>> ans;

    helper(nums, target, combination, 0, ans);

    return ans;
}

int main() {
    vector<int> nums = {2, 3, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum(nums, target);
    for (vector<int> val : result) {
        for (int el : val) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}
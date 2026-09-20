#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> optimizedApproach(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i+1; j < n;) {
            int k = j+1, l = n-1;

            while (k < l) {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];

                if (sum < 0) {
                    k++;
                } else if (sum > 0) {
                    l--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[l-1]) k++;
                }
            }

            j++;
            while (j < n && nums[j] == nums[j-1]) j++;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-2, -1, -1, 1, 1, 2, 2};
    vector<vector<int>> result = optimizedApproach(arr);
    
    for (vector<int> val : result) {
        for (int el : val) {
            cout << el << " ";
        }
        cout << endl;
    }
}
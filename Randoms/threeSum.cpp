#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {
    vector<vector<int>> ans;
    set<vector<int>> s;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            for (int k = j+1; k < arr.size(); k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());

                    if (s.find(triplet) == s.end()) {
                        s.insert(triplet);
                        ans.push_back(triplet);
                    }
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> optimizedApproach(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = n-1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while (j < k && nums[j] == nums[j-1]) j++;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(arr);

    for (vector<int> val : result) {
        for (int el : val) {
            cout << el << " ";
        }
        cout << endl;
    }

    vector<int> arr1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = optimizedApproach(arr1);
    
    for (vector<int> val : result1) {
        for (int el : val) {
            cout << el << " ";
        }
        cout << endl;
    }

}
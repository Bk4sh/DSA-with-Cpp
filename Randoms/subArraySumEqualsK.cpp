#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int bruteForce(vector<int> &arr, int target) {
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == target) count++;
        }
    }

    return count;
}

int optimizedApproach(vector<int> &arr, int target) {
    int count = 0;
    vector<int> prefixSum(arr.size(), 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
    }

    unordered_map<int, int> m;
    for (int j = 0; j < arr.size(); j++) {
        if (prefixSum[j] == target) count++;

        int val = prefixSum[j] - target;
        if (m.find(val) != m.end()) {
            count += m[val];
        }

        if (m.find(prefixSum[j]) == m.end()) {
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }
    
    return count;
}

int main() {
    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int target = 33;
    cout << bruteForce(arr, target) << endl;

    vector<int> arr1 = {9, 4, 0, 20, 3, 10, 5};
    cout << optimizedApproach(arr1, target) << endl;
    return 0;
}
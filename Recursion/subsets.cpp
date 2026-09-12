#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if (i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);
    
    ans.pop_back();
    printSubsets(arr, ans, i+1);
}

void printSubsetsDuplicates(vector<int> &arr, vector<int> &ans, int i) {    
    if (i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[i]);
    printSubsetsDuplicates(arr, ans, i+1);
    
    ans.pop_back();

    int idx = i+1;
    while (idx < arr.size() && arr[idx] == arr[idx-1]) idx++;

    printSubsetsDuplicates(arr, ans, idx);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    printSubsets(arr, ans, 0);

    vector<int> arr1 = {1, 2, 2};
    sort(arr1.begin(), arr1.end());
    vector<int> ans1;
    printSubsetsDuplicates(arr1, ans1, 0);

    return 0;
}
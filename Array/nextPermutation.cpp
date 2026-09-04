#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums) {
    int pivot = -1;
    for (int i = nums.size()-2; i >= 0; i--) {          //finding the pivot place value
        if (nums[i] < nums[i+1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size()-1; i > pivot; i--) {       //swap the pivot value with the next larger number
        if (nums[pivot] < nums[i]) {
            swap(nums[pivot], nums[i]);
            break;
        }
    }
    
    int i = pivot+1, j = nums.size()-1;                 //reverse the rest part after the pivot place
    while (i <= j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void nextPermutationinBuilt(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 6, 5, 4};

    nextPermutation(nums);
    for (int val : nums) {
        cout << val << " ";
    }

    cout << endl; 

    vector<int> A = {1, 2, 3, 4, 5, 6};
    nextPermutation(A);
    for (int val : A) {
        cout << val << " ";
    }

    cout << endl;

    vector<int> B = {6, 5, 4, 3, 2, 1};
    nextPermutation(B);
    for (int val : B) {
        cout << val << " ";
    }

    cout << endl;
    
    vector<int> C = {2, 1, 3};
    nextPermutationinBuilt(C);
    for (int val : C) {
        cout << val << " ";
    }

    return 0;
}
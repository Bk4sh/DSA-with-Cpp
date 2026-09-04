#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};          //Brute Force Approach O(n^2)

    int maxSum = 0;
    for (int start=0; start<n; start++) {
        int currSum = 0;

        for (int end=start; end<n; end++) {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    cout << "Maximum subarray sum: " << maxSum;
    return 0;
}
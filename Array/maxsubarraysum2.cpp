#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};              //Kadane's Algorithm O(n)

    int maxSum = 0, currSum = 0;
    for (int i=0; i<7; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    cout << "Maximum subarray sum: " << maxSum;
    return 0;
}
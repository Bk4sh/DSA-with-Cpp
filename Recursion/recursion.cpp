#include <iostream>
#include <vector>
using namespace std;

void printNums(int n) {
    if (n == 1) {
        cout << "1\n";
        return;
    }

    cout << n << " ";
    printNums(n-1);
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}

int sumOfN(int n) {
    if (n == 1) {
        return 1;
    }

    return n + sumOfN(n-1);
}

int fibonacciSeries(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacciSeries(n-1) + fibonacciSeries(n-2);
}

bool isSorted(vector<int> &arr, int n) {
    if (n == 0 || n == 1) {
        return true;
    }

    return (arr[n-1] >= arr[n-2]) && isSorted(arr, n-1);
}

int binarySearch(vector<int> &arr, int target, int start, int end) {
    int mid = start + (end-start)/2;

    if (start <= end) {
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearch(arr, target, mid+1, end);
        } else {
            return binarySearch(arr, target, start, mid-1);
        }
    }

    return -1;
}

int main() {
    printNums(20);

    cout << factorial(4) << endl;

    cout << sumOfN(5) << endl;

    for (int i = 0; i <= 8; i++){
        cout << fibonacciSeries(i) << " ";
    }
    cout << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    cout << isSorted(arr, arr.size()) << endl;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9, start = 0, end = nums.size()-1;
    cout << binarySearch(nums, target, start, end) << endl;

    return 0;
}
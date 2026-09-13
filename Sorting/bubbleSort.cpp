#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool isSwap = false;                    // Track whether any swap happened in this pass. If no swap occurs, the array is already sorted — no need to continue

        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;                  // Mark that a swap occurred in this pass
            }
        }

        if (!isSwap) {                          // If isSwap is still false, no elements were swapped in this entire pass
            return;                             // This means every element is already in its correct position
        }                                       // So we exit early instead of running the remaining unnecessary passes
    }                                           // Example: arr = {1, 2, 3, 4, 5} — first pass makes zero swaps → return immediately
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int smallestIndex = i;

        for (int j = i+1; j < n; j++) {
            if(arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }

        swap(arr[i], arr[smallestIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {4, 2, 5, 1, 3}, n = 5;

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
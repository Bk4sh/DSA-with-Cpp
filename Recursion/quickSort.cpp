#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivotPartition(vector<int> &arr, int start, int end) {
    int idx = start-1, pivot = arr[end];
    
    for (int j = start; j <= end-1; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int pivotIdx = pivotPartition(arr, start, end);

        quickSort(arr, start, pivotIdx-1); //left part
        quickSort(arr, pivotIdx+1, end);   //right part
    }
}

int main() {
    vector<int> arr = {8, 7, 20, 12, 31, 35};
    quickSort(arr, 0, arr.size()-1);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
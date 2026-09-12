#include <iostream>
#include <vector>
using namespace std;

void sorting(vector<int> &arr, int start, int mid, int end) {       //sorting and merging. backtracking
    vector<int> temp;
    int i = start, j = mid+1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    //elements that are left in sub-arrays after comparision
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    //merging the element and storing it in the original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx+start] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = start + (end-start)/2;

        mergeSort(arr, start, mid); //left part
        mergeSort(arr, mid+1, end); //right part

        sorting(arr, start, mid, end);
    }
}

int main() {
    vector<int> arr = {8, 12, 7, 20, 35};
    mergeSort(arr, 0, arr.size()-1);
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
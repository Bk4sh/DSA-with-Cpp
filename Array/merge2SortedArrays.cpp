#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(vector<int> A, vector<int> B) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) {
            ans.push_back(A[i]);
            i++;
        } else {
            ans.push_back(B[j]);
            j++;
        }
    }

    // Add remaining elements of A and B if any
    while (i < A.size()) {
        ans.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        ans.push_back(B[j]);
        j++;
    }

    for (int val : ans) {
        cout << val << " ";
    }
}

void mergeSortedArrayss(vector<int> A, vector<int> B, int m, int n) {
    int i = m-1, j = n-1, idx = m+n-1;

    while (i >= 0 && j >= 0) {
        if (A[i] >= B[j]) {
            A[idx] = A[i];
            i--;
            idx--;
        } else {
            A[idx] = B[j];
            j--;
            idx--;
        }
    }

    while (j >= 0) {
        A[idx] = B[j];
        j--;
        idx--;
    }

    for (int val : A) {
        cout << val << " ";
    }
}

int main() {
    vector<int> A = {3, 5, 9};
    vector<int> B = {2, 5, 6};

    mergeSortedArrays(A, B);

    cout << endl;

    vector<int> C = {3, 5, 9, 0, 0, 0};
    vector<int> D = {2, 5, 6};
    int m = 3, n = 3;

    mergeSortedArrayss(C, D, m, n);

    return 0;
}
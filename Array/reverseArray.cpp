#include <iostream>
using namespace std;

void reverseArray(int arr[], int sz) {
    int start=0, end=sz-1;

    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = 10;

    reverseArray(arr, sz);
    
    for(int i=0; i<sz; i++) {
        cout<<arr[i]<<endl;
    }

    return 0;
}
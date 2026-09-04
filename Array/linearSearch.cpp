#include <iostream>
using namespace std;

int linearSearch(int arr[], int sz, int target) {
    for(int i=0; i<sz; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; //-1 means invalid
}

int main() {
    int arr[] = {4, 2, 7, 6, 10, 8, 5};
    int sz = 7;
    int target = 10;

    cout<<linearSearch(arr, sz, target)<<endl;

    return 0;
}
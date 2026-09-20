#include <iostream>
using namespace std;

void minOfarray(int arr[], int sz) {
    int min = arr[0];
    int max = arr[0];
    int max_i = 0;
    int min_i = 0;

    for(int i=0; i<5; i++) {
        if (arr[i]<min) {
            min_i = i;
        }
    }

    for(int i=0; i<5; i++) {
        if (arr[i]>max) {
            max_i = i;
        }
    }

    swap(arr[max_i], arr[min_i]);
}


int main() {

    int arr[] = {30, 9, 11, 25, 8};
    int sz = 5;
    
    minOfarray(arr, sz);

    for(int i=0; i<sz; i++) {
        cout<<arr[i]<<endl;
    }

    return 0;
}
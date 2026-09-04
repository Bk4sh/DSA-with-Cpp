#include <iostream>
using namespace std;

void minOfarray(int arr[], int sz) {
    int min = arr[0];

    for(int i=0; i<5; i++) {
        if (arr[i]<min) {
            min = arr[i];
        }
    }

    cout<<"smallest in array "<<min;
}

void maxOfarray(int arr[], int sz) {
    int max = arr[0];

    for(int i=0; i<5; i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }

    cout<<"largest in array "<<max;
}

int main() {

    int arr[] = {9, 6, 7, 2, 8};
    int sz = 5;
    
    minOfarray(arr, sz);
    cout<<endl;
    maxOfarray(arr, sz);

    return 0;
}
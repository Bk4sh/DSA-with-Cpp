#include <iostream>
using namespace std;

void uniqueValue(int arr[], int sz) {

    for (int i=0; i<sz; i++) {
        bool isUnique = true;

        for (int j=0; j<sz; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            cout<<arr[i]<<" ";
        }
    }
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 4, 5};
    int sz = 7;

    uniqueValue(arr, sz);

    return 0;
}
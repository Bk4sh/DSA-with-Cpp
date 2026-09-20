#include <iostream>
using namespace std;

void powOftwo(int n) {
    int i = n;

    if (i<=0) {
        cout<<"Not power of 2";
    }

    while(i%2==0) {
        i = i/2;
    }

    if (i==1) {
        cout<<"Power of 2";
    }else {
        cout<<"Not power of 2";
    }
}

int main() {
    powOftwo(24);

    return 0;
}
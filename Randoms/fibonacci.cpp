#include <iostream>
using namespace std;

void fibonacci(int n) {
    int a=0, b=1;
    for(int i=0; i<n; i++) {
        if(i==0){
            cout<<a<<" ";
        }
        else if(i==1) {
            cout<<b<<" ";
        }
        else {
            int c = a+b;
            a = b;
            b = c;
            cout<<c<<" ";
        }
    }
}

int main() {
    fibonacci(20);
}
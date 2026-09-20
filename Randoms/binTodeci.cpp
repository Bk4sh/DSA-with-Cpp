#include <iostream>
using namespace std;

int binTodeci(int n) {
    int ans=0, pow=1;
    
    while(n>0) {
        int lastdigit = n%10;
        ans += lastdigit*pow;
        pow = pow*2;
        n = n/10;
    }

    return ans;
}

int main() {
    cout<<binTodeci(110);
    return 0;
}
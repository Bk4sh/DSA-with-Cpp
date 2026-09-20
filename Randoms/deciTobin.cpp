#include <iostream>
using namespace std;

int deciTobin(int n) {
    int ans=0, pow=1;
    
    while(n>0) {
        int remainder = n%2;
        ans += remainder*pow;
        pow = pow*10;
        n = n/2; 
    }
    
    return ans;
}

int main() {
    cout<<deciTobin(10);
    return 0;
}
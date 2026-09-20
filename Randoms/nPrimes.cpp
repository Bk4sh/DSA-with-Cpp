#include <iostream>
using namespace std;

bool checkPrime(int n) {
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
            break;
        }
    }
    return true;
}

void nPrimes(int n) {
    for(int i=2; i<=n; i++){
       if(checkPrime(i)){
        cout<<i<<" ";
       }

    }
}

int main() {
    nPrimes(50);

    return 0;
}
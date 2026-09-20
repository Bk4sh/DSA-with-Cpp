#include <iostream>
using namespace std;

int factorial_n(int n) {
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    int fact_n = factorial_n(n);
    int fact_r = factorial_n(r);
    int fact_nr = factorial_n(n-r);

    return fact_n/(fact_r * fact_nr);
}

int main() {
    int n=6, r=3;
    cout<<factorial_n(n)<<endl;
    cout<<factorial_n(r)<<endl;
    cout<<factorial_n(n-r)<<endl;

    cout<<nCr(n, r)<<endl;

    return 0;
}
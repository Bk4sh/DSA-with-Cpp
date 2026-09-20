#include <iostream>
using namespace std;

bool isArmstrong(int n) {
    int m = n;
    int sumCubes = 0;

    while (m != 0) {
        int digit = m % 10;
        sumCubes += (digit * digit * digit);
        m = m / 10;
    }

    return n == sumCubes;
}

int main() {
    int n = 371;

    if (isArmstrong(n)) {
        cout << n << " is a armstrong number";
    } else {
        cout << n << " is not a armstrong number";
    }

    return 0;
}
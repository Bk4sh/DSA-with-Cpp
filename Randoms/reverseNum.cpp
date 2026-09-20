#include <iostream>
using namespace std;

int reverseNum(int n) {
    int ans = 0;

    while (n != 0) {
        int digit = n % 10;

        if ((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
            return 0;
        }

        ans = (ans * 10) + digit;
        n = n / 10;
    }

    return ans;
}

bool palindromeNum(int n) {
    if (n < 0) return false;

    int revNum = reverseNum(n);

    return (n == revNum);
}

int main() {
    cout << reverseNum(123) << endl;
    cout << palindromeNum(121);
    return 0;
}
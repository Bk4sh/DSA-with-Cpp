#include <iostream>
#include <algorithm>
using namespace std;

bool isAlphanumeric(char ch) {
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }

    return false;
}

bool isPalindrome(string s) {
    int start = 0, end = s.length()-1;

    while (start < end) {
        if (!isAlphanumeric(s[start])) {
            start++;
            continue;
        }

        if (!isAlphanumeric(s[end])) {                      //isalnum(ch) builtin function
            end--;
            continue;
        }

        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    string s = "Ac3?e3c&a";

    cout << isPalindrome(s);

    return 0;
}
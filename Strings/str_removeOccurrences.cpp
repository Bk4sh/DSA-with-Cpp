#include <iostream>
#include <algorithm>
using namespace std;

string removeOccurrence(string s, string p) {
    while ((s.length() > 0) && (s.find(p) < s.length())) {
        s.erase(s.find(p), p.length());
    }

    return s;
}

int main() {
    string s = "daabcbbabccabcdab";
    string p = "abc";

    cout << removeOccurrence(s, p);

    return 0;
}
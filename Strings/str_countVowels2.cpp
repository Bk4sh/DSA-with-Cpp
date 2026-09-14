#include <iostream>
#include <set>
using namespace std;

int main() {
    string s = "Welcome to the jungle";
    int count = 0;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);

        if (vowels.find(c) != vowels.end()) {
            count++;
        }
    }

    cout << "Number of vowels " << count << endl;

    return 0;
}
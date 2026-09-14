#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word1 = "listen";
    string word2 = "silent";

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    if (word1 == word2) {
        cout << "Anagram" << endl;
    } else {
        cout << "Not anagram" << endl;
    }

    return 0;
}
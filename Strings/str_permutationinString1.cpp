#include <iostream>
#include <unordered_map>
using namespace std;

bool isFreqSame(unordered_map<char, int> freq1, unordered_map<char, int> freq2) {
    if (freq1.size() != freq2.size()) return false;

    for (auto it : freq1) {
        if ((freq2.find(it.first) == freq2.end()) || (freq2[it.first] != it.second)) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> freq;
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i]]++;
    }

    int windSize = s1.length();

    for (int i = 0; i < s2.length(); i++) {
        int windIdx = 0, idx = i;
        unordered_map<char, int> windFreq;

        while ((windIdx < windSize) && idx < s2.length()) {
            windFreq[s2[idx]]++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq)) {
            return true;
        }
    }
    return false;
}

int main() {
    // contains uppercase, lowercase and special characters
    string s1 = "aB!";
    string s2 = "eid!Baooo";

    cout << checkInclusion(s1, s2);  // output: 1 ("!Ba" is a permutation of "aB!")
    return 0;
}
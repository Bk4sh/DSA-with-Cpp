#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string copy = s;
    reverse(copy.begin(), copy.end());
    return s == copy;
}

void helper(string s, vector<string> &partition, vector<vector<string>> &ans) {
    if (s.size() == 0) {
        ans.push_back(partition);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i+1);
         if (isPalindrome(part)) {
            partition.push_back(part);
            helper(s.substr(i+1), partition, ans);
            partition.pop_back();
         }
    }
}

vector<vector<string>> getPalindrome(string s) {
    vector<string> partition;
    vector<vector<string>> ans;

    helper(s, partition, ans);
    return ans;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = getPalindrome(s);
    for (vector<string> substr : result) {
        for (string ch : substr) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
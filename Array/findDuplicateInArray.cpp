#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int> &arr) {
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) != s.end()) {
            return arr[i];
        }
        s.insert(arr[i]);
    }

    return -1;
}

int findDuplicatee(vector<int> &arr) {              //slow-fast approach
    int slow = arr[0], fast = arr[0];

    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    vector<int> arr = {3, 2, 3, 1, 4};
    cout << findDuplicate(arr) << endl;
    cout << findDuplicatee(arr) << endl;

    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6};
    int n = 10;

    map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    for (auto c : m) {
        cout << c.first << "=" << c.second << " ";
    }

    return 0;
}
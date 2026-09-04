#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};          //vector functions
    for (int val : vec) {                       //size, push_back, pop_back, front, back, at
        cout << val << endl;
    }

    return 0;
}
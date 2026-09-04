#include <iostream>
#include <vector>
using namespace std;

void reverseVector(vector<int> &vec) {
    int start = 0, end = vec.size()-1;

    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    reverseVector(nums);

    for (int val : nums) {
        cout << val << endl;
    }

    return 0;
}
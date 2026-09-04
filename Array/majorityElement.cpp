#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 2, 1, 1, 1};          //Brute force

    for (int val : nums) {
        int freq = 0;

        for (int el : nums) {
            if (val == el) {
                freq++;
            }
        }

        if (freq > nums.size()/2) {
            cout << "Majority Element is " << val;
            return 0;
        }
    }
    return 0;
}
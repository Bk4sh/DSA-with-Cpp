#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &vec) {                   //If you don’t want to modify but also avoid copying:
    int ans = 0;                                       //void func(const vector<int> &vec)
                                                        
    for (int val : vec) {                              //^ represents XOR. 
        ans = ans ^ val;
    }

    return ans;
}

int main() {
    vector<int> vec = {4, 2, 1, 2, 1};
    cout << singleNumber(vec)<< endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

//int bruteForce(vector<int> &heights) {
//    int ans = 0;
    
//    for (int i = 0; i < heights.size(); i++) {
        
//    }
//}

int optimalApproach1(vector<int> &heights) {
    vector<int> lmax(heights.size(), 0);
    vector<int> rmax(heights.size(), 0);
    int ans = 0;
    
    lmax[0] = heights[0];
    rmax[heights.size()-1] = heights[heights.size()-1];

    for (int i = 1; i < heights.size(); i++) {
        lmax[i] = max(lmax[i-1], heights[i]);
    }
    for (int i = heights.size()-2; i >= 0; i--) {
        rmax[i] = max(rmax[i+1], heights[i]);
    }

    for (int i = 0; i < heights.size(); i++) {
        ans += min(lmax[i], rmax[i]) - heights[i];
    }

    return ans;
}

int twoPointerApproach(vector<int> &heights) {
    int ans = 0;
    int leftPointer = 0, rightPointer = heights.size()-1;
    int leftMax = 0, rightMax = 0;

    while (leftPointer < rightPointer) {
        leftMax = max(leftMax, heights[leftPointer]);
        rightMax = max(rightMax, heights[rightPointer]);

        if (leftMax < rightMax) {
            ans += leftMax - heights[leftPointer];
            leftPointer++;
        } else {
            ans += rightMax - heights[rightPointer];
            rightPointer--;
        }
    }

    return ans;
}

int main() {
    vector<int> heights = {4, 2, 0, 3, 2, 5};

    cout << optimalApproach1(heights) << endl;
    cout << twoPointerApproach(heights) << endl;

    return 0;
}
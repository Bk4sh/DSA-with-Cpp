#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> nums, int n, int m, int mid) {     // Checks if it's possible to allocate books such that no student gets more than 'mid' pages. Returns true if allocation is possible within 'm' students, false otherwise
    int students = 1, pages = 0;                            // Start with 1 student and 0 pages read so far               

    for (int i = 0; i < n; i++) {
        if (nums[i] > mid) {                                // If a single book has more pages than allowed limit, allocation is impossible
            return false;
        }

        if (pages + nums[i] <= mid) {                       // If adding this book doesn't exceed the limit, give it to the current student
            pages += nums[i];
        } else {
            students++;                                     // Otherwise, assign a new student and start fresh with current book
            pages = nums[i];
        }
    }

    return students > m ? false : true;                     // If required students exceed available students, this 'mid' value won't work
}

int allocateBooks(vector<int> nums, int n, int m) {
    if (m > n) {                                             // Edge case: more students than books — some students get nothing, return -1
        return -1;
    }

    int sum = 0;                                            
    for (int i = 0; i < n; i++) {                           // Calculate total pages (this will be the maximum value of our binary search range)
        sum += nums[i];
    }

    int start = 0, end = sum, ans = -1;                     // Binary search between 0 and total sum of pages
    while (start <= end) {                                  // 'start' = 0 (minimum possible max pages), 'end' = sum (one student reads everything)
        int mid = start + (end-start)/2;                    // Candidate for maximum pages a student can read

        if (isValid(nums, n, m, mid)) {
            ans = mid;                                      // This works! Try to minimize further (go left)
            end = mid-1;
        } else {
            start = mid+1;                                  // Doesn't work, need a higher page limit (go right)
        }
    } 

    return ans;
}

int main() {
    vector<int> nums = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocateBooks(nums, n, m) << endl;

    vector<int> nums1 = {15, 17, 20};
    int n1 = 3, m1 = 2;
    cout << allocateBooks(nums1, n1, m1);    

    return 0;
}
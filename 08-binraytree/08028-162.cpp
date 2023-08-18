/*
 * leetcode 162
 * find peak element
 *
 * a peak element is an element that is strictly greater than its neighbors.
 * 
 * nums[i] != nums[i+1] for all valid i
 * that means all elements are unique and different
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // binary search
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        while (left < right) {
            mid = (left+right)/2;
            if (nums[mid] > nums[mid+1])
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

int main(){
    int a[] = {1, 2, 3, 1};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {1, 2, 1, 3, 5, 6, 4};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;

    if (2 == s.findPeakElement(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (5 == s.findPeakElement(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

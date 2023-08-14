/*
 * leetcode 215
 * K-th largest element in an array
 *
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// all elements in a set must be unique
// multiset will sort automatically
// every time put a number into the multiset
// if the size of multiset exceeds K, it will remove the smallest
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(s.begin());
        }
        return *s.begin();
    }
};


class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

int main() {
    int a[] = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    //
    Solution2 s;

    if (s.findKthLargest(v1, k1)==5) {
        cout << "Test1 OK" << endl;
    } else {
        cout << "Test1 failed" << endl;
    }

    return 0;
}

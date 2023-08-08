/*
 * leetcode 26
 * remove duplicates from the ordered array
 * return the length of the array after removal
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};

int main() {
    int a[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;
    if( 5 == s.removeDuplicates(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}

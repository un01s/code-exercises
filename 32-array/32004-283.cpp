/*
 * leetcode 283
 * move zeroes to the end of array
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while(fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
    void moveZeroes(vector<int>& nums) {
        int p = removeElement(nums, 0);
        // change the remaining to zeroes at the end
        for(; p < nums.size(); p++) {
            nums[p] = 0;
        }
    }
};

void printV(vector<int>& v) {
    if (v.empty()) return;

    cout << "vector: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    int a[] = {0, 1, 4, 0, 2};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;

    printV(v1);
    s.moveZeroes(v1);
    printV(v1);

    return 0;
}

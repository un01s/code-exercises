/*
 * leetcode 2811
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        return false;
    }
};

int main() {
    int a[] = {2, 2, 1};
    int m1 = 4;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {2, 1, 3};
    int m2 = 5; // false
    vector<int> v2(b, a+sizeof(b)/sizeof(int));
    int c[] = {2, 3, 3, 2, 3};
    int m3 = 6;
    vector<int> v3(c, a+sizeof(c)/sizeof(int));

    return 0;
}

/*
 * leetcode 2540
 * minimum common values
 *
 */

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        for (; p1 < n1 && p2 < n2;) {
            int x = nums1[p1], y = nums2[p2];
            if (x == y)
                return x;
            else if (x > y)
                p2++;
            else
                p1++;
        }
        return -1;
    }
};


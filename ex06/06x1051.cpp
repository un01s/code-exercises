/*
 * leetcode 1051
 * height checker
 *
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> a = heights;
        sort(a.begin(), a.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); i++)
            if (a[i] != heights[i])
                cnt++;
        return cnt;
    }
};


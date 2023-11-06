/*
 * leetcode 2923
 *
 */

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            bool bad = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i]) bad = 1;
            }
            if (!bad) return i;
        }
        return -1;
    }
};


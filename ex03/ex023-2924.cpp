/*
 * leetcode 2924
 *
 */

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> cnt(n);
        for (auto v : edges) {
            cnt[v[1]]++;
        }
        
        int ans = -1;
        int x= 0;
        for (int i = 0; i < n; i++) if (cnt[i] == 0) {
            ans = i;
            x++;
        }
        
        if (x == 1) return ans;
        return -1;    
    }
};

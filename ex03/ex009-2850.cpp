/*
 * Q3
 */

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> v1, v2;
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (grid[i][j]) {
                    for (int k=1; k<grid[i][j]; ++k) {
                        v1.emplace_back(i, j);
                    }
                } else {
                    v2.emplace_back(i, j);
                }
            }
        }
        int ans=10000000;
        sort(v2.begin(), v2.end());
        do {
            int cur=0;
            for (int i=0; i<v1.size(); ++i)
                cur+=abs(v1[i].first-v2[i].first)+abs(v1[i].second-v2[i].second);
            ans=min(ans, cur);
        } while(next_permutation(v2.begin(), v2.end()));
        return ans;
    }
};


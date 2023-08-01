/*
 * leetcode 77
 * combinations
 * 
 * Given two integers n and k, return all possible combinations of k numbers 
 * chosen from the range [1, n].
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

class Solution {
public:
    void helper(vector<vector<int> >& res, vector<int>& out, int level, int k, int n) {
        if(out.size() == k) {
            res.push_back(out); 
            return;
        }
        
        for(int i = level; i <= n; i++) {
            out.push_back(i);
            helper(res, out, i+1, k, n);
            out.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> out;

        helper(res, out, 1, k, n);
        return res;    
    }
};



/*
 * leetcode 57
 * insert interval
 *
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0];
        int r = newInterval[1];
        int sz = intervals.size(), p = 0;
        vector<vector<int>> res;

        // append the intervals before the new intervals
        while(p < sz && intervals[p][1] < l) {
            res.push_back(intervals[p++]);
        }

        // check if the current position of the original interval overlaps
        // with the new interval
        if (p < sz && intervals[p][0] <= r) {
            l = min(l, intervals[p][0]);
            while(p < sz && intervals[p][0] <= r) p++;
            r = max(intervals[p-1][1], r);
        }
        res.push_back({l, r});

        // append the rest of the intervals
        while(p < sz) res.push_back(intervals[p++]);
        
        return res;
    }
};


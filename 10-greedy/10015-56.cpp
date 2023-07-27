/*
 * leetcode 56
 * merge intervals
 *
 * intervals[i] = [start_i, end_i]
 * merge all overlapping intervals
 * and return an array of the non-overlapping intervals that covers all the 
 * intervals in the input
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    // why it does not like lambda?
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > res;
        if (intervals.size() == 0) return res;
        // sort with lambda, left boundary used
        //sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        sort(intervals.begin(), intervals.end(), cmp);

        res.push_back(intervals[0]); // first interval
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] > intervals[i][0]) { // right > left
                // overlapping, merge these two
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]); // non-overlapping
            }
        }
        return res;        
    }
};

int main() {
    int a[4][2] = {{1,3}, {2,6}, {8, 10}, {15,18}};
    vector<vector<int> > v1;
    // expect [[1,6], [8,10], [15,18]]
    Solution s;
    vector<vector<int> > a1 = s.merge(v1);

    return 0;
}

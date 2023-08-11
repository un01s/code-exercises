/*
 * leetcode 57
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        int i = 0, n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        // no overlapping
        while (i < n && intervals[i][1] < start) {
            result.push_back(intervals[i]);
            i++;
        }
        // overlapping
        while(i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        int t[2] = {start, end};
        vector<int> v(t, t+sizeof(t)/sizeof(int));
        result.push_back(v);

        // remaining
        while(i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

int main() {
    int a[2][2] = {{2, 5}, {7, 9}};
    int b[2] = {4, 8};
    //vector<vector<int> > x{{2, 5}, {7, 9}};
    //vector<vector<int> > v(a, a+sizeof(a)/sizeof(int));

    vector<int> u(b, b+sizeof(b)/sizeof(int));

    Solution s;

    //s.insert(v, u);

    return 0;
}

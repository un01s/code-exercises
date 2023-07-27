/*
 * leetcode 435
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // use the right boundary
    // it is ok to use left boundary
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if(intervals.size() == 0) return 0;

        // sort from little to big, with the right boundary
        sort(intervals.begin(), intervals.end(), cmp);
        // 
        int count = 1; // num of non-overlapping intervals
        int end = intervals[0][1]; // first right boundary
        // index from 1 instead of 0
        for(int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                // no overlapping, current left with previous right
                count++;
                end = intervals[i][1];
            } 
        }
        return intervals.size() - count;
    }
};

// the way to use left boudaries is different from using right ones
// here, count the overlapping.
// before count non-overlapping
class Solution2 {
public:
    // use left boundary here!
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // from little to big
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if(intervals.size() == 0) return 0;

        // sort from little to big, with the left boundary
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; // to record the overlapping intervals
        int end = intervals[0][1]; // right
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) end = intervals[i][1];
            else {
                // overlapping case
                end = min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};

int main() {
    int a[4][2] = {{1,2}, {2, 3}, {3, 4}, {1, 3}};
    vector<vector<int> > v1(4, vector<int>(2,0));
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            v1[i][j] = a[i][j];
        }
    }

    Solution s;

    if (1 == s.eraseOverlapIntervals(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}

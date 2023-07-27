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

        // sort from little to big, with the left boundary
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

int main() {
    return 0;
}

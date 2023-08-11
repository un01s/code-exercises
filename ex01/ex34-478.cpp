/*
 * Leetcode 478
 * 
 * given an array of intervals where intervals[i] = [start_i, end_i]
 * return minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping
 * 
 * the idea is use the end to sort the array
 * then compare the current start with the previous end to see if there is
 * any overlapping
 *  
 * lambda function is used in the sort
 *
 * this code is OK in Leetcode.
 * but it cannot be compiled with g++
 * 
 * Apple clang version 13.0.0 (clang-1300.0.29.30)
 * Target: arm64-apple-darwin22.4.0
 * Thread model: posix
 * 
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class Solution {
public:
    // TODO review, this is interesting
    // 
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        // use the end of one interval to sort
        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b){
                return a[1] < b[1];
            });

        int removed = 0;
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEnd) {
                // overlapped
                removed++;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return removed;
    }
};

int main() {
    return 0;
}

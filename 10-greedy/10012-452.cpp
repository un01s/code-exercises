/*
 * leetcode 452
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int> >& points) {
        if(points.size() == 0) return 0;
        // sort from little to big, with the left boundary
        sort(points.begin(), points.end(), cmp);
        // 
        int res = 1; // at least one arrow
        // index from 1 instead of 0
        for(int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i-1][1]) {
                // no overlapping, current left with previous right
                res++;
            } else {
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

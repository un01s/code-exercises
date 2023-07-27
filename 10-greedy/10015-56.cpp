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

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > res;
        return res;        
    }
};

int main() {
    int a[4][2] = {{1,3}, {2,6}, {8, 10}, {15,18}};
    vector<vector<int> > v1(4, vector<int>(2, 0));
    
    // expect [[1,6], [8,10], [15,18]]
    Solution s;
    vector<vector<int> > a1 = s.merge(v1);

    return 0;
}

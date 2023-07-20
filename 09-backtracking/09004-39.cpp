/**
 * Leetcode 39 
 * 
 * a set without duplicate, candidates
 * a target number, target
 * find all candidate whose sum is target
 *
 * 1 <= candidates <= 200, no zeros in candidates
 * the number from candidates can be used repeatedly with no limit
 *
 * 2023-07-20
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // helper to debug
    void show(vector<vector<int> >& v) {
        cout << "[ ";
        for(int i = 0; i < v.size(); i++) {
            cout << "[ ";
            for(int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]" << endl;
    }

    // global for results in backtracking
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int start) {
        // there are two conditions to stop the recursion
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }
        //
        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            // the key is that the start use the same i instead of i+1
            // because that duplicates are allowed in this!
            backtracking(candidates, target, sum, i); // duplicate allowed
            sum -= candidates[i]; // backtrack
            path.pop_back();
        }
    }    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        backtracking(candidates, target, 0, 0); // sum = 0, index = 0 
        return res;       
    }  
};

int main() {
    int c1[] = {2, 3, 6, 7};
    int t1 = 7;
    vector<int> v1(c1, c1+sizeof(c1)/sizeof(int));
    int c2[] = {2, 3, 5};
    int t2 = 8;
    vector<int> v2(c2, c2+sizeof(c2)/sizeof(int));

    Solution s;
    vector<vector<int> > v = s.combinationSum(v1, t1);
    s.show(v);
/*
[ [ 2 2 3 ][ 7 0 0 ] ]
*/
    v.clear();
    v = s.combinationSum(v2, t2);
    s.show(v);
/*
[ [ 2 2 2 2 ][ 2 3 3 0 ][ 3 5 0 0 ] ]
*/


    return 0;
}


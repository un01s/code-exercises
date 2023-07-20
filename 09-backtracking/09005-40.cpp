/**
 * Leetcode 40 
 * 
 * a set without duplicate, candidates
 * a target number, target
 * find all candidate whose sum is target
 *
 * 1 <= candidates <= 200, no zeros in candidates
 * the number from candidates can NOT be used repeatedly
 *
 * there are duplicates in candidates, however, 
 * the return should not have duplicates!
 *
 * 2023-07-20
 *
 * NOTES:
 *
 * without sorting of candidates, the used vector is no use for some cases 
 * where the duplcates are scattered in the candidates!
 * must do sorting to candidates! or the result is not complete if any.
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
    void backtracking(vector<int>& candidates, int target, int sum, int start, vector<bool>& used) {
        // there are two conditions to stop the recursion
        //if (sum > target) {
        //    return;
        //}
        if (sum == target) {
            res.push_back(path);
            return;
        }
        //
        for (int i = start; i < candidates.size() && sum+candidates[i]<=target; i++) {
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i+1, used); // duplicate not allowed
            used[i] = false;
            sum -= candidates[i]; // backtrack
            path.pop_back();
        }
    }    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // sorting is important for used!!
        backtracking(candidates, target, 0, 0, used); // sum = 0, index = 0 
        return res;       
    }  
};

// without using used as the above
class Solution2 {
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

private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // have to avoid the used element in candidates at the same tree level
            // here use the index and i together to bypass the same candidate
            // still the sorting of candidates are critical!
            // without the sorting before passed into the function call
            // the result is not correct!
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); 
            // the difference from leetcode 39:
            // in problem 39, duplicates are allowed
            // here in problem 40, no duplicate are allowed
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // sorting makes duplicates stay together
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

int main() {
    int c1[] = {10, 1, 2, 7, 6, 1, 5};
    int t1 = 8;
    vector<int> v1(c1, c1+sizeof(c1)/sizeof(int));
    int c2[] = {2, 5, 2, 1, 2};
    int t2 = 5;
    vector<int> v2(c2, c2+sizeof(c2)/sizeof(int));

    Solution s;
    //Solution2 s;
    vector<vector<int> > v = s.combinationSum2(v1, t1);
    s.show(v);
/*
[ [ 1 1 6 ][ 1 2 5 ][ 1 7 0 ][ 2 6 0 ] ]
*/
    v.clear();
    v = s.combinationSum2(v2, t2);
    s.show(v);
/*
[ [ 1 2 2 ][ 5 0 0 ] ]
*/


    return 0;
}


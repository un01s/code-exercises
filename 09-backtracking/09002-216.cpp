/**
 * Leetcode 216
 * 
 * find all k numbers whose sum equals n
 * the set has numbers from 1 to 9, all unique and no duplicate.
 * the return should have no duplicate.
 *
 * 
 * 2023-07-20
 *
 * k is the depth of the tree, need find k numbers
 * 9 is the width of the tree, we have numbers from 1 to 9 as the set to choose
 * 
 * if k = 2, n = 4, then 
 * find all combinations from [1, 2, ..., 9], 
 * get two numbers whose sum equals 4.
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
 

    vector<vector<int> > res;
    vector<int> path;
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        // sum is the current sum of numbers in the path
        // targetSum is n
        if (path.size() == k) {
            // found k numbers
            if (sum == targetSum) res.push_back(path);
            return;
        }
        for (int i = startIndex; i < 9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1);
            sum -= i; // backtrackinng
            path.pop_back(); // backtracking
        }
    }  
    vector<vector<int> > combinationSum3(int k, int n) {
        res.clear();
        path.clear();

        backtracking(n, k, 0, 1);
        return res;
    }
};

int main() {
    int k = 3;
    int n = 7;

    Solution s;
    vector<vector<int> > v = s.combinationSum3(k, n);
    s.show(v); // [ [ 1 2 4 ] ]

    v.clear();
    v = s.combinationSum3(3, 9);
    s.show(v); // [ [ 1 2 6 ][ 1 3 5 ][ 2 3 4 ] ] 
        

    return 0;
}


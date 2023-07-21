/**
 * Leetcode 78
 *
 * nums, all unique integers, no duplicates
 * return all the subsets of nums
 *
 * 2023-07-20
 *
 * the return should not have duplicates
 * 
 * if imagine the problems of subset, combination, and substring-cut as
 * a tree, then the combination and substring problems are collecting the leaf
 * nodes of the tree, and the subsets problem is looking for all nodes.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // helpers
    void showVector(vector<int>& v) {
        cout << "[ ";
        for(int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << "]";
    }
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
    void backtracking(vector<int>& nums, int startIndex) {
        showVector(path); // because the very first is []
                          // this cause all the followings have no space

        res.push_back(path);
        cout << " startIndex:" << startIndex << endl;

        if (startIndex >= nums.size()) {
            return; // stop
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i+1); // next level
            path.pop_back();
        }
    }    
    vector<vector<int> > subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};

int main() {
    int a[] = {1, 2, 3};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
 
    Solution s;
    vector<vector<int> > v = s.subsets(v1);
    s.show(v);

    //v.clear();
    //v = s.subsets(v2);
    //s.show(v);
/*

[ ] startIndex:0
[ 1 ] startIndex:1
[ 1 2 ] startIndex:2
[ 1 2 3 ] startIndex:3
[ 1 3 ] startIndex:3
[ 2 ] startIndex:2
[ 2 3 ] startIndex:3
[ 3 ] startIndex:3
[ [ ][ ][ ][ ][ ][ ][ ][ ] ]

 */

    return 0;
}


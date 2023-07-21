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
 * the strange thing is that the code runs OK with Leetcode which uses Linux 
 * at the backend. 
 * however, the macOS returns all empty subsets.
 * the clue is that the first empty subset is push into the vector,
 * this may cause no space for subsequent addon.
 * STRANGE!
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

class Solution2 {
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

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int> > result;
        dfs(nums, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int> >& result) {
        result.push_back(curr);
        showVector(curr);

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

// the following works OK at Leetcode
// this is still backtracking
// why there is no termination condition?
// because the input array is limited
// once the for-loop is done, the recursion will stop too.
// here every nodes are collected.
//
class Solution3 {
public:
    vector<int> curr;
    vector<vector<int> > result;

    void dfs(vector<int>& nums, int start) {
        result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            dfs(nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        curr.clear();
        result.clear();

        dfs(nums, 0);
        return result;
    }
};

int main() {
    int a[] = {1, 2, 3};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
 
    Solution2 s;
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


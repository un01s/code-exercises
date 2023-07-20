/*
 * leetcode 77 combination
 *
 * given two integers, n and k, return all subset of k from 1..n.
 *
 * 
 */

#include <iostream>
#include <vector>

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

    // two globals for results
    vector<vector<int> > res;
    vector<int> path;
    // 
    // startIndex to record the starting position to search
    void backtracking(int n, int k, int startIndex) {
        // how to stop the recursion?
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // one loop: breadth first
        for (int i = startIndex; i <= n; i++) {
	    path.push_back(i); // process the node or the element
            backtracking(n, k, i+1); // for the next loop, recursively
            path.pop_back(); // back
        }
    }
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        path.clear(); 
        
        backtracking(n, k, 1);
        return res;
    }
};

int main() {
    // test case 1
    int n = 4;
    int k = 2;

    Solution s;
    vector<vector<int> > v = s.combine(n, k);
    s.show(v);

    return 0;
}


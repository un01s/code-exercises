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

    return 0;
}


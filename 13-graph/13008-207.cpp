/*
 * leetcode 207
 *
 * input: numCourses = 2, prerequisites =[[1, 0]]
 * output: true
 * total 2. to learn 1, learn 0 first.
 *
 * input: numCourses = 2, prerequisites =[[1, 0], [0, 1]]
 * output: false
 *
 * turn it into a directed graph, if there is a circle or ring,
 * then it is impossible
 * 
 * to store a graph, there are two ways:
 * 1) neighbor matrix
 * 2) neighbor list: List<int>[] graph;
 * 
 */


class Solution {
public:
    vector<bool> onPath;
    vector<bool> visited;
    bool hasCycle = false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 2) return true;

        return !hasCycle;                
    }
    // DFS
};

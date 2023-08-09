/*
 * leetcode 797
 * all paths from source to target
 * directed, acyclic graph
 * 
 */

class Solution {
private:
    vector<vector<int> > res;
    vector<int> path;
    // x: current node of traversal
    // graph: current graph
    void dfs(vector<vector<int> >& graph, int x) {
        // all paths from node 0 to n-1
        if (x == graph.size()-1) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i< graph[x].size(); i++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]); // next
            path.pop_back(); // backtracking
        }
    }
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0); // start from node 0
        dfs(graph, 0);
        return res;
    }
};


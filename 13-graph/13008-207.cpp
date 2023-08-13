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
    vector<bool> visited;
    vector<bool> onPath;
    bool hasCycle = false;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 2) return true;
        // build a graph
        vector<vectot<int> > graph = buildGraph(numCourses, prerequisites);

        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);

        for (int i = 0; i < numCourses: i++) {
            traverse(graph, i);
        }
        return !hasCycle;                
    }
    // DFS
    void traverse(vector<vector,int> >& graph, int s) {
        if (onPath[s]) hasCylcle = true;
        if (visited[s] || hasCycle) return; 
        // pre-order
        visited[s] = true;
        onPath[s] = true;
        for (int t : graph[s]) {
            traverse(graph, t);
        }
        // post-order
        onPath[s] = false;
    }
    // build the graph
    vector<int>* buildGraph(int numCourses, vector<vector<int> >& prerequisites) {
        auto* graph = new vector<int>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            graph[i] = vector<int>();
        }
        for (auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }
};

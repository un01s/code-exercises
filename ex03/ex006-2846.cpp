/*
 * leetcode 2846
 *
 */

class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int LOG = 14;
        vector<vector<int>> frec(n, vector<int>(26, 0));
        vector<int> h(n, 0);
        vector<vector<int>> ST(n, vector<int>(LOG, 0));
        vector<vector<pair<int, int>>> G(n, vector<pair<int, int>>());
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            G[u].emplace_back(v, w - 1);
            G[v].emplace_back(u, w - 1);
        }
        
        function<void(int, int)> init = [&] (int u, int p) -> void {
            ST[u][0] = p;
            for(int d = 1; 1 << d <= h[u]; d++) {
                ST[u][d] = ST[p][0];
                p = ST[p][d];
            }
        };
        
        function<void(int, int)> DFS = [&] (int u, int p = -1) -> void {
            init(u, p);
            for(auto e : G[u]) {
                int v, w;
                tie(v, w) = e;
                if(v == p) continue;
                h[v] = h[u] + 1;
                for(int j = 0; j < 26; j++) frec[v][j] = frec[u][j];
                frec[v][w] += 1;
                DFS(v, u);
            }
        };
        
        function<int(int, int)> go_up = [&] (int u, int d) -> int {
            while(d) {
                int k = __builtin_ctz(d);
                d &= d - 1;
                u = ST[u][k];
            }  
            return u;
        };
        
        function<int(int, int)> lca = [&] (int u, int v) -> int {
            if(h[u] < h[v]) swap(u, v);
            u = go_up(u, h[u] - h[v]);
            if(u == v) return u;
            for(int i = LOG - 1; i >= 0; i--) {
                if((1 << i) > h[u]) continue;
                if(ST[u][i] != ST[v][i]) {
                    u = ST[u][i];
                    v = ST[v][i];
                }
            }
            return ST[u][0];
        };
        
        DFS(0, -1);
        
        vector<int> res;
        
        for(auto &e : queries) {
            int u = e[0], v = e[1];
            int l = lca(u, v);
            int max_color = 0;
            for(int c = 0; c < 26; c++) {
                int cnt = frec[u][c] + frec[v][c] - 2 * frec[l][c];
                if(cnt > max_color) max_color = cnt;
            }
            res.emplace_back(h[u] + h[v] - 2 * h[l] - max_color);
        }
        return res;
    }
};


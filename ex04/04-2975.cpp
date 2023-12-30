/*
 * leetcode 2975
 * maximum square area by removing fences from a field
 *
 */

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<int> len;
        
        long long e = -1;
        for (int i = 0; i < h.size(); ++i) {
            for (int j = i + 1; j < h.size(); ++j) {
                len.insert(h[j] - h[i]);
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                int l = v[j] - v[i];
                if (len.count(l)) {
                    e = max(e, (long long) l);
                }
            }
        }
        if (e == -1) {
            return -1;
        }
        return e * e % 1000000007;
    }
};


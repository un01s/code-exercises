/*
 * leetcode 2849
 * pair
 *
 */

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        pair<int, int> p1 = {sx, sy};
        pair<int, int> p2 = {fx, fy};
        if (p1 == p2) {
            if (t == 1) return false;
            return true;
        }    
        long a = abs(sx-fx);
        long b = abs(sy-fy);
        long res = max(a, b);
        if (res <= t) return true;
        else return false;
    }
};


/*
 * q2
 */

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d=max(abs(sx-fx), abs(sy-fy));
        if (t==1&&d==0)
            return 0;
        return d<=t;
    }
};

/*
 * leetcode 2141
 * max running time of N computers
 *
 * binary search
 * 
 */

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s = 0;
        for(int i = 0; i < batteries.size(); i++) {
            s += batteries[i];
        }      
        long long l = 1, r = s / n;
        while (l < r) {
            auto m = (l + r + 1) >> 1;
            long long tot = 0;
            for (int i = 0; i < batteries.size(); i++) {
                tot += min<long long>(m, batteries[i]);
                if (tot >= m * n) break;
            }
            if (tot >= m * n) 
                l = m;
            else 
                r = m - 1;
        }
        return l; 
    }
};

// over time limit!
class Solution2 {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = 0, right = LLONG_MAX/n;
        while (left < right)
        {
            long long mid = (right+left)/2;
            if (checkOK(mid, n, batteries))
                left = mid;
            else
                right = mid-1;
        }
        return left; 
    }
    bool checkOK(long long T, long long n,  vector<int>& batteries) {
        long long sum = 0;
        for (int i = 0; i < batteries.size(); i++)
        {
            sum += min((long long)batteries[i], T);
            if (sum >= T*n)
                return true;
        }
        return false;
    }
};


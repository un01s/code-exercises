/*
 * leetcode 2813
 * Maximum-Elegance-of-a-K-Length-Subsequence
 * 
 * 1. sort profit from big to small
 * 2. select first k elements, it has t categories now
 * 3. there is no point to move to t-1 categories. 
 * 4. how to select one element so that categories becomes t+1?
 *    - find a new category from remaining subarray
 *    - remove one element from current selected which is NOT single in its category
 *
 * greedy!
 *    
 */

using LL = long long;
using PII = pair<LL, LL>;
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) 
    {
        sort(items.rbegin(), items.rend());

        LL sum = 0;
        unordered_map<int, int>Map;
        for (int i=0; i<k; i++)
        {
            sum += items[i][0];
            Map[items[i][1]]++;
        }

        LL t = Map.size();
        LL ret = sum + t*t;

        priority_queue<PII, vector<PII>, greater<>>pq;
        for (int i=0; i<k; i++)
            pq.push({items[i][0], items[i][1]});

        for (int i=k; i<items.size(); i++)
        {
            if (Map.find(items[i][1])!=Map.end()) continue;

            while (!pq.empty())
            {
                auto [profit, cate] = pq.top();
                pq.pop();

                if (Map[cate] > 1)
                {
                    sum -= profit;
                    sum += items[i][0];
                    t++;
                    Map[cate]--;
                    Map[items[i][1]]++;

                    ret = max(ret, sum + t*t);
                    break;
                }
            }
        }

        return ret;
    }
};

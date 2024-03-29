/*
 * leetcode 347
 *
 * count, frequency order, first K of higher frequency
 * 
 */

class Solution {
public:
    // min-heap
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count
        unordered_map<int, int> map; // map<nums[i],count>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // size = k
        // ordered by frequency or count, the top has the minimum of count
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        // find out the the first K
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};


/**
 * Leetcode 347 top K frequent elements
 *
 * Given an integer array nums and an integer k, return the k most frequent 
 * elements. You may return the answer in any order. 
 *
 * k in the range of [1, nums.size()]
 * it is guaranteed that the answer is unique.
 *
 * 2023-07-05
 *
 * 1. couunt the frequency of each element
 * 2. sort the frequency
 * 3. find the top K of most frequent element
 *
 * priority queue use max-heap to get the order of the elements 
 * vector-based complete binary tree
 * 
 *
 * TODO 209 minimum size subarray sum
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> //<priority_queue>

using namespace std;

class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // count the frequency
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        // sort the frequency
        priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        // find the top K
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }    
};

int main() {
    int a[] = {1,1,1,2,2,3};
    int k1 = 2;
    vector<int> u(a, a + sizeof(a)/sizeof(int));

    int b[] = {1};
    int k2 = 1;
    vector<int> v(b, b + sizeof(b)/sizeof(int));

    Solution s;

    s.topKFrequent(u, k1); // [1, 2]
    s.topKFrequent(v, k2); // [1]

    return 0;
}


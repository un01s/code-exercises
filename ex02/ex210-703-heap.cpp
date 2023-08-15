/*
 * leetcode 703
 * Kth largest element in a stream
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        } 
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K) {
            q.pop();
        }
        return q.top();
    }
};

int main() {
    return 0;
}

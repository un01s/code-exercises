/*
 * leetcode 239
 * max sliding window
 *
 * deque
 * this is a new solution used deque directly.
 *
 *
 * there is another leetcode 236
 * lowest common ancestor of a binary tree 
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que; // monotonic queue
        // the elements from the front to the end is
        // strictly either increasing or decreasing
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        void push(int value) {
            while(!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value); // decreasing from big to small
        }
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
/*
        // this solution OK
        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k; i++) { // the first k element into queue
            que.push(nums[i]);
        }
        result.push_back(que.front()); // record the max of the first K
        for(int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]); // remove from the left from the sliding-win
            que.push(nums[i]); // add from the right
            result.push_back(que.front()); // record
        }
        
        return result;    
*/
        vector<int>results;
        deque<int>q;
        for (int i=0; i<nums.size(); i++)
        {
            while (q.size()>0 && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);

            if (q.front()<=i-k)
                q.pop_front();

            if (i>=k-1)
                results.push_back(nums[q.front()]);
        }
        return results;
    }
};

void printV(vector<int>& v) {
    cout << "Vector:[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> v1(a, a+ sizeof(a)/sizeof(int));

    Solution s;
   
    vector<int> a1 = s.maxSlidingWindow(v1, k1);
    printV(a1);

    return 0;
}

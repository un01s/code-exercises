/**
 * Leetcode 239 sliding window maximum 
 * https://leetcode.com/problems/sliding-window-maximum/
 *
 * 
 * 2023-07-05
 * the bit problem with sliding-window approach is the following:
 * the monotonic queue is very clean to think about because the max 
 * is always at the front of the queue.
 * 
 * max number can be sticky.
 * m, a, b
 * 1, 3, 1, 2, 0, 5 (k=3)
 *       3, 3, 2, 5 (answer)
 * 1, 3, 3, 3, 3, 5 (m)
 *       3, 3, 3, 5 (res)
 * 
 * 7, 2, 5
 * 7, 7, 7 (m)
 *
 * the local max moves into its neighbor.
 * how to find the condition to avoid this sticky local max?
 *
 * TODO leetcode 581, 496, 503, 84, 122, 862
 * TODO study deque
 * TODO 76, 155, 159
 *
 */

#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que; // monotonic queue, max at the front
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
        void show() {
            if (!que.empty()) {
                cout << "Que: ";
                for(int n : que) {
                    cout << n << " ";
                }
                cout << endl;
            }
        }
    };
public:

    // use deque to construct a monotonic queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        show(nums);

        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k; i++) { // the first k element into queue
            que.push(nums[i]);
        }
        que.show();
        result.push_back(que.front()); // record the max of the first K
        for(int i = k; i < nums.size(); i++) {
            que.pop(nums[i-k]); // remove from the left from the sliding-win
            que.push(nums[i]); // add from the right
            que.show();
            result.push_back(que.front()); // record
        }
        show(result);
        return result;
    }
    // this sliding-window approach requires a lot of house keeping to
    // get it right
    vector<int> maxSlidingWindowSW(vector<int>& nums, int k) {
        show(nums);

        if (k == 1) return nums;

        int left = 0, right = 0;
        int rSize = nums.size() - k + 1;
        int rIndex = 0;
        vector<int> res(rSize, 0);
        int m = 0;
        int count = 0;
        while (right < nums.size()) {
            int a = nums[right];
            if (right == 0) {
                m = a;
            } else {
                m = max(m, a);
            }
            right++;
            count++;

            if (count >= k) {
                res[rIndex++] = m;
                if (k == 2) {
                    m = min(m, a);
                }
            }

            while(count > k) {
                int b = nums[left];
                count--;
                left++;

                if (b == m) {
                    // this is hard
                    // for example
                    // 3 1 2 0 (k=3)
                    // 3 out and 0 in
                    // correct m should be 2
                    // but how to get it if k is big?
                    // 3 1 2 1 0 (k=4)
                    // how to get max(1, 2, 1) here?                  
                }
            }
        }
        show(res);
        return res;
    }
    void show(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }    
};

int main() {
    int a[] = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    vector<int> u(a, a + sizeof(a)/sizeof(int));

    int b[] = {1,3,1,2,0,5};
    int k2 = 3;
    vector<int> v(b, b + sizeof(b)/sizeof(int));

    int c[] = {7, 2, 4}; //{1,-1};
    int k3 = 2; // 1;
    vector<int> w(c, c + sizeof(c)/sizeof(int));

    int d[] = {3, 7, 2};
    int k4 = 2;
    vector<int> x(d, d + sizeof(d)/sizeof(int));
    Solution s;
    s.maxSlidingWindow(u, k1);
    s.maxSlidingWindow(v, k2);
    s.maxSlidingWindow(w, k3); // expecting [1, -1], instead [1,1]
    s.maxSlidingWindow(x, k4); // expecting [7, 4], instead [7,7]
     
    return 0;
}


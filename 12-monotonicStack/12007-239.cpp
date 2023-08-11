/*
 * leetcode 239
 *  
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MonotonicQueue {
private:
    deque<int> maxq;
public:
    void push(int n) {
        while(!maxq.empty() && maxq.back() < n) {
            maxq.pop_back();
        }
        maxq.push_back(n);
    } 
    void pop(int n) {
        if (n == maxq.front()) {
            maxq.pop_front();
        }
    }
    int max() {
        return maxq.front();
    }   
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue window;

        int n = nums.size();
        for(int i = 0; i< n; i++) {
            if (i < k-1) {
                window.push(nums[i]);
            } else {
                // move the window forward
                // add new element
                window.push(nums[i]);
                res.push_back(window.max());
                // remove its last element
                window.pop(nums[i-k+1]);
            }
        }
        return res;        
    }
};

void printV(vector<int>& v) {
    if (v.empty()) return;

    cout << "vector: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;
    vector<int> r1 = s.maxSlidingWindow(v1, k1);
    printV(r1);

    return 0;
}

/*
 * leetcode 503
 * next greater element, circular array
 * 739, 496
 *
 *
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // not found = -1
        if (n == 0) return res;

        // nums not empty
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++) {
            // pay attention to i%n
            if (nums[i%n] <= nums[st.top()]) st.push(i%n);
            else {
                while(!st.empty() && nums[i%n] > nums[st.top()]) {
                    res[st.top()] = nums[i%n];
                    st.pop();
                }
                st.push(i%n);
            }
        }
        return res;
    }
};

// class Solution2 {
// simpler
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // not found = -1
        if (n == 0) return res;

        // nums not empty
        stack<int> st;
        
        for(int i = 1; i < n*2; i++) {
            // pay attention to i%n
            while(!st.empty() && nums[i%n] > nums[st.top()]) {
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};


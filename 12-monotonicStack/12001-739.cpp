/* 
 * leetcode 739
 * 
 * daily temperatures
 *
 * Given an array of integers temperatures represents the daily temperatures, 
 * return an array answer such that answer[i] is the number of days you 
 * have to wait after the ith day to get a warmer temperature.
 *  
 * If there is no future day for which this is possible, keep answer[i] == 0 
 * instead.
 * 
 * Find the next hotter day.
 * find first element on the right side which is bigger
 * 
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // increasing from top to bottom of the stack
        int n = temperatures.size();
        vector<int> res(n, 0);
        st.push(0);

        for (int i = 1; i < n; i++) {
            if (temperatures[i] < temperatures[st.top()]) {
                // case 1: all traversed less than the top
                st.push(i);
            } else if (temperatures[i] == temperatures[st.top()]) {
                // case 2: equal
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    // case 3: greater than the top
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};


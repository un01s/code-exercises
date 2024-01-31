/*
 * leetcode 739
 * monotonic stack
 * 
 */

class Solution {
public:
    // monotonic stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n, 0);
        vector<array<int,2>> st;
        st.push_back({temperatures[n-1], n-1});
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && temperatures[i] >= st.back()[0])
                st.pop_back();

            if (!st.empty())
                ans[i] = st.back()[1] - i;

            st.push_back({temperatures[i], i});
        }
        return ans;        
    }
};


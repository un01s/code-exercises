/*
 * leetcoe 42
 * trapping rain water
 * 
 */

class Solution {
public:
    int trap(vector<int>& height) {
        // mootonic stack
        const unsigned n = height.size();
        int res = 0;
        vector<unsigned> st;
        for (int r = 0; r < n; r++) {
            while (!st.empty() && height[st.back()] < height[r]) {
                int m = st.back();
                st.pop_back();
                if (st.empty())
                    break;
                int l = st.back();
                int h = min(height[r] - height[m], height[l] - height[m]);
                int w = r - l - 1;
                res += h * w;
            }
            st.push_back(r);
        }
        return res;
    }
};


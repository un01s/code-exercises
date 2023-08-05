/*
 * leetcode 84
 * 
 * 
 */

// brute force
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int sum = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {

            int left = i;
            int right = i;
            for (; left >= 0; left--) {
                if (heights[left] < heights[i]) break;
            }
  
            for (; right < n; right++) {
                if (heights[right] < heights[i]) break;
            }
            // width
            int w = right - left - 1;
            int h = heights[i];
            sum = max(sum, w * h);
        }
        return sum;
    }
};

// double-pointer
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();

        // the first on the left whose height is less than current
        minLeftIndex[0] = -1; // -1
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // not if but while
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        // the first on the right whose height is less than current
        minRightIndex[size - 1] = size; // 
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};

// monotonic stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0); // head 
        heights.push_back(0); // tail
        st.push(0);

        // start from 1 instead of 0
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) { // case1
                st.push(i);
            } else if (heights[i] == heights[st.top()]) { // case2
                st.pop(); //
                st.push(i);
            } else { // case3
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};

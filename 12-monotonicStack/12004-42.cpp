/*
 * leetcode 42
 * trapping rain water
 * 
 * Given n non-negative integers representing an elevation map where the width 
 * of each bar is 1, compute how much water it can trap after raining.
 *
 * input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 * three different approaches
 * - double-pointer
 * - dynamic prgamming
 * - monotonic stack
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// find the height of rain trapped for each column,
// it depends on the min of the height of its left and right neighbors
// the first and last column won't be able to trap rain
// 
// this is wrong, because it just looking for its immediate neighbors
// but need to find both highest left and right neighbors
//
class Solution0 {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for(int i = 1; i < height.size()-1; i++) {
            int h = min(height[i-1], height[i+1]) - height[i];
            if (h > 0) sum += h;
        }      
        return sum;
    }
};
// brute force
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();

        for(int i = 0; i < n; i++) {
            // the first and the last won't be able to trap rain
            if (i == 0 || i == n-1) continue;

            int left = height[i]; // max on the left for current i
            int right = height[i]; // max on the right for current i
            for(int l = i-1; l >= 0; l--) {
                if (height[l] > left) left = height[l];
            }
            for(int r = i+1; r < n; r++) {
                if (height[r] > right) right = height[r];
            }
            // the result
            int h = min(left, right) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};
// double-pointer
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // special case, only two columns
        // the first and the last won't be able to trap rain
        if (n <= 2) return 0;

        vector<int> maxL(n, 0);
        vector<int> maxR(n, 0);
        maxL[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxL[i] = max(height[i], maxL[i-1]);
        }
        maxR[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxR[i] = max(height[i], maxR[i+1]);
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int h = min(maxL[i], maxR[i]) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};
// monotonic stack
class Solution3 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // special case, only two columns
        // the first and the last won't be able to trap rain
        if (n <= 2) return 0;

        // use the stack to store the index
        // when to compute, use the height of that index
        stack<int> st;
        st.push(0); // first
        int sum = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {     // less than the top
                st.push(i);
            } if (height[i] == height[st.top()]) {  // equal to the top
                st.pop();
                st.push(i); // need update the index
            } else {                                // greater then the top
                while (!st.empty() && height[i] > height[st.top()]) { // while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1; // minus 1
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int b[] = {4,2,0,3,2,5};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution3 s;

    if (6 == s.trap(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (9 == s.trap(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

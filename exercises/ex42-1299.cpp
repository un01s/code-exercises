/* leetcode 1299 */

// correct
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxVal = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = maxVal;
            maxVal = max(maxVal, temp);
        }
        return arr;
    }
};

// wrong 
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int> st;
        
        if (arr.size() == 1) {
            return vector<int>(1, -1);
        }
        int n = arr.size();
        int last = arr[n-1];
        for(int i = 1; i < n; i++) {
            if (last > arr[n-i-1]) {
                arr[n-i-1] = last;
            } else {
                last = arr[n-i-1];
                st.push(n-i-1);
            }
        }
        int j = st.top();
        if (j != 0) {
            int i = 0;
            for(i = 0; i < (n-j); i++) {
                arr[i] = arr[i+j];
            }
            arr[i] = -1;
        }
        return arr;
    }
};

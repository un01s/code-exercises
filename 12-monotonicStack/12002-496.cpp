/*
 * leetcode 496
 * 
 * there is another solution in this folder.
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res(nums1.size(), -1);
        // empty case
        if (nums1.size() == 0) return res;

        // non-empty case
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = i;
        }
        st.push(0); // index 0 
        // start from 1
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= nums2[st.top()]) {
                st.push(); // greater, to stack
            } else {
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    if (m.count(nums[st.top()]) > 0) {
                        // each elemet is unique
                        int index = m[nums2[st.top()]];
                        res[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

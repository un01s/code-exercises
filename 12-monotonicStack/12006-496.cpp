/*
 * leetcode 496
 * next greater element I
 *
 * nums1 is a subset of nums2.
 * all the integers in nums1 and nums2 are unqiue.
 *
 */

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        // push to the stack from the end of the nums
        for(int i = n-1; i >= 0; i--) {
            // check the value
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop(); // smaller popped out of the stack
            }
            // if there is no next greater element, return -1
            //
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return res;
    }
    // nums1 is the subset of nums2
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> greater = nextGreaterElement(nums2);
        unordered_map<int, int> m;
        for(int i = 0; i< nums2.size(); i++) {
            m[nums2[i]] = greater[i];
        }            
        int n = nums1.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = m[nums1[i]];
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
    int a1[] = {4, 1, 2};
    int b1[] = {1, 3, 4, 2};
    vector<int> v1(a1, a1+sizeof(a1)/sizeof(int));
    vector<int> v2(b1, b1+sizeof(b1)/sizeof(int));

    int a2[] = {2, 4};
    int b2[] = {1, 2, 3, 4};
    vector<int> v3(a2, a2+sizeof(a2)/sizeof(int));
    vector<int> v4(b2, b2+sizeof(b2)/sizeof(int));

    Solution s;

    vector<int> r1 = s.nextGreaterElement(v1, v2);
    printV(r1);
   
    vector<int> r2 = s.nextGreaterElement(v3, v4);
    printV(r2);

    return 0;
}

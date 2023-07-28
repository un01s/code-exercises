/*
 * leetcode 321
 *
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxVector(vector<int> nums, int k) {
        while (nums.size() > k) {
	    int i = 0, n = nums.size();
	    for (; i < n - 1; ++i) {
	        if (nums[i] < nums[i + 1]) {
		    nums.erase(nums.begin() + i);
		    break;
	        }
	    }
	    if (i == n-1) nums.erase(nums.begin() + i);
	}
        return nums;
    }
    bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
	while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
	    ++i;
	    ++j;
	}
	if (j == nums2.size()) return true;
	if (i < nums1.size() && nums1[i] > nums2[j]) return true;
	return false;
    }
    vector<int> merge(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> res(k, 0);
	for (int i = 0, j = 0, r = 0; r < k; ++r) {
	    res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
	}
	return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int m = nums1.size();
        int n = nums2.size();
        
        for(int i = max(0, k-n); i <= min(k,m); i++) {
            vector<int> v1 = maxVector(nums1, i);
            vector<int> v2 = maxVector(nums2, k-i);
            vector<int> tmp = merge(v1, v2, k);
            if (compare(tmp, 0, res, 0)) res = tmp;
        }
        return res;    
    }
};

void print(vector<int>& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {3, 4, 6, 5};
    int b[] = {9, 1, 2, 5, 8, 3};
    int k1 = 5;
    // expect [9, 8, 6, 5, 3]
    vector<int> v1(a, a+sizeof(a)/sizeof(int));    
    vector<int> v2(b, b+sizeof(b)/sizeof(int));    

    Solution s;
    vector<int> a1 = s.maxNumber(v1, v2, k1);
    print(a1);

    return 0;
}

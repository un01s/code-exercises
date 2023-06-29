/**
 * 454 4 sum II 
 * https://leetcode.com/problems/4sum-ii/
 *
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, 
 * return the number of tuples (i, j, k, l) such that:
 * 
 * - 0 <= i, j, k, l < n
 * - nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 * 20230628
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap; // key: a+b, value: count of (a+b)
        for(int a : nums1) {
            for(int b : nums2) {
                umap[a+b]++;
            }
        }
        int count = 0;
        for(int c : nums3) {
            for(int d : nums4) {
                if (umap.find(0 - (c+d)) != umap.end()) {
                    count += umap[0 - (c+d)];
                }
            }
        }
        return count;
    }
};

int main() {
    int a[] = {1, 2};
    int b[] = {-2, -1};
    int c[] = {-1, 2};
    int d[] = {0, 2};
    vector<int> n1(a, a+sizeof(a)/sizeof(int));
    vector<int> n2(b, b+sizeof(b)/sizeof(int));
    vector<int> n3(c, c+sizeof(c)/sizeof(int));
    vector<int> n4(d, d+sizeof(d)/sizeof(int));
    Solution s;
    if (2 == s.fourSumCount(n1, n2, n3, n4)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }
    
    return 0;
}

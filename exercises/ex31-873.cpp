/*
 * leetcode 873
 * length of longest fib subsequence
 *
 * dynamic programming
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// dp
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;
        for(int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        // two nodes: (i, j) and (j, k)
        // a[i] + a[j] = a[k] fib sequence
        //
        unordered_map<int, int> longest;
        int result = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < j; k++) {
                if(arr[j] - arr[k] < arr[k] && index.count(arr[j]-arr[k])) {
                    int i = index[arr[j] - arr[k]];
                    longest[k*n + j] = longest[i*n + k] + 1;
                    result = max(result, longest[k*n +j]+2);
                }
            }
        }
        return result >= 3 ? result : 0;
    }
};

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> nums1(a, a+sizeof(a)/sizeof(int));;
    cout << Solution().lenLongestFibSubseq(nums1) << endl;
    // 5

    int b[] = {1, 3, 7, 11, 12, 14, 18};
    vector<int> nums2(b, b+sizeof(b)/sizeof(int));;
    cout << Solution().lenLongestFibSubseq(nums2) << endl;
    // 3

    int c[] = {2, 4, 5, 6, 7, 8, 11, 13, 14, 15, 21, 22, 34};
    vector<int> nums3(c, c+sizeof(c)/sizeof(int));;
    cout << Solution().lenLongestFibSubseq(nums3) << endl;
    // 5
  
    return 0;
}

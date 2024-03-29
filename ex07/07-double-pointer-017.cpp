/*
 * leetcode 1574
 * shortest subarray to be removed to make array sorted
 * 
 * subarray, double-pointer
 * [0, i], [i+1, j-1], [j, n-1]
 * the middle segment is that to be removed.
 * so the question is how to find both i and j.
 * 
 */

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int ret = n-1;
        
        int j = n-1;
        while (j-1>=0 && arr[j-1]<=arr[j])
            j--;
        ret = j;        
        if (ret==0) return 0;
        
        for (int i=0; i<n; i++){
            if (i>=1 && arr[i]<arr[i-1]) break;
            while (j<n && arr[j]<arr[i])
                j++;
            ret = min(ret, j-i-1);
        }
        
        return ret;
    }
};


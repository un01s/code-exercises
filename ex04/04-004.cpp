/*
 * leetcode 4
 *
 */

class Solution {
public:
    double findKthSmallest(vector<int>& nums1, int a, int m, vector<int>& nums2, int b, int n, int k)
    {
        if (m>n) return findKthSmallest(nums2,b,n,nums1,a,m,k);
        
        if (m==0) return nums2[b+k-1];
        
        if (k==1) return min(nums1[a],nums2[b]);
        
        int k1=min(m,k/2);
        int k2=k-k1;
        
        if (nums1[a+k1-1]<nums2[b+k2-1])
            return findKthSmallest(nums1,a+k1,m-k1,nums2,b,n,k-k1);
        else
            return findKthSmallest(nums1,a,n,nums2,b+k2,n-k2,k-k2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
        if ((m+n)%2==1)
            return findKthSmallest(nums1,0,m,nums2,0,n,(m+n+1)/2);
        else
            return (findKthSmallest(nums1,0,m,nums2,0,n,(m+n)/2)+findKthSmallest(nums1,0,m,nums2,0,n,(m+n)/2+1))/2;    
    }
};


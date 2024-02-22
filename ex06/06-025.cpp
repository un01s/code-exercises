/*
 * leetcode 53
 * maximum subarray
 *
 */

class Solution {
public:
    //Kadane's Algorithm
    int maxSubArray(vector<int>& n) {
        int res=INT_MIN;
        int sum=0;
        for(int i=0;i<n.size();i++){
            sum+=n[i];
            res=max(res,sum);
            if(sum<0){
                sum=0;
            }
        }
        return res;
    }
};


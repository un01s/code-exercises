/*
 * leetcode 278 
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=0,e=n;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isBadVersion(mid)==true and isBadVersion(mid-1)!=true)
                return mid;
            else if(isBadVersion(mid)!=true){
                s=mid+1;
                }
            else if(isBadVersion(mid)){
                e=mid-1;
            }
        }
        return 1;    
    }
};

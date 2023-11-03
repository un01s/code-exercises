/*
 * leetcode 2918
 */

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        using ll = long long;
        ll suma = 0, sumb = 0, cha = 0, chb = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] == 0){
                nums1[i] = 1;
                cha++;
            }
            suma += nums1[i];
        }
        for(int i = 0; i < m; i++){
            if(nums2[i] == 0){
                nums2[i] = 1;
                chb++;
            }
            sumb += nums2[i];
        }
        if(suma == sumb) return suma;
        if(suma > sumb){
            if(!chb) return -1;
            return suma;
        }
        if(suma < sumb){
            if(!cha) return -1;
            return sumb;
        }
        return -1;
    }
};


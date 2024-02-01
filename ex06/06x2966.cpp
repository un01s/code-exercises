/*
 * leetcode 2966
 *
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        int freq[100001]={0};
        int xMax=0, xMin=INT_MAX;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        vector<vector<int>> ans;
        vector<int> vec3;
        int count=0, vec_m;
        for(int x=xMin; x<=xMax; x++){
            for( ; freq[x]>0; freq[x]--, count++){
                if (count%3==0)
                    vec_m=x;
                if (x>vec_m+k ) return {};
                vec3.push_back(x);
                if (count%3==2){
                    ans.push_back(vec3);
                    vec3.clear();
                }
            }
        }
        return move(ans);    
    }
};


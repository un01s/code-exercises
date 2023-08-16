/*
 * leetcode 11
 * container with most water
 *
 */



class Solution {
public:
    int maxArea(vector<int>& height) {
/*     
        int i = 0;
        int n = height.size();
        int j = n -1;
        int area = 0;
        while(j > 1) {
            area = max(area, min(height[i], height[j])*abs(i-j));
            if (height[i] < height[j]) i++;
            else j--;
        }   
        return area;
*/
        // double-pointer
        int left=0;
        int right=height.size()-1;
        
        int temp=0;
        int res=0;
        
        while (left<right){
            int temp = (right-left)*min(height[left],height[right]);
            if (temp>res) res=temp;
            
            if (height[left]>=height[right]) right--;
            else left++;
        }
        
        return res;
    }
};



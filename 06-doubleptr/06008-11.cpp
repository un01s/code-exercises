/*
 * leetcode 11
 * container with most water
 *
 */

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    int a[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {1, 1};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;

    if (49 == s.maxArea(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (1 == s.maxArea(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

/*
 * Leetcode 704 binary search
 *
 * the array is sorted
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bSearch(vector<int>& nums, int target, int start, int end){
        // terminate
        if(end < start) return -1;
        // mid point, recursive
        int mid = (start+end)/2;
        if(nums[mid] == target){
            return mid;
        }else if(target < nums[mid]){
            return bSearch(nums, target, start, mid-1);
        }else{
            return bSearch(nums, target, mid+1, end);
        }
    }

    int search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size()-1);
/*        
        int r = -1;  
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                r = i;
                break;
            }
        }
        return r;
*/
    }
};

int main() {
    return 0;
}

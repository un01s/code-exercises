/*
 * leetcode 2422
 * https://github.com/wisdompeak/LeetCode
 * https://github.com/akhilkammila/leetcode-screenshotter/
 * 
 * merge operations to turn array into a palindrome
 * nums: positive numbers
 * ops: choose any two adjacent elements and replace them with their sum
 * 
 * return the minimum number of operations needed to turn the array into a
 * palindrome.
 *
 * double-pointer
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

using LL = long long;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        LL left = nums[i], right = nums[j];        
        int res = 0;
        
        while (i<j){
            if (left==right){
                i++;
                j--;
                left = nums[i];
                right = nums[j];                
            } else if (left < right){
                i++;
                left += nums[i];
                res++;
            }else if (left > right){
                j--;
                right += nums[j];
                res++;
            }
        }
        return res;
    }
};

int main() {
    int a[] = {4, 3, 2, 1, 2, 3, 1};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {1, 2, 3, 4};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;
    
    if (2 == s.minimumOperations(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (3 == s.minimumOperations(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

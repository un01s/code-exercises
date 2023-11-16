/*
 * leetcode 1980
 *
 * construct a string whose character is at the diagonal position of the array
 * 
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // string contains only '0' and '1'
        string res;
        for (int i = 0; i < nums.size(); i++) {
            res += (nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};


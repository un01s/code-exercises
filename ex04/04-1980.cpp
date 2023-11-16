/*
 * leetcode 1980
 *
 * construct a string whose character is at the diagonal position of the array
 * 
 */

// why?
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

// backtracking
class Solution {
public:
    string res;
    void backtrack(unordered_set<string>& ss, string s, int len) {
        if (len == 0) {
            if (ss.find(s) == ss.end()) {
                res = s;
            }
            return;
        }
        if (res.length() == 0) {
            backtrack(ss, s+'0', len-1);
        }
        if (res.length() == 0) {
            backtrack(ss, s+'1', len-1);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        res = "";
        unordered_set<string> ss;
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            ss.insert(nums[i]);
        }
        len = nums[0].length();
        string str = "";
        backtrack(ss, str, len);
        return res;
    }
};

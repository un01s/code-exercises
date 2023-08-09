/*
 * leetcode 344 reverse string
 *
 * left-right double-pointer
 * O(1) extra memory.
 * 
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        char tmp;
        while(left < right) {
            tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--;
        }
    }
};


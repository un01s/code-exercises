/*
 * leetcode 3
 *
 * Given a string s, find the length of the longest substring
 * without repeating characters.
 * 
 * no duplicates in the substring and longest!
 *
 * sliding window
 * both are sliding windows!!
 *
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counts;
        int left = 0, right = 0;
        int result = 0;
        while(right < s.size()) {
            char c = s[right];
            counts[c]++;
            right++; // increase the sliding window
            while(left < right && counts[c] > 1) {
                char d = s[left];
                counts[d]--;
                left++;
            }
            result = max(result, right-left);
        }
        return result;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int res = 0; // to record the result
        while(right < s.size()) {
            char c = s[right];
            window[c]++;
            right++; // increase the sliding window
            while(window[c] > 1) {
                char d = s[left];
                window[d]--;
                left++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};

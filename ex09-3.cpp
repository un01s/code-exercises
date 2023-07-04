/**
 * Leetcode 3 longest substring without repeating characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/986458015/
 *
 * 2023-07-03
 * 
 * use unordered_map to record the count of every character
 * unordered_map<char, int> counts;
 * counts[c]++ or counts[c]--;
 *
 * TODO: 20, 159, 340, 992
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

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

int main() {
    
    return 0;
}


/**
 * Leetcode 3  
 * length of longest substring that has no duplicate letter
 * 
 * 2023-07-03
 *
 * the questions to ask when using the approach of sliding window:
 * - when to increase the window?
 * - when to shrink the window?
 * - when to update the result?
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // map to record the window
        unordered_map<char, int> window;
        int left = 0;
        int right = 0;
        int result = 0; 
        // length of longest substring that has no duplicate letter
        while (right < s.size()) {
            char c = s[right]; // move into the window
            right++; // increase the window [left, right)
            window[c]++;
            // shrink the window?
            while(window[c] > 1) {
                // duplicates occur
                char d = s[left]; // move out of the window
                left++;
                // update
                window[d]--; // mirror to window[c]++
            }
            result = max(result, right-left);
        }
        return result;    
    }
};

int main() {
    string s = "abcabcbb";
    string t = "bbbbb";
    Solution ans;
 
    if (3 == ans.lengthOfLongestSubstring(s)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }

    if (1 == ans.lengthOfLongestSubstring(t)) {
        cout << "OK\n";
    } else {
        cout << "failed\n";
    }

    return 0;
}


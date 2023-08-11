/**
 * Leetcode 340 longest sunstring with at most k distinct characters
 *  
 *
 *
 * 2023-07-04
 *
 * 
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        unordered_map<char, int> counts;
        int left = 0, right = 0;
        int result = 0;
        int charTypes = 0;
        while (right < s.size()) {
            char c = s[right++];
            if (counts[c] == 0) {
                charTypes++;
            }
            counts[c]++;
            // add charTypes then do NOT use the following condition
            //while (left < right && counts.size() > k) {
            while (charTypes > k) {
                char d = s[left++];
                counts[d]--;
                if (counts[d] == 0) {
                    charTypes--;
                }
            }
            cout << "[" << left << "," << right << ")" << endl;
            result = max(result, right-left);
        }
        return result;
    }    
};

int main() {
    unordered_map<char, int> test;
    string s = "abbaccabcdddcceef";
    Solution ans;
    cout << s << endl;
    cout << ans.lengthOfLongestSubstringKDistinct(s, 2) << endl;
/*
    // correct answer:
abbaccabcdddcceef
[0,1)
[0,2)
[0,3)
[0,4)
[3,5)
[3,6)
[3,7)
[6,8)
[7,9)
[8,10)
[8,11)
[8,12)
[8,13)
[8,14)
[12,15)
[12,16)
[14,17)
6
    // wrong answer with counts.size and without charTypes
abbaccabcdddcceef
[0,1)
[0,2)
[0,3)
[0,4) 
[5,5) // here a big shrinkage of the window
[6,6)
[7,7)
[8,8)
[9,9)
[10,10)
[11,11)
[12,12)
[13,13)
[14,14)
[15,15)
[16,16)
[17,17)
4  
*/
    return 0;
}


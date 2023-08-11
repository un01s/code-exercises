/*
 * leetcode 8 atoi
 *
 */

class Solution {
public:
    bool isDigit(char c) {
        unordered_set<int> digits = {'0','1','2','3','4','5','6','7','8','9'};
        return digits.find(c) != digits.end();
    }
    
    int myAtoi(string s) {
        unordered_set<int> digits = {'0','1','2','3','4','5','6','7','8','9'};
        
        if (s.size() == 0) return 0;
        int ans = 0;
        int sign = 1;
        int i = 0;
        while (s[i]==' ' || s[i]=='\t') {
            i++; // skip whitespace and tab
        }
        if (i == s.size()) return 0;
        
        // get the sign
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            i++;
            sign = -1;
        }
        
        for(; i < s.size() && isdigit(s[i]); i++) {
            if (ans > (numeric_limits<int>::max() - (s[i] - '0')) / 10) { 
                return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            ans *= 10;
            ans += s[i]-'0';
        }
        
        ans *= sign;
        return ans;
    }
};


/*
 * leetcode 125
 * valid palindrome
 * 
 */

class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                res.push_back(tolower(s[i]));
            }
        }  

        int l=0,r=res.length()-1;
   
        while(l <= r){
            if(res[l] != res[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;    
    }
};

// double-pointer
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};

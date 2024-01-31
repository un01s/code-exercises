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


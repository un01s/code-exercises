/*
 * leetcode 28 find the index of the first occurrence in a string
 *
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()&& haystack.empty())
            return 0;
        
        if(haystack.empty()||haystack.size()<needle.size())
            return -1;
        
        for(int i = 0; i <= haystack.size()-needle.size(); i++) {
            int j = 0;
            for(; j!=needle.size(); j++){
                if(needle[j] != haystack[i+j]) break;
            }
            if(j == needle.size())
                return i;
        }
        return -1;
    }
};


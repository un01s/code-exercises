/*
 * leetcode 344
 * 
 * double-pointer: left and right
 *
 * just check the for-loop
 * the common way is just one invariable like the follows:
 * for (int i = 0; i < s.size(); i++) { ... }
 *
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size()-1; i < s.size()/2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0, j = n-1; i < n/2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};


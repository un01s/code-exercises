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

// recursion
class Solution {
public:
    void myReverse(int i, vector<char>& s) {
        if (i >= s.size()-i-1) return;
        swap(s[i], s[s.size()-i-1]);
        myReverse(i+1, s);
    }
    void reverseString(vector<char>& s) {
        myReverse(0, s);
    }
};

// recursion
class Solution {
public:
    void myReverse(vector<char>& s, int low, int high) {
        if (low >= high) return;
        myReverse(s, low+1, high-1);
        swap(s[low], s[high]);
    }
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        myReverse(s, 0, n);
    }
};


/*
 * leetcode 344 
 * reverse string
 *
 */

/*
 *  iterative
 * just a simple swap
 * this requires a temporary storage
 * 
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int m = n/2;
        for (int i = 0; i <= m; i++) {
            char t = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = t;
        }
    }
};

/*
 * double pointer
 * left and right, moving toward each other, that is, moving to the center
 *
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }    
    }
};

/*
 * recursive
 */

class Solution {
public:
    void r(int i, vector<char>& s) {
        int n = s.size();
        if (i >= n/2) return;
        swap(s[i], s[n-i-1]);
        r(i+1, s);
    }
    void reverseString(vector<char>& s) {
        r(0, s);    
    }
};


/*
 * leetcode 22
 * generate parentheses
 *
 */

class Solution {
public:
    vector<string> res;
    void traverse(string current, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(current);
        }
        if (left > 0) {
            traverse(current + "(", left - 1, right);
        }
        if (right > left) {
            traverse(current + ")", left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        traverse("", n, n);
        return res;    
    }
};


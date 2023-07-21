/**
 * Leetcode 93 
 *
 * IP address; 4 numbers, each  [0, 255]
 * separated by .
 *
 *
 * 2023-07-20
 *
 * to think this through
 * 1. take a string, "25525511135"
 * 2. at first level, we take the substring 2, then 25, 255, and etc.
 * 3. at the next level, we take the second cut from the level1
 * 4. at the third level, take a third cut after the level2.
 * 
 * at each level, we have to valid the cut we take, the substring must be valid
 * or, it make the result invalid.
 * 
 * another particular thing is to add dot after each valid cut.
 * three cuts of a string results in four segments. 
 * if every segment is valid, then these cuts are valid.
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void show(vector<string>& vs) {
        cout << "[ ";
        for (int i = 0; i < vs.size(); i++) {
            cout << "\"" << vs[i] << "\" ";
        }
        cout << "]" << endl;
    }

    // the number starts with 0 is not valid
    // non-positive number is not valid
    // the number greater than 255 is not valid
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num*10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
    
    vector<string> res;
    // startIndex: where to start the search
    // pointNum: num of dot added
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            // if the last substring is valid
            if (isValid(s, startIndex, s.size()-1)) {
                res.push_back(s);
            }
            return;
        }
        // start the search
        for (int i = startIndex; i < s.size(); i++) {
            // [startIndex, i] both ends closed
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin()+i+1, '.'); // add dot or period
                pointNum++;
                backtracking(s, i+2, pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            } else {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if (s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
};

int main() {
    // test cases
    string s1 = "25525511135";
    string s2 = "0000";
    string s3 = "1111";
    string s4 = "010010";
    string s5 = "101023";
    
    Solution s;
    vector<string> vs = s.restoreIpAddresses(s1);
    s.show(vs);

    vs.clear();
    vs = s.restoreIpAddresses(s2);
    s.show(vs);

    vs.clear();
    vs = s.restoreIpAddresses(s3);
    s.show(vs);

    vs.clear();
    vs = s.restoreIpAddresses(s4);
    s.show(vs);

    vs.clear();
    vs = s.restoreIpAddresses(s5);
    s.show(vs);

    return 0;
}


/*
 * leetcode 2788
 * split strings by separator
 * 
 * Input: words = ["one.two.three","four.five","six"], separator = "."
 * Output: ["one","two","three","four","five","six"] 
 *
 * 2023-07-23
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        string tmp = "";
        for(int i = 0; i < words.size(); i++) {
            tmp = "";
            for(int j = 0; j < words[i].size(); j++) {
                if (words[i][j] != separator) {
                    tmp += words[i][j];
                } else {
                    if (tmp.size() >= 1) {
                        cout << tmp << endl;
                        res.push_back(tmp);
                    }
                    tmp = "";
                }
            }
            if (tmp.size() >= 1) {
                cout << tmp << endl;
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main() {
    string s1[] = {"one.two.three","four.five","six"};
    char separator = '.';

    vector<string> v1(3);
    v1[0] = "one.two.three";
    v1[1] = "four.five";
    v1[2] = "six";

    Solution s;
    s.splitWordsBySeparator(v1, separator);

    return 0;
}

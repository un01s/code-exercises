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
        int k = 0;
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            for (
            cout << words[i] << endl;
            if (words[i] == separator) {
                string s = words.substr(words.begin()+k, words.begin()+k+i);
                if (!s.empty()) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

int main() {
    strings s1[] = {"one.two.three","four.five","six"};
    
    return 0;
}

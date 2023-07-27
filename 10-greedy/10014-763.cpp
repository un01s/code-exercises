/*
 * leetcode 763
 * partition labels
 *
 * You are given a string s. We want to partition the string into as many 
 * parts as possible so that each letter appears in at most one part.
 *
 * return a list of integers representing the size of these parts.
 *
 * solution: greedy
 * how to group the same letter in the same range?
 *
 * 1) the last position of each letter
 * 2) traverse from the start, if the letter matches its last position, then
 * the partition point is right after.
 *
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        // use the array as a hash table
        // the string has only lower-case English letters
        int hash[26] = {0};
        // count the last position of each letter in the string
        for (int i = 0; i < S.size(); i++) {
            hash[S[i]-'a'] = i;
        }
        // start to partition
        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, hash[S[i]-'a']); // the farthest of current
            // this update always move the boundary to the farthest
      
            if (i == right) {
                res.push_back(right-left+1);
                left = i+1; // start of next partition
            }
        }
        return res;
    }
};

void show(vector<int>& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    string S1 = "ababcbacadefegdehijhklij";
    string S2 = "eccbbbbdec";

    Solution ans;

    vector<int> a = ans.partitionLabels(S1);
    show(a); // [ 9 7 8 ]
    vector<int> b = ans.partitionLabels(S2);
    show(b); // [ 10 ]

    return 0;
}

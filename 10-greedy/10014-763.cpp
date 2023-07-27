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
 * it also has the trace of double-pointer, left and right.
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

// this uses the range to solve the problem.
// more complex than the first solution
// 
class Solution2 {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; // from small to big
    }
    // count the range of each letter instead of the farthest position
    vector<vector<int> > countRange(string s) {
        vector<vector<int> > hash(26, vector<int>(2, INT_MIN));
        vector<vector<int> > hash_filter;
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]-'a'][0] == INT_MIN) {
                hash[s[i]-'a'][0] = i;
            } // starting position
            hash[s[i]-'a'][1] = i; // ending position
        }
        // remove the range for letters not appear in the string
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i][0] != INT_MIN) {
                hash_filter.push_back(hash[i]);
            }
        }
        return hash_filter;
    }
    // 
    vector<int> partitionLabels(string S) {
        vector<int> res;
        // ranges
        vector<vector<int> > hash = countRange(S);
        sort(hash.begin(), hash.end(), cmp); // use the left boundaries to sort
        // record the farthest right boundary
        int right = hash[0][1];
        int left = 0;
        for (int i = 1; i < hash.size(); i++) {
            // once one left greater than current right, partition now
            if (hash[i][0] > right) {
                res.push_back(right-left+1);
                left = hash[i][0];
            }
            right = max(right, hash[i][1]); // max of previous and current 
        }
        res.push_back(right-left+1); // farthest
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

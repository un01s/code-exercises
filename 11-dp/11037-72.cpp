/*
 * leetcode 72
 * word1 and word2, how to change word1 to word2 by minimum steps?
 * - insert a char
 * - delete a char
 * - replace a char
 *
 * all lower-case English letters
 *
 *
 * input: word1 = "horse", word2 = "ros"
 * output: 3
 * - replace 'h' with 'r': rorse
 * - delete 'r': rose
 * - delete 'e': ros
 *
 * dp[i][j] = minDistance for substring of word1 ending at i-1, and
 *            substring of word2 ending at j-1
 * 
 * state diagram:
 *
 * if (word1[i-1] == word2[j-1]), no op
 *     dp[i][j] = dp[i-1][j-1];
 *
 * if (word1[i-1] != word2[j-1]), three possible ops
 * - add or insert
 * - delete
 * : delete one char from word1, dp[i][j] = dp[i-1][j] + 1
 * : delete one char from word2, dp[i][j] = dp[i][j-1] + 1
 * word2 add one char is eqivalent to word1 delete one char
 *
 * - replace
 * dp[i][j] = dp[i-1][j-1]+1
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        // initialize
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        // traverse
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    //dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main() {
    string w1 = "horse";
    string w2 = "ros";

    Solution s;
    if (3 == s.minDistance(w1, w2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}

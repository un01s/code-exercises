/*
 * leetcode 583
 *
 * input: "sea", "eat"
 * output: 2
 * step1: delete s from "sea"
 * step2: delete t from "eat"
 * after two steps, both words become "ea"
 * this is the minimum steps requried to make both words same.
 *
 * DP
 * 
 * dp[i][j] = minimum steps to make the substring of word1 ending at i-1 and
 *            the substring of word2 ending at j-1 same.
 * when word1[i-1] == word2[j-1], dp[i][j] = dp[i-1][j-1];
 * when word1[i-1] not equal to word2[j-1]:
 * 1) delete word1[i-1], dp[i][j] = dp[i-1][j] + 1
 * 2) delete word2[j-1], dp[i][j] = dp[i][j-1] + 1
 * 3) delete both, dp[i][j] = dp[i-1][j-1] + 2
 * in the end, choose the minimum steps here
 *
 * how to initialize?
 * dp[i][0]: word2 is empty, dp[i][0] = i
 * dp[0][j]: word1 is empty, dp[0][j] = j
 *
 * how to traverse?
 * from top to bottom, from left to right
 * 
 * DP - e a t
 *  - 0 1 2 3
 *  s 1 2 3 4
 *  e 2 1 2 3
 *  a 3 2 1 2
 *
 * so the answer is 2 at the right-bottom corner
 *
 * #############################################
 * 
 * solution 2: DP
 * this problem is almost same as Leetcode 1143: max common subarray
 *
 * get the max common subarray from two strings, all other chars have to be
 * deleted. so the answer is (word1.size() + word2.size() - 2*max)
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
        // initialization
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        // traverse
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <=word2.size(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

class Solution2 {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 1; i <= word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++){
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return word1.size()+word2.size()-dp[word1.size()][word2.size()]*2;
    }
};

int main() {
    string w1 = "sea";
    string w2 = "eat";

    //Solution s;
    Solution2 s;
    if (2 == s.minDistance(w1, w2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}

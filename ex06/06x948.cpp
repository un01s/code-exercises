/*
 * leetcode 948
 * bag of tokens
 *
 */

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        int res = 0;
        int score = 0;
        int s = 0;
        int p = size(tokens) - 1;
        while (s <= p) {
            // Can we score?
            if (tokens[s] <= power) {
                power -= tokens[s++];
                ++score;
                res = max(res, score);
                // Can we power up?
            } else if (score > 0) {
                power += tokens[p--];
                --score;
            } else {
                break;
            }
        }
        return res;
    }
};


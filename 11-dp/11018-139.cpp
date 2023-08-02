/*
 * leetcode 139
 * dp
 *
 * when using backtracking, in at least one case the time limit exceeded
 * 
 * s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
 *
 * wordDict = ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 *
 */

// dp
// words are objects of knapsack problem
// string is the knapsack
// if words could form the string is the same as
// if objects(words) could fill the knapsack full
// 
// since the words can be used repeatedly, 
// this is a complete knapsack problem.
//
// dp[i] = the string with length i, if its value is true,
// it indicates that the string could be breaks into words in the dictionary
//
// dp[0] = true
// [j, i] is word, dp[i] true ==> dp[j] true, j < i
// 

class SolutionDP {
public:
    bool wordbreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);

        dp[0] = true; // if this is false, all others derived will be false
        for (int i = 1; i <= s.size(); i++) { // knapsack
            for (int j = 0; j < i; j++) { // words as objects	
                string word = s.substr(j, i-j); 
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    } 
};

// this is not working just because the order of traversal
class SolutionDP2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 0; j < wordDict.size(); j++) { // words
            for (int i = wordDict[j].size(); i <= s.size(); i++) { // knapsack
                string word = s.substr(i - wordDict[j].size(), wordDict[j].size());
                cout << word << endl;
                if ( word == wordDict[j] && dp[i - wordDict[j].size()]) {
                    dp[i] = true;
                }
                for (int k = 0; k <= s.size(); k++) cout << dp[k] << " ";
                cout << endl;
            }
        }
        return dp[s.size()];
    }
};

// back tracking
// time limit exceeded
//
// 

class Solution {
private:
    bool backtracking (const string& s, const unordered_set<string>& wordSet, int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtracking(s, wordSet, 0);
    }
};

// backtracking
class Solution2 {
private:
    bool backtracking (const string& s,
            const unordered_set<string>& wordSet,
            vector<bool>& memory,
            int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        if (!memory[startIndex]) return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1)) {
                return true;
            }
        }
        memory[startIndex] = false; 
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), 1); 
        return backtracking(s, wordSet, memory, 0);
    }
};

/*
 * leetcode 1048
 *
 */

class Solution {
public:
    static bool cmp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> mp;
        int ans = 0;
        for(string w : words) {
            int longest = 0;
            for (int i = 0; i < w.size(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest, mp[sub]+1);
            }
            mp[w] = longest;
            ans = max(ans, longest);
        }
        return ans;
    }
};

// DP
class Solution {
public:
    unordered_map<string, int> chain_lengths;
    unordered_map<string, bool> word_set;

    int calculateChainLength(const string& word) {
        if (word_set.find(word) == word_set.end()) return 0;

        if (chain_lengths.find(word) != chain_lengths.end())
            return chain_lengths[word];
        
        int chain_length = 1;
        for (int i = 0; i < word.size(); i++) {
            string new_word = word.substr(0, i) + word.substr(i+1);
            chain_length = max(chain_length, 1 + calculateChainLength(new_word));
        }
        chain_lengths[word] = chain_length;
        return chain_length;
    }
    int longestStrChain(vector<string>& words) {
        for (const auto& word : words) {
            word_set[word] = true;
        }
        int max_chain_length = -1;
        for (const auto& word : words) {
            max_chain_length = max(max_chain_length, calculateChainLength(word));
        }
        return max_chain_length;
    }
};

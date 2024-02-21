/*
 * leetcode 3042
 * count prefix and suffix pairs
 *
 */

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int r = 0; 
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(words[j].size() < words[i].size())continue; 
                if(words[j].substr(0, words[i].size()) == words[i] && words[j].substr(words[j].size() - words[i].size(), words[i].size()) == words[i])r++; 
            }
        }
        return r; 
    }
};


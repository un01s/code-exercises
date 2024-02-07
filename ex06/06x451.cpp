/*
 * leetcode 451
 * sort characters by frequency
 *
 */

class Solution {
public:
    string frequencySort(string s) {
        using int_char=pair<int, char>;
        int freq[75]; //'0'=48 'z'=122=>'z'-'0'+1=75        
        for(char c : s)
            freq[c-'0']++;

        vector<int_char> freq_c;
        for(char c='0'; c<='z'; c++){
            if (freq[c-'0']==0) continue;
            freq_c.emplace_back(freq[c-'0'], c);
        }
        sort(freq_c.begin(), freq_c.end(), greater<int_char>());
        string ans;
        for (auto& [n, c]: freq_c){
            ans+=string(n, c);
        }

        return ans;          
    }
};


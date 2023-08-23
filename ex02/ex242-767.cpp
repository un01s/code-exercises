/*
 * leetcode 767
 *
 */

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        
        for (auto c : s) {
            count[c - 'a'] += 100;
            if (count[c - 'a'] / 100 > (n + 1) / 2)
                return ""; 
        }

        for (int i = 0; i < 26; ++i) count[i] += i; 
        sort(count.begin(), count.end()); 

        int index = 1;
        string res(n, ' ');
        for (auto c : count) {
            int cnt = c / 100; 
            char ch = 'a' + (c % 100); 
            for (int i = 0; i < cnt; ++i) {
                if (index >= n) index = 0; 
                res[index] = ch;
                index += 2; 
            }
        }

        return res;
    }
};


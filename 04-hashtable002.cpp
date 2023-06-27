/**
 * 1002 find common characters
 * https://leetcode.com/problems/find-common-characters/
 *  
 * Given a string array words, return an array of all characters that show up 
 * in all strings within the words (including duplicates). You may return the 
 * answer in any order. 
 *
 * words[i] consists of lowercase English letters.
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string>& words) {
    int num = words.size();
    int hash[26] = {0};
    int hash2[26] = {0};
    vector<string> a;

    // just the fist word
    for (int j = 0; j < words[0].size(); j++) {
        hash[words[0][j]-'a']++;
    }
    // other words
    for (int i = 1; i < num; i++) {
        memset(hash2, 0, 26 * sizeof(int));
        for (int j = 0; j < words[i].size(); j++) {
            hash2[words[i][j]-'a']++;
        }
        // update hash
        for (int k = 0; k < 26; k++) {
            hash[k] = min(hash[k], hash2[k]);
        }
    }
    // convert back to letters
    for (int i = 0; i < 26; i++) {
        while(hash[i] != 0) {
            string s(1, i + 'a');
            a.push_back(s);
            hash[i]--;
        }
    }
    return a;
}

int main() {
    string words[3] = { "bella","label","roller" };
    vector<string> v(words, words + 3);
    vector<string> ans = commonChars(v);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    string words2[3] = { "cool","lock","cook" };
    vector<string> v2(words2, words2 + 3);
    vector<string> ans2 = commonChars(v2);
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}

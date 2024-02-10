/*
 * leetcode 383
 * ransom note
 *
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int fR[26] = {0}, fM[26] = {0};
        int n1 = ransomNote.size(), n2 = magazine.size();
        for (int i = 0; i < n1; i++) {
            fR[int(ransomNote[i])%97]++;
        }     
        for (int i = 0; i < n2; i++) {
            fM[int(magazine[i])%97]++;
        }
        for (int i = 0; i < 26; i++) {
            if (fM[i]>=fR[i]) continue;
            return false;
        }
        return true;
    }
};


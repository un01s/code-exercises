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

//
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto m:magazine){
            mp[m]++;
        }
        for(auto r:ransomNote){
            if(mp.find(r)!=mp.end()){
                mp[r]--;
                if(mp[r]==0){
                    mp.erase(r);
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};

// hash-table
//
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            return false; // each letter in magazine can be used only once
        }
        for(int i = 0; i < magazine.size(); i++) {
            // count the frequency of each char in magazine
            record[magazine[i]-'a']++;
        }
        // now compare it with the ransom notes
        for(int j = 0; j < ransomNote.size(); j++) {
            // traverse ransomNote
            record[ransomNote[j]-'a']--;
            if (record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};


/**
 * 242 valid anagram
 * https://leetcode.com/problems/valid-anagram/
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of 
 * a different word or phrase, typically using all the original letters 
 * exactly once.
 * 
 * Given two strings s and t, return true if t is an anagram of s, and 
 * false otherwise.
 * 
 * Constraints: s and t consist of lowercase English letters.
 *
 * create an array as the record to count the occurence of every letter of
 * first word, then minus the occurence of every letter of the second word.
 * check the array if the record is all zeros.
 * yes, true anagram. no, false.
 * 
 */

#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    int record[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        record[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
        record[t[i]-'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (record[i] != 0) {
            return false;
        }
    }
    return true;        
}

int main() {
    string s = "anagram", t = "nagaram";
    
    cout << "are "<< s << " and " << t << " anagram? ";
    if (isAnagram(s, t)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    s = "rat";
    t = "car";
    cout << "are "<< s << " and " << t << " anagram? ";
    if (isAnagram(s, t)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}

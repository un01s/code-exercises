/*
 * leetcode 1255
 * maximum score words fromed by letters
 *
 */

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        int n = words.size();
        int cnt = 0;
        vector<int> arr(26);
        for (auto it : letters) {
            arr[it - 'a']++;
        }

        for (int i = 0; i < 1 << n; i++) {
            // generate all possible combination

            vector<int> temp(26);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (auto it : words[j]) {
                        temp[it - 'a']++;
                    }
                    int scr = 0, flag = 1;
                    for (int i = 0; i < 26; i++) {
                        if (temp[i] <= arr[i]) {
                            scr += score[i] * temp[i];
                        } else {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {
                        // check weather we can make or not
                        cnt = max(cnt, scr);
                    }
                }
            }
        }
        return cnt;
    }
};


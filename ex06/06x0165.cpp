/*
 * leetcode 165
 * compare version numbers
 *
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1 = 0;
        int idx2 = 0;

        bool versionsLeft = true;

        while (versionsLeft) {
            long long num1 = 0;
            long long num2 = 0;

            while (idx1 < version1.length() && version1[idx1] != '.') {
                num1 = num1 * 10 + version1[idx1] - '0';
                idx1++;
            }

            while (idx2 < version2.length() && version2[idx2] != '.') {
                num2 = num2 * 10 + version2[idx2] - '0';
                idx2++;
            }

            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }

            if (idx1 >= version1.length() && idx2 >= version2.length()) {
                return 0;
            }

            idx1++;
            idx2++;
        }

        return 0;
    }
};


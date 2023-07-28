/*
 * leetcode 738
 * monotone increasing digits
 * 
 * 
 * 2023-07-27
 *
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        //
        int flag = strNum.size();
        for (int i = strNum.size()-1; i > 0; i--) {
            if (strNum[i-1] > strNum[i]) {
                flag = i; // to find where 9 starts
                strNum[i-1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);         
    }
};

int main() {
    // test cases
    int n1 = 10;
    int n2 = 1234;
    int n3 = 332;

    Solution s;
    if (s.monotoneIncreasingDigits(n1) == 9) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.monotoneIncreasingDigits(n2) == 1234) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (s.monotoneIncreasingDigits(n3) == 299) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}

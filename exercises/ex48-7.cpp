/*
 * leetcode 7 reverse integer
 *
 * the negative number has the minus sign as 1 at the MSB, then complimentary.
 * set the format for cout: hex or dec.
 *
 */

#include <iostream>

using namespace std;

// runtime error???

class Solution {
public:
    int reverse(int x) {
        int t = abs(x);
        int flag = 0;
        if (x < 0) {
            flag = 1;
        }

        int r = 0;
        while(t > 0) {
            r = r*10 + t%10;
            t = t/10;
        }

        if (r < INT_MIN || r > INT_MAX) {
            return 0;
        }
        if (flag == 1) {
            r = (-1)*r;
        }
        return r;
    }
};

int main() {

    int a = -123;

    Solution s;

    cout << "INT_MIN = 0x" << hex << INT_MIN << endl;
    cout << "INT_MAX = 0x" << INT_MAX << endl;
    cout << dec << "input = " << a << " reversed = ";
    cout << dec << s.reverse(a) << endl;

    return 0;
}

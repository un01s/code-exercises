/* 
 * leetcode 2806
 * 
 * 四舍五入
 *
 *
 * 0 is considered to be a multiple of 10.
 *
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int res = 100;
        int p = purchaseAmount;
        if (p%10 == 0) {
            res -= p;
        } else {
            if (p%10 >= 5) {
                res -= (p/10+1)*10;
            } else {
                res -= (p/10)*10;
            }
        }
        return res;
    }
};

int main() {
    int a = 9;
    int b = 15;
    int c = 24;
    int d = 4;
    int e = 20;

    Solution s;

    if (s.accountBalanceAfterPurchase(a)==90) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.accountBalanceAfterPurchase(b)==80) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (s.accountBalanceAfterPurchase(c)==80) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    if (s.accountBalanceAfterPurchase(d)==100) {
        cout << "test4 OK" << endl;
    } else {
        cout << "test4 failed" << endl;
    }

    if (s.accountBalanceAfterPurchase(e)==80) {
        cout << "test5 OK" << endl;
    } else {
        cout << "test5 failed" << endl;
    }

    return 0;
}

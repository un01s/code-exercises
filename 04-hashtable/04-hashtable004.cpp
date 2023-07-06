/**
 * 202 happy number
 * https://leetcode.com/problems/happy-number/
 * 
 * use the hash table to find if the sum is repeated,
 * if yes, then not a happy number
 * if no, find until the sum becomes 1.
 * to find the sum is repeated, use the unordered_set.
 * 
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        // got the digits in n one after another
        while (n) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true; // a happy number
            }
            if (s.find(sum) != s.end()) {
                // the sum repeated
                return false;
            } else {
                s.insert(sum);
            }
            n = sum; // next round
        }
    }
};

int main() {
    Solution s;
    
    if (s.isHappy(19)) {
        cout << "19 is a happy number!" << endl;
    } else {
        cout << "19 is not a happy number!" << endl;
    }
    return 0;
}

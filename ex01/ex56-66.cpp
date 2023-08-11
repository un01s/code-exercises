/*
 * leetcode 66 plus one
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;
        int a = 0;
        while(carry > 0 && i > 0) {
            a = digits[i]+carry;
            carry = a/10;
            digits[i] = a%10;
            i--;
        }
        if (i == 0) {
            a = digits[i]+carry;
            carry = a/10;
            if (carry == 1) {
                digits[i] = 1;
                digits.push_back(a%10);
            } else {
                digits[i] = a%10;
            }
        }
        return digits;
    }
};

class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n -1;
        while(i >= 0 && digits[i] == 9){
            digits[i] = 0;
            i--;
        }
        
        if (i < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            digits[i]++;
        }
        
        return digits;
    }
};

int main() {
    return 0;
}

/*
 * leetcode 860
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// greedy
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int i = 0; i < bills.size(); i++) {
            // case 1
            if (bills[i] == 5) five++;
            // case 2
            if (bills[i] == 10) {
                if (five <= 0) return false;
                ten++;
                five--;
            }
            // case 3
            if (bills[i] == 20) {
                if (five > 0 && ten > 0) {
                    twenty++;
                    ten--;
                    five--;
                } else if ( five >= 3 ) {
                    five -= 3;
                    twenty++;
                } else return false;
            }
        }
        return true;
    }
};


int main() {
    return 0;
}

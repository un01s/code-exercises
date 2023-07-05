/**
 * Leetcode 904 fruit into baskets 
 * https://leetcode.com/problems/fruit-into-baskets/
 *
 * 2023-07-04
 *
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> counts;
        int left = 0;        
        int right = 0;        
        int result = 0;        
        int basketNum = 2;
        int typeNum = 0;
        while(right < fruits.size()) {
            int f = fruits[right];
            if (counts[f]==0) {
                typeNum++;
            }
            counts[f]++;
            right++; // increase the window
            // 
            while(typeNum > basketNum) {
                int g = fruits[left];
                counts[g]--;
                if (counts[g]==0) {
                    typeNum--;
                }
                left++;
            }
            cout << left << "," << right << "-" << typeNum << endl;
            result = max(result, right-left);
        }
        return result;        
    } 
};

int main() {
    int a[] = {1, 2, 1};
    vector<int> u(a, a + sizeof(a)/sizeof(int));
    int b[] = {0, 1, 2, 2};
    vector<int> v(b, b + sizeof(b)/sizeof(int));
    int c[] = {1, 2, 3, 2, 2};
    vector<int> w(c, c + sizeof(c)/sizeof(int));

    Solution s;

    if (3 == s.totalFruit(u)) {
        cout << "test1 OK\n";
    } else {
        cout << "test1 failed\n";
    }
    if (3 == s.totalFruit(v)) {
        cout << "test2 OK\n";
    } else {
        cout << "test2 failed\n";
    }
    if (4 == s.totalFruit(w)) {
        cout << "test3 OK\n";
    } else {
        cout << "test3 failed\n";
    }

    return 0;
}


/*
 * Leetcode 941
 * valid mountain array
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int i = 1;
        while(i < arr.size() && arr[i] > arr[i-1]) {
            i++;
        }
        if (i == 1 or i == arr.size()) return false;
        while(i < arr.size() && arr[i] < arr[i-1]) {
            i++;
        }
        if (i == arr.size()) return true;
        return false;
    }
};

int main() {
    return 0;
}

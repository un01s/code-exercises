/*
 * leetcode 167
 * two sum II - input array is sorted
 *
 * Given a 1-indexed array of integers numbers that is already sorted in 
 * non-decreasing order, find two numbers such that they add up to a specific 
 * target number. 
 * Let these two numbers be numbers[index1] and numbers[index2],
 *  where 1 <= index1 < index2 < numbers.length.
 * 
 * Return the indices of the two numbers, index1 and index2, added by one as 
 * an integer array [index1, index2] of length 2.
 * 
 * The tests are generated such that there is exactly one solution. 
 * You may not use the same element twice.
 * 
 * Your solution must use only constant extra space.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // helper
    void printV(vector<int>& v) {
        if (v.empty()) return;

        cout << "vector: ";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;

        while (left < right) {
            int s = numbers[left] + numbers[right];
            if (s == target) {
                break;
            } else if (s > target){
                right--;
            } else {
                left++;
            }
        }
        //return {left+1, right+1};

        vector<int> res(2, 0);
        res[0] = left+1;
        res[1] = right+1;
        return res;
    }
};

int main() {
    int a[] = {2, 7, 11, 15};
    int t1 = 9;

    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;
    
    vector<int> a1 = s.twoSum(v1, t1);
    s.printV(a1);

    return 0;
}

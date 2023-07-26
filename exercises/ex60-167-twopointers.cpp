/*
 * leetcode 167
 * two sum II
 * 
 * the array sorted in ascending order!
 * assume each input has exactly one answer
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() < 2) return res;
        int left = 0;
        int right = nums.size()-1;
        while(left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back(left+1); // index starting from 1
                res.push_back(right+1); // index starting from 1
                return res;
            } else if (nums[left] + nums[right] > target) right--;
            else if (nums[left] + nums[right] < target) left++;
        }
        return res;
    }
};

void print(vector<int>& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {2, 7, 11, 15};
    int t1 = 9;
    vector<int> v1(a, a + sizeof(a)/sizeof(int));

    Solution s;
    vector<int> a1 = s.twoSum(v1, t1);
    print(a1);

    return 0;
}

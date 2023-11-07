/*
 * leetcode 1
 *
 * unordered_map<int, int> m;
 * as hash, the first is the number, the second is its index
 *
 */

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (m.count(c)) {
                //return {m[c], i};
                res[0] = m[c];
                res[1] = i;
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};

void print(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    int a[] = {2, 7, 11, 15};
    int t1 = 9;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;
    vector<int> a1 = s.twoSum(v1, t1);
    print(a1);

    return 0;
}

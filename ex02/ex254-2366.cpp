/*
 * leetcode 2366
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i+1] < nums[i]) {
                if (nums[i]%nums[i+1]) {
                    res += nums[i]/nums[i+1];
                    nums[i] = nums[i]/(nums[i]/nums[i+1]+1);
                } else {
                    res += nums[i]/nums[i+1]-1;
                    nums[i] = nums[i+1];
                }
            }
        }
        return res;    
    }
};

int main() {
    int a[] = {3, 9, 3};
    int b[] = {1, 2, 3, 4, 5};

    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;
    
    if (s.minimumReplacement(v1) == 2) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.minimumReplacement(v2) == 0) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

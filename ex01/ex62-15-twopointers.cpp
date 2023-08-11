/*
 * leetcode 15
 * 3 sum
 * 
 * input [-1, 0, 1, 2, -1, -4]
 * output:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 * so the sum of three elements are zero
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n = nums.size();
        // the input given is not sorted
        sort(nums.begin(), nums.end());
        // what we are looking for is a + b = -c
        // so a + b + c = 0
        // 1. iterate to n-2 only
        // 2. skip same to avoid duplicate
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            findPair(nums, -nums[i], i+1, res);
        }
        return res;
    }
    void findPair(vector<int>& nums, int target, int start, vector<vector<int> >& ans) {
        int left = start;
        int right = nums.size()-1;
        while (left < right) {
            if (nums[left]+nums[right] == target) {
                vector<int> a(3);
                a[0] = -target;
                a[1] = nums[left];
                a[2] = nums[right];
                ans.push_back(a);
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1]) {
                    left++;
                }
                while(left < right && nums[right] == nums[right+1]) {
                    right--;
                }
            } else if (nums[left]+nums[right] > target) right--;
            else if (nums[left]+nums[right] < target) left++;
        }
    }
};

void print(vector<int>& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

void print2(vector<vector<int> >& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v1(a, a + sizeof(a)/sizeof(int));

    Solution s;
    vector<vector<int> > a1 = s.threeSum(v1);
    print(v1);
    print2(a1);

    return 0;
}

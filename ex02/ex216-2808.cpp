/*
 * leetcode 2808
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, vector<int> > m;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }        
        for(auto& [key, arr]: m) {
            arr.push_back(n+arr[0]);
            int d = 0;
            for (int i = 0; i < arr.size()-1;i++) {
                d = max(d, (arr[i+1]-arr[i])/2);
            }
            res = min(res, d);
        }
        return res;
    }
};

int main() {
    return 0;
}

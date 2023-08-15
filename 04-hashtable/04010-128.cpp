/*
 * leetcode 128
 * longest consecutive subsequence
 *
 * input: nums = [100,4,200,1,3,2]
 * output: 4
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * output: 9
 *
 * there are two ways to approach this:
 * 1) sort the array and traverse the sorted one to find the longest consecutive
 *    subsequence
 * 2) build a hash-table, get one from the table, start to erase its consecutive
 *    numbers from the table
 *
 * the code below uses the second
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> q;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            q.insert(nums[i]);
        }
        while(!q.empty()) {
            int t = *q.begin();
            q.erase(t);
            int l = t-1, r = t+1;
            while(q.find(l) != q.end()) {
                q.erase(l);
                l--;
            }
            while(q.find(r) != q.end()) {
                q.erase(r);
                r++;
            }
            l = l+1;
            r = r-1;
            res = max(res, r-l+1);
        }
        return res;        
    }
};

int main() {
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> v2(b, a+sizeof(b)/sizeof(int));

    Solution s;
    
    if (s.longestConsecutive(v1)==4) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.longestConsecutive(v2)==9) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}

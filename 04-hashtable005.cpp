/**
 * 1 sum of two numbers
 *
 * why use the hash table?
 * why use the map?
 * use the map for what?
 * the key and value of the map?
 * 
 * when we need to find if an element occurs or an element is in a set
 * think about the hash table.
 *
 * the key is for the element
 * the value is for the index of the element
 * 
 */

#include <iostream>
#include <vector>
#include <cstddef>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map; // record traversed element and its index
        int empty[] = {};
        for(int i = 0; i < nums.size(); i++) {
            // go through every element in the array
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                int n[2] = {iter->second, i};
                vector<int> v(n, n + sizeof(n)/sizeof(int));
                return v;
            }
            // no match, store the element and its index in the map
            map.insert(pair<int, int>(nums[i], i));
        }
        int m[] = {};
        vector<int> w(m, m+sizeof(m)/sizeof(int)); 
        return w;
    }
};

int main() {
    int a[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(a, a + sizeof(a)/sizeof(int));

    Solution s;
    vector<int> v = s.twoSum(nums, target);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

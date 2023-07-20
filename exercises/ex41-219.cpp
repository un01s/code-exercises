/* leetcode 219 */

class Solution {
public:
    bool second(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                st.erase(nums[i - k - 1]);
            }
            if (!st.insert(nums[i]).second) {
                return true;
            }
        }
        return false;    
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != nums.end() && i - mp[nums[i]] <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }    
        return false;
    }
};


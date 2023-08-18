
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // must sort first
        // this makes the pointer moving meaningful
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res;
        int tmp = INT_MAX;
        for (int i = 0; i < n; i++) {
            int left = i+1;
            int right = n-1; // the end
            int sum = target - nums[i];

            while (left < right) {
                if (tmp > abs(nums[left]+nums[right]-sum)) {
                    // update the minimum result
                    tmp = abs(nums[left]+nums[right]-sum);
                    res = nums[i]+nums[left]+nums[right];
                }

                if (nums[left]+nums[right] == sum) return target;
                else if (nums[left]+nums[right] > sum) right--;
                else if (nums[left]+nums[right] < sum) left++;            
            }      
        }

        return res;
    }
};


/*
 * leetcode 2818
 * apply operations to maximize score
 *
 * You are given an array nums of n positive integers and an integer k.
 *
 * Initially, you start with a score of 1. You have to maximize your score by 
 * applying the following operation at most k times:
 * 
 * Choose any non-empty subarray nums[l, ..., r] that you haven't chosen 
 * previously.
 * Choose an element x of nums[l, ..., r] with the highest prime score. 
 * If multiple such elements exist, choose the one with the smallest index.
 * Multiply your score by x.
 * Here, nums[l, ..., r] denotes the subarray of nums starting at index l and 
 * ending at the index r, both ends being inclusive.
 *
 * The prime score of an integer x is equal to the number of distinct prime 
 * factors of x. For example, the prime score of 300 is 3 
 * since 300 = 2 * 2 * 3 * 5 * 5.
 * 
 * Return the maximum possible score after applying at most k operations.
 * 
 * Since the answer may be large, return it modulo 109 + 7.
 * 
 * Input: nums = [8,3,9,3,8], k = 2
 * Output: 81
 *  
 * Input: nums = [19,12,14,6,10,18], k = 3
 * Output: 4788
 *
 * https://www.youtube.com/watch?v=-h12SmBQznA
 *
 * solution
 *
 * positive integers
 * 
 * nums = [19, 12, 14, 6, 10, 18]
 * prime_score = [1, 2, 2, 2, 2, 2]
 * 
 * how many subarray can be created to have the maximum value for the score?
 * greedy
 *
 * compute the prime_score first
 * 
 * how to choose the subarray? find a range?
 * how to calculate the prime score?
 * 
 * count/find array by element, here by the greatest
 * then find the next greater prime score to the left and to the right
 * t = (i-L)*(R-i)
 * nums[i]
 * monotonic queue
 * 
 * greedy: nums[i] should be the greatest in the chosen subarray
 * so that the final score will be greater.
 * 
 * 1. count/find array by element
 * 2. precompute the prime score
 *    sift
 * 3. prev greater element/ next greater element
 * 4. nums[i]^10 -> quick power
 *
 */

class Solution {
public:
    int primeScore(int n) {
        int score = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            bool f = false;
            while (n%i == 0) {
                f = true;
                n = n/i;
            }
            if (f) score++;
        }
        if (n >= 2) {
            score++;
        }
        return score;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        vector<int> pScore(n);
        for (int i = 0; i < n; i++) {
            pScore[i] = primeScore(nums[i]);
        }

        vector<int> next_greater(n, n);
        vector<int> prev_greater(n, -1);

    }
};


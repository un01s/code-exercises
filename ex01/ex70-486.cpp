/*
 * leetcode 486 predict the winner
 *
 * You are given an integer array nums. Two players are playing a game with 
 * this array: player 1 and player 2.
 *
 * Player 1 and player 2 take turns, with player 1 starting first. 
 * Both players start the game with a score of 0. At each turn, the player 
 * takes one of the numbers from either end of the array (i.e., nums[0] or 
 * nums[nums.length - 1]) which reduces the size of the array by 1. 
 * The player adds the chosen number to their score. The game ends when there 
 * are no more elements in the array.
 * 
 * Return true if Player 1 can win the game. 
 * If the scores of both players are equal, then player 1 is still the winner, 
 * and you should also return true. 
 * You may assume that both players are playing optimally.
 * 
 * 
 */

class Solution {
public:
    // recursion
    int maxDiff(vector<int>& nums, int left, int right, int n) {
        if (left == right) {
            return nums[left];
        }
        int scoreByLeft = nums[left] - maxDiff(nums, left+1, right, n);
        int scoreByRight = nums[right] - maxDiff(nums, left, right-1, n);

        return max(scoreByLeft, scoreByRight);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return maxDiff(nums, 0, n-1, n) >= 0;    
    }
};


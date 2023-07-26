/*
 * leetcode 134
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// brute force
// time O(n*n) space O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1; // cannot complete
        for(int i = 0; i < cost.size(); i++) {
            int remain = gas[i] - cost[i];
            // second loop
            int index = (i+1)%cost.size();
            while(remain > 0 && index != i) {
                remain += gas[index] - cost[index];
                index = (index+1)%cost.size();
            }
            // if take i as the starting point and the remaining gas positive
            // this is the answer
            if (remain >= 0 && index == i) return i;
        }
        return res;
    }
};

// greedy
// case 1: if sum(gas) < sum(cost), wherever to start, no way to complete
// case 2: remain[i] = gas[i]-cost[i], i = 0, then sum(remain[i])>=0, i OK
// case 3: if the sum(remain[i]) negative, change to the next start point
class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int minSum = INT_MAX;
        for(int i = 0; i < gas.size(); i++) {
            int remain = gas[i] - cost[i];
            curSum += remain;
            if (curSum < minSum) {
                minSum = curSum;
            }
        }
        if (curSum < 0) return -1; // case 1
        if (minSum >= 0) return 0; // case 2

        for(int i = gas.size()-1; i>=0; i--) {
            int remain = gas[i] - cost[i];
            minSum += remain;
            if (minSum >= 0) return i;
        }
        return -1;
    }
};

// greedy
class Solution3 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i]; // remaining gas
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // no gas
                start = i + 1;  // change the start to i+1
                curSum = 0;     // curSum reset to 0
            }
        }
        if (totalSum < 0) return -1; // no way
        return start;
    }
};


int main() {
    return 0;
}

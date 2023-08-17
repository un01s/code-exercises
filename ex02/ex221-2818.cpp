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

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

using LL = long long;
LL M = 1e9+7;
using PII = pair<LL, LL>;

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

    vector<int> primeScore2(int n)
    {
        vector<int> q(n+1,0);
        for (int i=2; i<=n; i++){
            if (q[i] >= 1) continue;
            q[i] = 1;
            int j=i*2;
            while (j<=n)
            {
                q[j] +=1;
                j+=i;
            }
        }
        return q;
    }

    // find all primes <= n
    vector<int>Eratosthenes(int n)
    {
        vector<int>q(n+1,0);
        vector<int>primes;
        for (int i=2; i<=sqrt(n); i++){
            if (q[i]==1) continue;
            int j=i*2;
            while (j<=n)
            {
                q[j]=1;
                j+=i;
            }
        }        
        for (int i=2; i<=n; i++)
        {
            if (q[i]==0)
                primes.push_back(i);                
        }
        return primes;
    }

    long long quickMul(long long x, long long N) {
        if (N == 0) {
            return 1;
        }
        LL y = quickMul(x, N / 2) % M;
        return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
    }

    int maximumScore(vector<int>& nums, int k) {
        LL n = nums.size();
        int m = *max_element(nums.begin(), nums.end());

        vector<int> pScore(n);
        for (int i = 0; i < n; i++) {
            pScore[i] = primeScore(nums[i]);
        }
        //printV(pScore);

        vector<int> s = primeScore2(m);
        vector<LL> scores(n);
        for (int i = 0; i < n; i++) {
            scores[i] = s[nums[i]];
        }
        //printV(scores);
        // prime scores are OK 
        // both are the same

        // monotonic stack
        vector<LL> next_greater(n, n);
        vector<LL> prev_greater(n, -1);
        stack<int> st; // decreasing
        // traverse from the start to the end
        for (int i = 0; i < n; i++) {
            while(!st.empty() && scores[st.top()] < scores[i])
                st.pop();
            if (!st.empty()) {
                prev_greater[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // traverse from the end to the start
        for (int i = n-1; i >= 0; i--) {
            while(!st.empty() && scores[st.top()] <= scores[i])
                st.pop();
            if (!st.empty())
                next_greater[i] = st.top();
            st.push(i);
        }
        
        vector<PII> tmp(n);
        for(int i = 0; i < n; i++) {
            LL t = (LL)(i-prev_greater[i])*(next_greater[i]-i);
            tmp[i] = {nums[i], t};
        }

        sort(tmp.rbegin(), tmp.rend());

        LL res = 1;
        for(auto [num, t]: tmp) {
            if((LL)k >= t) {
                res = res * quickMul(num, t)%M;
                k -= t;
            } else {
                res = res * quickMul(num, k)%M;
                k = 0;
            }
            if (k == 0) break;
        }

        return res;
    }

    // helper
    void printV(vector<int>& v) {
        cout << "V:[ ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    int a[] = {3, 4, 9, 7, 29, 17, 11, 33};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    
    Solution s;
    s.maximumScore(v1, 2);
    
    return 0;
}

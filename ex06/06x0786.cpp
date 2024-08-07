/*
 * leetcode 786
 * k-th smallest prime number
 *
 */

class Solution {
public:
    using int2 = pair<int, int>; // (i, j) represents the index for fraction
                                 // arr[i]/arr[j]
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int n = arr.size();
        auto cmp = [&](int2 x, int2 y) -> bool {
            // Comparison of numerators over the common denominator.
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        vector<int2> denL(n - 1);
        for (int i = 0; i < n - 1; i++)
            denL[i] = {
                n - 2 - i,
                n - 1}; // Put the index for numerator & denominator=arr[n-1]
        priority_queue<int2, vector<int2>, decltype(cmp)> pq(cmp, denL);

        for (int i = 1; i < k; i++) {
            auto [num_i, den_i] = pq.top();
            pq.pop();
            pq.emplace(num_i, den_i - 1);
        }
        auto [num_i, den_i] = pq.top();
        return {arr[num_i], arr[den_i]};
    }
};


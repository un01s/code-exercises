/*
 * leetcode 454
 * hash table + map
 *
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap; 
        // key:a+b, sum，value:a+b count of the sum
        // traverse both A and B, put sum in the map
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        int count = 0; // count of 0 =a+b+c+d
        // traverse both C and D, find out if 0-(c+d) occurs
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

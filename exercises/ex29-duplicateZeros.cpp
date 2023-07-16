/*
 * duplicate zeros
 * 1089
 *
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // find number of zeros first
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count++;
            }
        }
        
        // if any zero, resize the array
        // should not resize the array, use the same array
        if (count != 0) {
            int m = n + count;
            arr.resize(m);
            for (int i = n-1; i >= 0; i--) {
                if (arr[i] == 0) {
                    arr[m-1] = arr[i];
                    m--;
                } 
                arr[m-1] = arr[i];
                m--;
            }
            arr.resize(n);
        }
    }
};


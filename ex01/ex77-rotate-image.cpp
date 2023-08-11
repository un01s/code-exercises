/*
 * leetcode rotate image
 *
 */

class Solution {
public:
    void print(vector<vector<int> >& matrix) {
        cout << "[ ";
        for (int i = 0; i < matrix.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
    void rotate(vector<vector<int>>& matrix) {
        print(matrix);
        const int n = matrix.size();
        // Anti-diagonal mirror.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // Horizontal mirror.
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        } 
        print(matrix);
    }
};


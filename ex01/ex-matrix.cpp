#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > matrix; // empty matrix
    int m = 4, n = 5; // row-num, col-num

    int a[20] = {0};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    vector<int> w(20, 0);

    // this is a one way to initialize the matrix
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for(int j = 0; j < n; j++) {
            row.push_back(i*n+j);
        }
        matrix.push_back(row);
    } 

    vector<vector<int> > x(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            x[i][j] = i*n+j; // now we can use this, or segment fault due to empty matrix 
            v[i*n+j] = i*n+j; // row-major into one dimension array 
            w[i*n+j] = i*n+j; // 
        }
    } 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << x[i][j] << ",";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    
    return 0;
}

/*
 * leetcode 118
 *
 * pascals' triangle
 *
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        // first row
        vector<int> a(1, 1);
        res.push_back(a);
        for(int i = 0; i < numRows-1; i++) {
            vector<int> b;
            b.push_back(1);
            for (int j = 0; j < res[i].size()-1; j++) {
                b.push_back(res[i][j]+res[i][j+1]);
            }
            b.push_back(1);
            res.push_back(b);
        }    
        return res; 
    }
};

int main() {
    return 0;
}

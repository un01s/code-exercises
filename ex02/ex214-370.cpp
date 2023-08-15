/*
 * leetcode 370
 *
 * [startIndex, endIndex, inc]
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
        vector<int> res(length);
        for(int i = 0; i < updates.size(); i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            for(int j = start; j <= end; j++) {
                res[j] += inc; 
            } 
        }
        return res;
    }
};

void printV(vector<int>& v) {
    cout << "V:[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int l1 = 5;
    int a1[] = {1, 3, 2, 2, 4, 3, 0, 2, -2};
    vector<vector<int> > updates1(3, vector<int>(3, 0));
    for (int i = 0; i < 9; i++) {
        updates1[i/3][i%3] = a1[i];
    }
    
    Solution s;
    vector<int> a = s.getModifiedArray(l1, updates1);
    printV(a); // expect: [ -2 0 3 5 3 ]

    return 0;
}

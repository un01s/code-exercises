/*
 * leetcode 1346
 * check if n and its double exist
 *
 * this uses the unordered_set!
 * then count()
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int i = 0; i < arr.size(); i++) {
            if (s.count(2*arr[i]) == 1 || (arr[i]%2 == 0 && s.count(arr[i]/2))) return true;
            s.insert(arr[i]);
        }
        return false;
    }
};

int main() {
    int a[] = {10, 2, 5, 3};
    int b[] = {3, 1, 7, 11};
    int c[] = {7, 3, 14, 1};

    vector<int> u(a, a+sizeof(a)/sizeof(int));
    vector<int> v(b, b+sizeof(b)/sizeof(int));
    vector<int> w(c, b+sizeof(b)/sizeof(int));

    Solution s;
    
    if (s.checkIfExist(u) == true) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 OK" << endl;
    }

    if (s.checkIfExist(v) == false) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 OK" << endl;
    }

    if (s.checkIfExist(w) == true) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 OK" << endl;
    }

    return 0;
}

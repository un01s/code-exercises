/*
 * leetcode 2834
 * 
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> st;
        long long res = 0;
        for (int i = 1; st.size() < n; i++) {
            if (st.find(target-i) == st.end()) {
                st.insert(i);
                res += i;
            }
        }
        return res;   
    }
};

int main() {
    int n1 = 2;
    int t1 = 3;
    int n2 = 3;
    int t2 = 3;
    int n3 = 1;
    int t3 = 1;
    
    Solution s;
    
    if (s.minimumPossibleSum(n1, t1)==4) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.minimumPossibleSum(n2, t2)==8) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (s.minimumPossibleSum(n3, t3)==1) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}

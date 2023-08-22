/*
 * leetcode 168
 * 
 * excel sheet column title
 * A -> 1
 * B -> 2
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26  + 'A');
    }
};

class Solution2 {
public:
    string convertToTitle(int columnNumber) {
        return "";
    }
};

int main() {
    int n1 = 1; // A
    int n2 = 28; // AB
    int n3 = 701; // ZY

    Solution s;

    if ("A" == s.convertToTitle(n1)) {
        cout << "Test1 OK" << endl;
    } else {
        cout << "Test1 failed" << endl;
    }

    if ("AB" == s.convertToTitle(n2)) {
        cout << "Test2 OK" << endl;
    } else {
        cout << "Test2 failed" << endl;
    }

    if ("ZY" == s.convertToTitle(n3)) {
        cout << "Test3 OK" << endl;
    } else {
        cout << "Test3 failed" << endl;
    }


    return 0;
}

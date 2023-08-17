/*
 * leetcode
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[] = {3, 4, 9, 7, 29, 17, 11, 33};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    // get the max of the array v1
    int m = *max_element(v1.begin(), v1.end());
    cout << "max: " << m << endl;

    return 0;
}

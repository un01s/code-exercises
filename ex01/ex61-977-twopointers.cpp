/*
 * leetcode 977
 * squares of a sorted array 
 * 
 * the array sorted in non-descreasing order!
 * return the squares of each number also in non-decreasing order
 *
 * input [-4, -1, 0, 3, 10]
 * output [0, 1, 9, 16, 100]
 *
 * negative number
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquare(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);

        int left = 0;
        int right = n-1;
        int highIndex = n-1;

        while(left <= right) {
            int lSquare = arr[left]*arr[left];
            int rSquare = arr[right]*arr[right];

            if (lSquare >= rSquare) {
                res[highIndex--] = lSquare;
                left++;
            } else {
                res[highIndex--] = rSquare;
                right--;
            } 
        }
        return res;
    }
};

void print(vector<int>& v) {
    cout << "[ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int a[] = {-7, -3, 2, 3, 11};
    vector<int> v1(a, a + sizeof(a)/sizeof(int));

    Solution s;
    vector<int> a1 = s.sortedSquare(v1);
    print(v1);
    print(a1);

    return 0;
}

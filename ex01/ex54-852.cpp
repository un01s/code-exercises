/*
 * leetcode 852
 * Peak Index in a Mountain Array
 * 
 * 2023-07-24
 *
 * this is easy!
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int res = 0;
        int t = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if (arr[i] > t) {
                t = arr[i];
                res = i;
            }
        }
        return res;
    }
};

// easy simpler, as linear scan, shown in editorial
class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while(arr[i] < arr[i+1]) {
            i++;
        }
        return i;
    }
};

// binary search
class Solution3 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // binary search
        int l = 0, r = arr.size()-1, mid;
        while(l < r) {
            mid = (l+r)/2;
            if (arr[mid] < arr[mid+1]) l = mid+1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    int a[] = {0, 1, 0};
    int r1 = 1;
    int b[] = {0, 2, 1, 0};
    int r2 = 1;
    int c[] = {0, 10, 5, 2};
    int r3 = 1;
    
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
    vector<int> v3(c, c+sizeof(c)/sizeof(int));

    Solution s;

    if (r1 == s.peakIndexInMountainArray(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (r2 == s.peakIndexInMountainArray(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (r3 == s.peakIndexInMountainArray(v3)) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}


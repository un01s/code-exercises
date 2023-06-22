/*
 * https://leetcode.com/problems/squares-of-a-sorted-array/
 * 
 * Given an integer array nums sorted in non-decreasing order, 
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// helper
void print(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return;
}

// brutal force
// square each element and sorting in non-decreasing order
//
// O(n + nlogn)
//
vector<int> bfSortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end()); // sorting

    print(nums);

    return nums;
}

//
// double pointers: 
// the array is ordered, after square, 
// the max value should be either left end or right end, not the middle
// 
// double pointers moving toward each other
// 
// O(n)
vector<int> dpSortedSquares(vector<int>& nums) {
    int k = nums.size() - 1; // k: pointing to the right end of new array
    vector<int> result(nums.size(), 0);
    for (int i = 0, j = nums.size() - 1; i <= j; ) {
        if (nums[i]*nums[i] < nums[j]*nums[j]) {
            result[k--] = nums[j]*nums[j];
            j--;
        } else {
            result[k--] = nums[i]*nums[i];
            i++;
        }
    }
    print(result);
    return result;
}

int main() {
    int a[] = {-4, -1, 0, 3, 10};
    int r1[] = {0, 1, 9, 16, 100};
    int b[] = {-7, -3, 2, 3, 11};
    int r2[] = {4, 9, 9, 49, 121};

    vector<int> aa(a, a + sizeof(a)/sizeof(int));
    vector<int> ab(b, b + sizeof(b)/sizeof(int));
    
    vector<int> ra(r1, r1 + sizeof(r1)/sizeof(int));
    vector<int> rb(r2, r2 + sizeof(r2)/sizeof(int));

    if( ra == bfSortedSquares(aa)) {
        cout << "bf OK\n";
    } else {
        cout << "bf failed\n";
    }
    
    if (rb == dpSortedSquares(ab)) {
        cout << "dp OK\n";
    } else {
        cout << "dp failed\n";
    }
 
    return 0;
}

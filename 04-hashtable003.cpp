/**
 * 349 intersection of two arrays
 * 
 * the constraints say that each integer array has the length less than 1000
 * so it is OK to use array to make the table
 * if no such constraints, then use unordered_set to make the hash table
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // no repeated elements
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) { // why this warning?
            // check if the element of nums2 shows up in nums_set
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        int hash[1001] = {0}; // this is big, but the constraints says 1000
        for (int num : nums1) {
            hash[num] = 1;
        }
        for (int num : nums2) {
            if (hash[num] == 1) {
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

void show(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } 
    cout << endl;
    return;
}

int main() {
    int a[] = {1, 2, 2, 1};
    vector<int> nums1(a, a + sizeof(a)/sizeof(int));
    int b[] = {2, 2};
    vector<int> nums2(b, b + sizeof(b)/sizeof(int));

    Solution s;

    // test 1
    vector<int> ans = s.intersection(nums1, nums2);
    show(ans);
    
    int c[] = {4, 9, 5};
    vector<int> num1(c, c + sizeof(c)/sizeof(int));
    int d[] = {9, 4, 9, 8, 4};
    vector<int> num2(d, d + sizeof(d)/sizeof(int));

    Solution2 s2;
    vector<int> ans2 = s.intersection(num1, num2);
    show(ans2);
    vector<int> ans3 = s2.intersection(num1, num2);
    show(ans3);

    return 0;
}

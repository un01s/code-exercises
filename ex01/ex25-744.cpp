/*
 * leetcode 744
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// the binary search is so complicated!
char binarySearch(vector<char>&letters, char target){
    int high = letters.size()-1, low = 0, mid;

    while (low < high){
        mid = low + (high-low)/2;

        if (letters[mid+1] > target && letters[mid] <= target) return letters[mid+1];
        if (letters[mid+1] <= target) low = mid+1;
        else if (letters[mid+1] > target && letters[mid] > target) high = mid;

    }

    if (target < letters[low]) return letters[low];
    else return letters[high];
}
char nextGreatestLetter(vector<char>& letters, char target) {
    int size = letters.size();

    if (target >= letters[size-1] || target < letters[0])
        return letters[0];
    else return binarySearch(letters, target);

}

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (int i = 0; i < letters.size(); i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }   
        return letters[0]; 
    }
};

int main(){
    char a[] = {'c','f','f','j'};
    vector<char> letters(a, a+sizeof(a)/sizeof(char));
    char target = 'k';

    cout << nextGreatestLetter(letters, target) << endl;
    
    Solution s;
    cout << s.nextGreatestLetter(letters, target) << endl;

    return 0;
}


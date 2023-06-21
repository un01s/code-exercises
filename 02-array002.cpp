/*
 * Given one array, nums, and one value, val:
 * remove all elements whose value equals to val,
 * and return the new length of the array after removal.
 *
 * note:
 * Do not use extra array space
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

// brutal force to remove duplicate elements
// double loops
int bfRemoveElement(vector<int>& nums, int v) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == v) { // found one
            for (int j = i+1; j < size; j++) {
                nums[j-1] = nums[j];
            }
            i--; // all elements after the index of i are moved forward 
            size--; // current array size
        }
    }
    return size;
}

// double pointers: fast and slow
// fastIndex: looking for elements in the new array, which does not have the target
// slowIndex: pointing to the index of next new array element
//
int dpRemoveElement(vector<int>& nums, int v) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (nums[fastIndex] != v) {
            nums[slowIndex++] = nums[fastIndex];
        }
        //cout << "fastIndex=" << fastIndex << " slowIndex=" << slowIndex << endl; 
        //print(nums);
    }
    return slowIndex;
}

// double pointers: two pointers moving to each other
// 
int dpRemoveElement2(vector<int>& nums, int v) {
    int leftIndex = 0;
    int rightIndex = nums.size() - 1;
    while (leftIndex <= rightIndex) {
        // look for element which is the target
        while (leftIndex <= rightIndex && nums[leftIndex] != v) {
            ++leftIndex;
        }
        // look for element which is not the target
        while (leftIndex <= rightIndex && nums[rightIndex] == v) {
            --rightIndex;
        }

        cout << "before: leftIndex=" << leftIndex << " rightIndex=" << rightIndex << endl; 
        print(nums);
        
        // use the right (not v) to overwrite the left (v)
        if (leftIndex < rightIndex) {
            nums[leftIndex++] = nums[rightIndex--];
        }

        cout << "after: leftIndex=" << leftIndex << " rightIndex=" << rightIndex << endl; 
        print(nums);
    }
    return leftIndex; // pointing to the next element of new array (final result)
}

int main() {
    int d[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    vector<int> nums(d, d + sizeof(d)/sizeof(int));
    
    print(nums);

// reminder: we are using the the same array
// have to comment out the first tests
// because it has changed the array after removal process.
 
/*
    if (5 == bfRemoveElement(nums, val)) {
        cout << "test1 OK\n";
        print(nums);
    } else {
        cout << "test1 failed\n";
    }

    if (5 == dpRemoveElement(nums, val)) {
        cout << "test2 OK\n";
        print(nums);
    } else {
        cout << "test2 failed\n";
    }
*/
    if (5 == dpRemoveElement2(nums, val)) {
        cout << "test3 OK\n";
        print(nums);
    } else {
        cout << "test3 failed\n";
    }

    return 0;
}

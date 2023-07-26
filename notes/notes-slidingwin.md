# sliding window

sliding window is a special form of two-pointer approach.

Check out the following problems and solutions.

* [leetcode 167](https://github.com/un01s/code-exercises/blob/main/exercises/ex60-167-twopointers.cpp)

* [leetcode 977](https://github.com/un01s/code-exercises/blob/main/exercises/ex61-977-twopointers.cpp)

* [leetcode 15](https://github.com/un01s/code-exercises/blob/main/exercises/ex62-15-twopointers.cpp)

* [leetcode 713](https://github.com/un01s/code-exercises/blob/main/exercises/ex63-713-twopointers.cpp)

* [leetcode 209 min subarray len](https://github.com/un01s/code-exercises/blob/main/exercises/ex64-209-slidingw.cpp)

## examples

the general idea of sliding window is simple. 

```C++
int left = 0, right = 0;

while (left < right && right < s.size()) {
    // increase window
    window.add(s[right]);
    right++;

    while(window shrink) {
        // shrink window
        window.remove(s[left]);
        left++;
    }
}

void slidingWin(string s) {
    // use right data structure to record data in the window
    unordered_map<char, int> window;

    int left = 0, right = 0;
    while(right < s.size()) {
        // c to be slided into the window
        char c = s[right];
        window.add(c);
        // increase the window
        right++;
        // update and process data in the window
        ...
        cout << "window: [" << left << "," << right << "]" << endl;
        ...
        // need shrink the left side?
        while (left < right && window needs shrink) {
            // d is char to be slided out of the window
            char d = s[left];
            window.remove(d);
            // shrink the window
            left++;
            // update data inside the window
            ...
        }
 
    }
}
```

## [76 min window substring](https://leetcode.com/problems/minimum-window-substring/)

* ex03-*.cpp
* ex04-*.cpp
* ex05-*.cpp
* ex06-*.cpp

All four problems are all using sliding window to solve. The first is difficult. The last one is easier.

There are still some problems at Leetcode. Examples to apply the sliding-window approach such as 1004 and 713.

### 713

The approach of sliding windows are still applicable. The difficult part of the problem is as follows:

* with the sliding-window approach, how to count the new subarray in the sliding window? Remember that our window is [left, right). The count is NOT all the permutation but the new subarray created by sliding right.

* the special case of k <= 1. in this case, all positive numbers in the array won't return any thing.

* when to count is important

### 1004

Get this right for the first time. After recognizing the sliding-window is applicable, then the key questions to ask are as follows:

* when to increase the window? what to update for the element within the window?
* when to shrink the window? how about the elements in the window?
* when to record or update the result?

The only point missed in the problem is the spacial case if ```k == nums.size()```.

## [other related sliding window problems](https://leetcode.com/discuss/general-discussion/1122776/summary-of-sliding-window-patterns-for-subarray-substring)

3, 340, 76, 1004, 904, 424, 930, 992, 1248, 1358

the idea of sliding window is simple. Keep two pointers, left and right to form a window. Use either [left, right) or [left, right], but use one consistently. Otherwise you will confuse yourself.

* keep increase the right pointer
* if the element at the right pointer makes the window not valid, move the left pointer to shrink the window until it becomes valid again. So we need some conditions to check if the window is valid or not.

### length of substring or subarray, min or max

* [longest substring without repeating characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## some references on two-pointers and sliding window

Two-pointer or sliding window is one of patterns and templates to solve some problems.

* https://blog.techbridge.cc/2019/08/30/leetcode-pattern-two-pointer/
* https://ithelp.ithome.com.tw/articles/10303527
* https://github.com/wisdompeak/LeetCode/tree/master/Template


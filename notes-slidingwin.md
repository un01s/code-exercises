# sliding window

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




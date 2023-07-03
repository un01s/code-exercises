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




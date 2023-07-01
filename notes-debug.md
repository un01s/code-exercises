# debug

## 05-string003.cpp

```
$ clang++ -g 05-string003.cpp
$ lldb a.out
```

Set a breakpoint on replaceTest function:

```
(lldb)b replaceTest
(lldb)r
(lldb)n
```

```r``` = run

```n``` = next, steps to the next line

```s``` = step, steps into current line's function

```r``` = run

```br list``` = list all existing breakpoints

```br del 1``` = delete the first breakpoint

```br del``` = deleting all breakpoints

## why?

This code is not difficult but why it takes some time to get it right? It is about in details.

The idea is straight forward.

* get the count of the spaces in the string
* resize the string
* use the double-pointer from tail to head to get spaces replaces by ```%20```

```c++
string replaceSpace(string s) {
    int count = 0; 
    int sOldSize = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            count++;
        }
    }
    s.resize(s.size() + count * 3);
    int sNewSize = s.size();
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
        if (s[j] != ' ') {
            s[i] = s[j];
        } else {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
    }
    return s;
}
```

So what's wrong with the above code?

1. the resize is not right. we have the old size of the string, then add the replacement count. but forget minus the space-count!
2. the for-loop to implement the double pointers. the index i is the new pointer, and the index j is the old pointer. The code can be compiled. When executing the code, we have a segment fault which means we mess up with the memory somewhere. Where? the for-loop stop-condition.
3. start with the debugger. You notice that the for-loop for double-pointer is skipped even when you want to debug-print something inside the loop.
4. read the code carefully. run it on the paper. then you realize both indexes are decremental at the same time. ideally when the old pointer reaches 0, the new pointer gets 0 too. However, we have extra room for the string and we could reach the negative index. Bad.


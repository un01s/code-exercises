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

```br list```` = list all existing breakpoints

```br del 1``` = delete the first breakpoint

```br del``` = deleting all breakpoints


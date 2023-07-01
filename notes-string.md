# strings

Strings are the finite characters in an array. However, there are special treatment for strings in many programming languages. For example, C strings have an extra terminal ```null``` char at the tail. C language uses it to determine if a string is ended. In C++, both C style strings and C++ string class are supported. Then what is the difference between ```string``` and ```vector<char>``` in C++? Almost none. There are more APIs for string class. For example, the string has overloaded the operator ```+```, while vector has none.

## C code for 05-string003

```C
char* replaceSpace(char* s){
    int count = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            count++;
        }
    }

    int newLen = len + count * 2;
    char* result = malloc(sizeof(char) * newLen + 1);
    for (int i = len - 1, j = newLen - 1; i >= 0; i--, j--) {
        if (s[i] != ' ') {
            result[j] = s[i];
        } else {
            result[j--] = '0';
            result[j--] = '2';
            result[j] = '%';
        }
    }
    result[newLen] = '\0';

    return result;
}
```

### python code

```python
class Solution:
    def replaceSpace(self, s: str) -> str:
        result = []
        for i in range(len(s)):
            if s[i] == ' ':
                result.append('%20')
            else:
                result.append(s[i])
        return ''.join(result)
```

Python code just append whatever to a new list. No double-pointer.

## KMP = [Knuth-Morris-Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm)

KMP is a linear-time algorithm for string matching. While searching for occurrences of a word within a string, the key point is when a mismatch happens, the matched part has sufficient info to determine where the next match could begin, bypassing re-examination of previously matched characters.



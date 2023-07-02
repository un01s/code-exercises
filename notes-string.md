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

### prefix and suffix of a string

Both prefix and suffix are tables. Prefix is all continuous sub-strings that starts from the first letter but not the last letter. Suffix is all continuous sub-strings that have the last letter but not the first one.

For a string ```aabaa```, its prefix table and suffix table are as follows.

| string | prefix | suffix | the longest common prefix and suffix |
| ------ | ------ | ------ | ------------------------------------ |
| a | x | x | x |
| aa | a | a | a |
| aab | a, aa | ab, b | x |
| aaba | a, aa, aab | aba, ab, b | a |
| aabaa | a, aa, aab, aaba | abaa, baa, aa, a | aa |
| aabaaf | aabaa, aaba, aab, aa, a | abaaf, baaf, aaf, af, f | - |

Then the longest common prefix and suffix for ```aabaa``` is ```aa``` and its length is ```2```. The key words are ```common``` and ```longest```.

So the next table from the longest common prefix and suffix of the word ```aabaaf``` is as follow:

| string | next table |
| ------ | ---------- |
| aabaaf | 0, 1, 0, 1, 2, 0 |


# [hash table](https://en.wikipedia.org/wiki/Hash_table)

One purpose of hash table is to know if an element is in a set. A hash function maps an element to an index of a hash table. ```index = hashFunction(name)``` and ```hashFunction = hashCode(name)%tableSize```. 

### array, set and map in C++ for hash table

| C++ set | low-level | ordered | repeatable | changeable | efficiency | add/delete |
| ------- | --------- | ------- | ---------- | ---------- | ---------- | ---------- | 
| std::set | red-black-tree | ordered | no | no | O(logN) | O(logN) |
| std::multiset | red-black tree | ordered | yes | no | O(logN) | O(logN) |
| std::unordered_set | hash-table | no | no | no | O(1) | O(1) |

| C++ map | low-level | ordered | repeatable | changeable | efficiency | add/delete |
| ------- | --------- | ------- | ---------- | ---------- | ---------- | ---------- | 
| std::map | red-black-tree | key ordered | no | no | O(logN) | O(logN) |
| std::multimap | red-black tree | key ordered | yes | no | O(logN) | O(logN) |
| std::unordered_map | hash-table | key NOT ordered | no | no | O(1) | O(1) |

## [15 three sum](https://leetcode.com/problems/3sum/)

It is not a perfect fit to use hash table for this. The removal of duplicates in the solution could go wrong easily. Instead, use the double-pointer approach.

* sorting the array first, so every number is in the order from little to big.
* i starts from the index of 0, left is pointing at i+1, and right at the tail.
* how to move left and right pointers? still looking for ```a + b + c = 0``` in this way, ```a = nums[i]```, ```b = nums[left]```, and ```c = nums[right]```. if the sum is greater than 0, since the numbers are ordered after sorting, then the right pointer should be moved to left to make the sum smaller. if the sum is less than 0, then the left pointer should move to the right side of the array to make the sum bit bigger.

In this problem, how to remove the duplicate a, or duplicate b or duplicate c is critical to get the correct answer.

* remove the duplicate a: should find nums[i]==nums[i+1] or nums[i]==nums[i-1]?



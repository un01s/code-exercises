# [hash table](https://en.wikipedia.org/wiki/Hash_table)

Array is the simplest hash table. The memory is continuous. Use the index to access the value. The index and its value are mapped to each other. 

Now let's have keys and values paired. The keys can be integers or strings. The values are not limited to integers as well. How are we going to have these keys and values stored and retrieved?

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


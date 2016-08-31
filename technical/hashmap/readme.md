# Hashmap

Hash tables are arguably the most important data structure known to mankind. Their uses are very versatile and usually performant. Hashed data structures provide constant time insertions, deletions, and retrievals given some degradation in time complexity and space trade-offs. 

One should be able to implement a hash table using using just an array data structure and some library functions. Create a templated hash table that supports the following operations for **string keys** (for simplicity):

```
  HashTable:
    void  put(key, elt)
     elt  get(key)
    void  del(key)
    bool  find(elt)
    size  size()
```

Additionally, your implementation should grow to support a healthy load factor. Load factors describe a ratio of filled spots / total spots in the table. As the load factor approaches 1, space utilization improves, but the constant-time complexity guarantee erodes. Design your implementation such that the load factor of your table never exceeds `0.75` but does not fall below `0.25` (unless the table is empty). Note that this requires you to both handle cases in which the table must grown as well as shrunk.

Finally, use **either** a separate chaining or open addressing collision resolution policy to handle hash collisions.

Use library functions liberally in your solution, but these libraries should not abstract away the core problem you are trying to solve.

## Solutions

List your "best case" approximation for your solution's complexity in each of the following operations for this problem only. (since the worst case is known to be linear)

**Put**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | 1      | 1     | gapoorva |

**Get**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | 1      | 1     | gapoorva |

**Del**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | 1      | 1     | gapoorva |

**Find**

| Language | Time   | Space | Authors  |
|----------|--------|-------|----------|
| c++      | 1      | 1     | gapoorva |
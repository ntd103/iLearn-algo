---
day: 04
topic: Python Collections, Heapq, Bisect, Itertools
tags:
  - roadmap
  - python
created: 2026-05-20
---
# Day 04 - Python Collections & Built-ins cho CP

> **Mục tiêu**: Master các module hỗ trợ CP trong Python.

## Lý thuyết

### collections module

#### Counter - đếm tần suất

```python
from collections import Counter

c = Counter("aabbbcc")           # {'b': 3, 'a': 2, 'c': 2}
c = Counter([1, 1, 2, 3, 3, 3])  # {3: 3, 1: 2, 2: 1}
c.most_common(2)                  # [(3, 3), (1, 2)]
c['b']                           # 3
c['z']                           # 0 (không KeyError)
c.update("ab")                   # cộng dồn
c.subtract("ab")                 # trừ dần
```

#### defaultdict - dict với giá trị mặc định

```python
from collections import defaultdict

graph = defaultdict(list)
graph[1].append(2)               # auto tạo []
graph[1].append(3)

cnt = defaultdict(int)
cnt['a'] += 1                    # auto tạo 0

groups = defaultdict(set)
groups['x'].add(1)               # auto tạo set()
```

#### deque - 2-ended queue

```python
from collections import deque

dq = deque([1, 2, 3])
dq.append(4)        # right - O(1)
dq.appendleft(0)    # left - O(1)
dq.pop()            # right - O(1)
dq.popleft()        # left - O(1)
dq.rotate(1)        # rotate right
```

### heapq - min-heap

```python
import heapq

h = []
heapq.heappush(h, 3)
heapq.heappush(h, 1)
heapq.heappop(h)              # 1 (min)

# Max-heap: negate values
heapq.heappush(h, -x)
-heapq.heappop(h)

# Heapify từ list
arr = [3, 1, 4, 1, 5]
heapq.heapify(arr)            # O(n)

# K largest/smallest
heapq.nlargest(3, arr)
heapq.nsmallest(3, arr)
```

### bisect - binary search trên list

```python
from bisect import bisect_left, bisect_right, insort

arr = [1, 3, 3, 5, 7]

bisect_left(arr, 3)    # 1 (left-most pos)
bisect_right(arr, 3)   # 3 (right-most pos)
bisect_left(arr, 4)    # 3 (insertion point)

insort(arr, 4)         # insert maintaining sort - O(n) cho list

# Đếm phần tử = x:  bisect_right - bisect_left
# Phần tử < x:       bisect_left(arr, x)
# Phần tử <= x:      bisect_right(arr, x)
```

### itertools - combinatorics

```python
from itertools import (
    permutations, combinations, combinations_with_replacement,
    product, accumulate, chain, groupby
)

list(permutations([1,2,3]))           # 6 perms
list(permutations([1,2,3], 2))         # 6 perms độ dài 2
list(combinations([1,2,3], 2))         # [(1,2),(1,3),(2,3)]
list(combinations_with_replacement([1,2,3], 2))  # với lặp
list(product([1,2], [3,4]))            # cartesian: [(1,3),(1,4),(2,3),(2,4)]
list(product([0,1], repeat=3))         # all 3-bit binary

list(accumulate([1,2,3,4]))            # [1,3,6,10] - prefix sum
list(accumulate([1,2,3,4], max))       # [1,2,3,4] - prefix max

list(chain([1,2], [3,4]))              # [1,2,3,4]
```

### math module

```python
from math import gcd, lcm, sqrt, ceil, floor, log2, inf, isqrt, comb, perm

gcd(12, 18)              # 6
lcm(4, 6)                # 12
isqrt(10)                # 3 (integer sqrt - không float error)
comb(5, 2)               # C(5,2) = 10
perm(5, 2)               # P(5,2) = 20
```

### functools

```python
from functools import lru_cache, cache, reduce

@cache  # Python 3.9+, không giới hạn size
def fib(n):
    if n < 2: return n
    return fib(n-1) + fib(n-2)

@lru_cache(maxsize=10000)
def dp(i, j):
    pass

reduce(lambda a, b: a + b, [1,2,3,4])  # 10
```

## Tricks Pythonic cho CP

### Quick swap

```python
a, b = b, a
arr[i], arr[j] = arr[j], arr[i]
```

### Multi-assignment

```python
a = b = c = 0
n, m = map(int, input().split())
```

### List comprehension nhanh hơn for-loop

```python
# CHẬM
res = []
for x in arr:
    if x > 0:
        res.append(x * 2)

# NHANH
res = [x * 2 for x in arr if x > 0]
```

### Slice tricks

```python
arr[::-1]              # reverse
arr[::2]               # mỗi phần tử cách 2
arr[start:end:step]
```

## Practice

### Easy

- [ ] Đếm tần suất ký tự trong chuỗi - dùng Counter
- [ ] Find K largest - dùng heapq.nlargest
- [ ] Insert maintaining sort - dùng bisect.insort

### Medium

- [ ] Top K Frequent Elements (LC #347) - Counter + heapq
- [ ] Sliding Window Maximum (LC #239) - deque
- [ ] Find First and Last Position (LC #34) - bisect

## Notes

- `Counter`, `defaultdict`, `deque`, `heapq`, `bisect` đều implement bằng C - nhanh
- Tránh implement custom data structures khi đã có built-in

---

**Next**: [[Day-05-Complexity-Debugging]]

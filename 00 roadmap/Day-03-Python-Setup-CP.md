---
day: 03
topic: Python Setup & I/O cho CP
tags:
  - roadmap
  - python
created: 2026-05-20
---
# Day 03 - Python Setup & Fast I/O cho CP

> **Mục tiêu**: Setup Python cho CP, master fast I/O.

## Lý thuyết

### Vì sao Python chậm?

- Interpreted (không compile)
- Dynamic typing (mỗi operation phải check type)
- GIL (Global Interpreter Lock)
- **Chậm 3-10x so với C++** -> nhiều bài CP TLE với Python

**Khi nào dùng Python:**
- Bài có constraint nhỏ (n < 10^5)
- Bài cần thao tác string/big number nhiều
- Khi muốn code nhanh hơn C++

### Fast I/O

```python
import sys
input = sys.stdin.readline       # nhanh hơn input() built-in 5-10x

# Đọc 1 số
n = int(input())

# Đọc nhiều số trên 1 dòng
a, b, c = map(int, input().split())

# Đọc list
arr = list(map(int, input().split()))

# Đọc tất cả input cùng lúc
data = sys.stdin.read().split()
idx = 0
n = int(data[idx]); idx += 1
```

### Print nhanh

```python
import sys
print = lambda *args, **kwargs: sys.stdout.write(' '.join(map(str, args)) + kwargs.get('end', '\n'))

# Hoặc dùng sys.stdout.write trực tiếp
sys.stdout.write(f"{result}\n")

# In nhiều dòng - nối thành 1 string rồi print 1 lần
output = []
for i in range(n):
    output.append(str(result[i]))
print('\n'.join(output))
```

### Template chuẩn

```python
import sys
from collections import Counter, defaultdict, deque
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right, insort
from itertools import permutations, combinations, accumulate
from math import gcd, lcm, sqrt, ceil, floor, log2, inf
import io, os

input = sys.stdin.readline

def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    # logic here
    print(arr)

def main():
    t = 1
    # t = int(input())  # uncomment cho multi-testcase
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
```

### Buffered I/O cực nhanh

```python
import sys, io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
```

Đọc toàn bộ stdin 1 lần - nhanh hơn `sys.stdin.readline` ~2x.

## Tricks cho CP

### Đa biến trên 1 dòng

```python
# Cách Pythonic
*a, b = map(int, input().split())  # a là list, b là số cuối
```

### Check chẵn lẻ

```python
if n & 1:  # nhanh hơn n % 2
    pass
```

### Recursion limit

```python
import sys
sys.setrecursionlimit(10**6)  # mặc định 1000
```

### Boolean as int

```python
sum(x > 0 for x in arr)  # đếm phần tử dương
```

### Tránh tạo string lớn

```python
# CHẬM
result = ""
for x in arr:
    result += str(x)  # O(n) mỗi lần

# NHANH
result = ''.join(str(x) for x in arr)
```

## Programming

### Math

`max(iterable)`

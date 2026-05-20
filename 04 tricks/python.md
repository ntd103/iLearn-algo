# Python Tricks & Competitive Idioms

### Collections module
**Khi nào dùng**: Frequency counting, default values, deque
```python
from collections import Counter, defaultdict, deque

# Frequency count
freq = Counter([1, 2, 2, 3]) # {2: 2, 1: 1, 3: 1}
freq.most_common(2) # [(2, 2), (1, 1)]

# Default dict
graph = defaultdict(list)
graph[u].append(v) # no KeyError

# Deque - O(1) both ends
dq = deque([1, 2, 3])
dq.appendleft(0)
dq.pop()
dq.popleft()
```

---

### Heapq (min-heap)
**Khi nào dùng**: Priority queue, top K
```python
import heapq

heap = []
heapq.heappush(heap, item)
smallest = heapq.heappop(heap)
heapq.heapify(list_) # O(n)

# Max-heap: negate values
heapq.heappush(heap, -val)
max_val = -heapq.heappop(heap)

# Top K largest
heapq.nlargest(k, iterable)
heapq.nsmallest(k, iterable)
```

---

### Bisect (binary search)
**Khi nào dùng**: Tìm vị trí insert trong sorted list
```python
import bisect

pos = bisect.bisect_left(arr, x) # first index >= x
pos = bisect.bisect_right(arr, x) # first index > x
bisect.insort(arr, x) # insert maintaining order
```

---

### Itertools
**Khi nào dùng**: Permutations, combinations, products
```python
from itertools import permutations, combinations, product, accumulate

list(permutations([1,2,3])) # all permutations
list(combinations([1,2,3], 2)) # all C(3,2)
list(product([0,1], repeat=3)) # all 3-bit binary
list(accumulate([1,2,3,4])) # prefix sums [1,3,6,10]
```

---

### Infinity
**Khi nào dùng**: Initialize distances, comparisons
```python
INF = float('inf')
dist = [INF] * n

# So sánh an toàn
min(INF, 5) # 5
```

---

### List comprehension tricks
**Khi nào dùng**: Tạo list nhanh
```python
# 2D array
grid = [[0] * cols for _ in range(rows)]
# KHÔNG dùng: [[0]*cols]*rows (shared reference!)

# Flatten 2D
flat = [x for row in grid for x in row]

# Filter
evens = [x for x in arr if x % 2 == 0]
```

---

### Walrus operator (:=)
**Khi nào dùng**: Assign trong condition (Python 3.8+)
```python
# Đọc input cho đến khi hết
while (line := input()) != "":
 process(line)

# Filter + transform
results = [y for x in data if (y := expensive(x)) > threshold]
```

---

### String tricks
**Khi nào dùng**: Xử lý string nhanh
```python
s.count('a') # đếm ký tự
s.isdigit() # check all digits
s.isalpha() # check all letters
''.join(reversed(s)) # reverse string
s[::-1] # reverse (faster)
ord('a') # 97
chr(97) # 'a'
```

---

### Defaultdict for graph
**Khi nào dùng**: Build adjacency list
```python
from collections import defaultdict

graph = defaultdict(list)
for u, v in edges:
 graph[u].append(v)
 graph[v].append(u) # undirected
```

---

### sys.stdin for fast input
**Khi nào dùng**: Large input (10^5+ lines)
```python
import sys
input = sys.stdin.readline

# Đọc n số trên 1 dòng
nums = list(map(int, input().split()))
```

---

### Tuple as dict key
**Khi nào dùng**: Memoization với multiple params
```python
from functools import lru_cache

@lru_cache(maxsize=None)
def dp(i, j, state):
 # memoized automatically
 pass
```

---

### Bit tricks
**Khi nào dùng**: Bitmask operations
```python
bin(x).count('1') # popcount
x & (x - 1) # clear lowest set bit
x & (-x) # isolate lowest set bit
1 << n # 2^n
```

---

### Sort stability
**Khi nào dùng**: Sort theo nhiều key
```python
# Python sort is stable — sort by secondary first, then primary
arr.sort(key=lambda x: x[1]) # secondary
arr.sort(key=lambda x: x[0]) # primary

# Hoặc dùng tuple key
arr.sort(key=lambda x: (x[0], -x[1])) # asc first, desc second
```

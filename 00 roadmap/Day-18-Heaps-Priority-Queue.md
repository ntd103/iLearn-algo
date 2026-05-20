---
day: 18
topic: Heaps & Priority Queue
tags:
  - roadmap
  - dsa/topics/heap
created: 2026-05-20
---
# Day 18 - Heaps & Priority Queue

## Lý thuyết

### Heap properties

Binary heap - complete binary tree thỏa mãn heap property:
- **Max-heap**: parent >= children
- **Min-heap**: parent <= children

| Operation | Time |
|-----------|------|
| push | O(log n) |
| pop top | O(log n) |
| top | O(1) |
| build from array | O(n) |

### C++ priority_queue

```cpp
// Max-heap (default)
priority_queue<int> pq;
pq.push(x); pq.top(); pq.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> minPQ;

// Custom comparator
priority_queue<pii, vector<pii>, function<bool(pii,pii)>> 
    pq([](pii a, pii b) { return a.first > b.first; });

// Min-heap với pair
priority_queue<pii, vector<pii>, greater<pii>> minPQ;
```

### Python heapq

```python
import heapq

h = []
heapq.heappush(h, x)
heapq.heappop(h)         # min-heap
heapq.heappushpop(h, x)
heapq.heapreplace(h, x)  # pop then push

# Max-heap: negate
heapq.heappush(h, -x)
-heapq.heappop(h)

# Heapify O(n)
arr = [3, 1, 4]
heapq.heapify(arr)

# K largest/smallest
heapq.nlargest(k, arr)
heapq.nsmallest(k, arr)
```

### Implement Heap from scratch

```cpp
class MinHeap {
    vector<int> h;
    void siftUp(int i) {
        while (i > 0 && h[(i-1)/2] > h[i]) {
            swap(h[i], h[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    void siftDown(int i) {
        int n = h.size();
        while (2*i+1 < n) {
            int j = 2*i+1;
            if (j+1 < n && h[j+1] < h[j]) j++;
            if (h[i] <= h[j]) break;
            swap(h[i], h[j]);
            i = j;
        }
    }
public:
    void push(int x) { h.push_back(x); siftUp(h.size()-1); }
    int top() { return h[0]; }
    void pop() { h[0] = h.back(); h.pop_back(); if (!h.empty()) siftDown(0); }
};
```

## Patterns

### Top K elements

```cpp
// Top K largest - dùng min-heap size K
priority_queue<int, vector<int>, greater<int>> minH;
for (int x : arr) {
    minH.push(x);
    if (minH.size() > k) minH.pop();
}
// minH chứa K phần tử lớn nhất
```

### K-way Merge

Merge K sorted lists/arrays:

```cpp
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
for (int i = 0; i < k; i++) {
    if (!arrs[i].empty()) pq.push({arrs[i][0], i, 0});
}
while (!pq.empty()) {
    auto [val, i, j] = pq.top(); pq.pop();
    result.push_back(val);
    if (j + 1 < arrs[i].size()) pq.push({arrs[i][j+1], i, j+1});
}
```

### Two heaps - Median

```cpp
priority_queue<int> maxH;  // chứa nửa nhỏ
priority_queue<int, vector<int>, greater<int>> minH;  // chứa nửa lớn

void addNum(int x) {
    maxH.push(x);
    minH.push(maxH.top()); maxH.pop();
    if (maxH.size() < minH.size()) {
        maxH.push(minH.top()); minH.pop();
    }
}

double median() {
    if (maxH.size() > minH.size()) return maxH.top();
    return (maxH.top() + minH.top()) / 2.0;
}
```

## Practice

### Easy

- [ ] Last Stone Weight (LC #1046)
- [ ] Kth Largest Element in Stream (LC #703)

### Medium

- [ ] Kth Largest Element in Array (LC #215)
- [ ] Top K Frequent Elements (LC #347)
- [ ] K Closest Points to Origin (LC #973)
- [ ] Task Scheduler (LC #621)
- [ ] Reorganize String (LC #767)
- [ ] Furthest Building You Can Reach (LC #1642)

### Hard

- [ ] Find Median from Data Stream (LC #295)
- [ ] Merge K Sorted Lists (LC #23)
- [ ] Sliding Window Median (LC #480)
- [ ] IPO (LC #502)

---

**Next**: [[Day-19-Trees-Basics]]

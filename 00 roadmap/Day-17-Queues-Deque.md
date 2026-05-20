---
day: 17
topic: Queues, Deque, Monotonic Queue
tags:
  - roadmap
  - dsa/topics/queue
  - dsa/topics/monotonic-queue
created: 2026-05-20
---
# Day 17 - Queues & Deque

## Lý thuyết

### Queue basics

```cpp
queue<int> q;
q.push(x); q.front(); q.pop(); q.empty(); q.size();
```

FIFO - First In First Out.

### Deque - 2-ended queue

```cpp
deque<int> dq;
dq.push_back(x); dq.push_front(x);
dq.back(); dq.front();
dq.pop_back(); dq.pop_front();
dq[i];           // O(1) random access
```

Use case: BFS với 0-1 weight, monotonic queue, sliding window max.

### Monotonic Queue

Deque chứa các phần tử theo thứ tự (tăng/giảm), dùng để tìm max/min trong sliding window.

#### Sliding Window Maximum

```cpp
vector<int> maxSlidingWindow(vector<int>& a, int k) {
    deque<int> dq;  // indices, a[indices] giảm dần
    vector<int> ans;
    for (int i = 0; i < a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(a[dq.front()]);
    }
    return ans;
}
```

### Circular Queue

```cpp
class CircularQueue {
    vector<int> q;
    int head, tail, size, cap;
public:
    CircularQueue(int k) : q(k), head(0), tail(-1), size(0), cap(k) {}
    bool enqueue(int x) {
        if (size == cap) return false;
        tail = (tail + 1) % cap;
        q[tail] = x; size++;
        return true;
    }
    bool dequeue() {
        if (size == 0) return false;
        head = (head + 1) % cap; size--;
        return true;
    }
};
```

### 0-1 BFS

Khi cạnh có weight 0 hoặc 1, dùng deque thay priority_queue để O(V+E):

```cpp
vector<int> dist(n, INF);
deque<int> dq;
dist[src] = 0;
dq.push_front(src);
while (!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            if (w == 0) dq.push_front(v);
            else dq.push_back(v);
        }
    }
}
```

## Practice

### Easy

- [ ] Implement Queue using Stacks (LC #232)
- [ ] Number of Recent Calls (LC #933)

### Medium

- [ ] Design Circular Queue (LC #622)
- [ ] Design Circular Deque (LC #641)
- [ ] Shortest Subarray with Sum at Least K (LC #862) - monotonic deque
- [ ] Constrained Subsequence Sum (LC #1425) - DP + monotonic deque

### Hard

- [ ] Sliding Window Maximum (LC #239)
- [ ] Jump Game VI (LC #1696) - DP + monotonic deque

---

**Next**: [[Day-18-Heaps-Priority-Queue]]

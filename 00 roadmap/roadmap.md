---
tags:
  - roadmap
created: 2026-05-20
---
# Roadmap - 35 Ngày Master CP

35 ngày học cấu trúc dữ liệu và thuật toán cho competitive programming. Mỗi ngày 1 file, theory + practice tích hợp.

## Phần 1: Ngôn ngữ & Foundation (Day 01-05)

Tập trung vào C++ và Python, master fast I/O, complexity.

- [[Day-01-CPP-Setup-Fast-IO]] - C++ setup, fast I/O
- [[Day-02-CPP-STL-Mastery]] - STL containers, algorithms
- [[Day-03-Python-Setup-CP]] - Python setup, fast I/O
- [[Day-04-Python-Collections-Itertools]] - collections, heapq, bisect
- [[Day-05-Complexity-Debugging]] - Big O, debugging skills

## Phần 2: Arrays, Strings & Two Pointers (Day 06-10)

- [[Day-06-Arrays-Prefix-Sum]] - Prefix sum, difference array
- [[Day-07-Two-Pointers]] - Two pointers patterns
- [[Day-08-Sliding-Window]] - Fixed/variable window
- [[Day-09-Hashing]] - Hash maps, sets
- [[Day-10-Strings-Pattern-Matching]] - KMP, Z-function, hashing

## Phần 3: Sorting, Search, Recursion (Day 11-14)

- [[Day-11-Sorting]] - Built-in sort, merge sort, counting sort
- [[Day-12-Binary-Search]] - Templates, BS on answer
- [[Day-13-Recursion]] - Recursion fundamentals, memoization
- [[Day-14-Backtracking]] - Backtracking template, pruning

## Phần 4: Linear Data Structures (Day 15-18)

- [[Day-15-Linked-Lists]] - Singly/doubly, Floyd's cycle
- [[Day-16-Stacks-Monotonic]] - Stack, monotonic stack
- [[Day-17-Queues-Deque]] - Queue, deque, monotonic queue
- [[Day-18-Heaps-Priority-Queue]] - Min/max heap, top K

## Phần 5: Trees & Graphs (Day 19-25)

- [[Day-19-Trees-Basics]] - Tree traversals, DFS, BFS
- [[Day-20-BST-Tree-DP]] - BST operations, tree DP
- [[Day-21-Graphs-Basics]] - Representations, DFS, BFS, components
- [[Day-22-Shortest-Paths]] - Dijkstra, Bellman-Ford, Floyd
- [[Day-23-Topological-Sort]] - Kahn's, DFS-based, DAG DP
- [[Day-24-DSU]] - Union-Find với optimizations
- [[Day-25-MST]] - Kruskal, Prim

## Phần 6: Dynamic Programming (Day 26-29)

- [[Day-26-DP-1D]] - DP fundamentals, 1D patterns
- [[Day-27-DP-2D-Knapsack]] - Grid DP, 0/1 knapsack
- [[Day-28-DP-Patterns]] - LIS, LCS, Edit Distance
- [[Day-29-DP-Bitmask-Tree]] - Bitmask DP, tree DP, digit DP

## Phần 7: Math & Advanced (Day 30-35)

- [[Day-30-Greedy-Intervals]] - Greedy, interval scheduling
- [[Day-31-Bit-Manipulation]] - Bit tricks, XOR
- [[Day-32-Number-Theory]] - GCD, sieve, modular arithmetic
- [[Day-33-Trie]] - Prefix tree, max XOR
- [[Day-34-Segment-Tree-Fenwick]] - Range queries
- [[Day-35-Contest-Strategy]] - Pattern recognition, contest tactics

## Tiến độ

```dataview
TABLE WITHOUT ID
  file.link AS "Ngày",
  length(filter(file.tasks, (t) => t.completed)) + "/" + length(file.tasks) AS "Đã làm",
  topic AS "Chủ đề"
FROM "00 roadmap"
WHERE file.name != "roadmap"
SORT file.name ASC
```

## Lưu ý

- Không cần xong 35 ngày trong 35 ngày thực. Có thể vượt nếu cần.
- Tập trung vào hiểu kỹ thay vì chạy nhanh.
- Mỗi ngày: đọc theory, làm practice, ghi solution vào `01 solutions/`.
- Khi gặp pattern mới hoặc lỗi - cập nhật `03 mistakes/` và `04 tricks/`.

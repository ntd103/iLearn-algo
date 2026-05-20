---
day: 35
topic: Contest Strategy & Pattern Recognition
tags:
  - roadmap
  - contest
created: 2026-05-20
---
# Day 35 - Contest Strategy & Pattern Recognition

## Pattern Recognition

### Constraints suy ra thuật toán

| n | Expected complexity | Algorithms |
|------|---------------------|------------|
| 10^18 | O(1), O(log n) | Math, Bit |
| 10^9 | O(log n), O(sqrt(n)) | Binary search, Math |
| 10^7 | O(n) | Linear, Two-pointer |
| 10^6 | O(n log n) | Sort, Heap, BIT |
| 10^5 | O(n log n), O(n sqrt(n)) | Most algorithms |
| 10^4 | O(n^2) | DP 2D |
| 10^3 | O(n^2 log n), O(n^3) | Dense DP |
| 500 | O(n^3) | Floyd, Matrix DP |
| 100 | O(n^4) | Heavy DP |
| 25 | O(2^n), O(n * 2^n) | Bitmask DP, Backtrack |
| 11 | O(n!) | Permutations |

### Keyword -> Pattern

| Keyword | Likely Pattern |
|---------|----------------|
| "Subarray sum" | Prefix sum, Sliding window |
| "Subsequence" | DP |
| "Sorted array" + "Find" | Binary search, Two pointers |
| "Min/Max with constraint" | DP, Binary search on answer |
| "Count ways" | DP, Combinatorics |
| "Shortest path" | BFS, Dijkstra |
| "All pairs / paths" | DFS, Floyd |
| "Top K" | Heap, Quickselect |
| "Window of size K" | Sliding window |
| "Continuous interval" | Greedy, Sliding window |
| "Connected" | DSU, DFS |
| "Cycle" | DFS, DSU |
| "Prefix matching" | Trie |
| "K-th ..." | Heap, Quickselect, BST |

## Contest Strategy

### Trước contest

- [ ] Setup template với fast I/O
- [ ] Snippets cho DSU, Segment Tree, Dijkstra
- [ ] Test compile với input từ file
- [ ] Đảm bảo môi trường ổn định

### Trong contest

#### Đọc đề

1. Đọc kỹ statement, examples, constraints
2. Note edge cases: n=0, n=1, all same, sorted
3. Vẽ ra giấy với example nhỏ

#### Solve order

- Easy nhất trước (A, B, C theo Codeforces)
- Skip nếu stuck > 15 phút - quay lại sau
- Đảm bảo solution submit được trước khi optimize

#### Plan trước khi code

1. Identify pattern -> chọn algorithm
2. Check complexity với constraints
3. Code hộp/draft trên giấy
4. Implement carefully

#### Debug

1. Test với examples
2. Generate edge cases
3. Stress test nếu có thời gian
4. Đọc lại code

### Sau contest

- [ ] Up-solving: giải các bài chưa giải được
- [ ] Đọc editorial cho bài hay
- [ ] Note pattern mới vào `04 mistakes/` hoặc `05 tricks/`
- [ ] Re-implement từ đầu để nhớ

## Common Bugs Checklist

- [ ] Integer overflow (long long khi cần)
- [ ] Off-by-one trong loop
- [ ] Empty input edge case
- [ ] Negative number trong modulo
- [ ] Uninitialized variables
- [ ] Array bounds
- [ ] Floating point comparison (dùng EPS)

## Resources

### Practice platforms

- **Codeforces**: round contests, lots of problems
- **AtCoder**: clean problems, short duration
- **LeetCode**: interview prep, weekly contests
- **CSES**: structured topic-based problemset

### Study materials

- **CP Handbook** by Antti Laaksonen (free PDF)
- **CP Algorithms** (cp-algorithms.com)
- **USACO Guide** (usaco.guide)
- **Competitive Programming 4** by Steven Halim

### When stuck

1. Brainstorm: brute force, what's the bottleneck?
2. Reverse: thay vì xây kết quả, xem điều gì đặc biệt
3. Rephrase: đề bài thực ra hỏi gì?
4. Look at constraints: chúng gợi ý gì?
5. Sketch examples larger than test

---

## Hết roadmap

Sau khi xong 35 ngày:

- Liên tục practice với LeetCode/Codeforces
- Tham gia contest hàng tuần
- Up-solve các bài contest
- Review `06 review/` đều đặn
- Build template library trong `05 templates/`

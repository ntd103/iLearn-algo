# General DSA Tricks

Tricks chung không phụ thuộc ngôn ngữ.

---

### Sentinel / Dummy nodes
**Khi nào dùng**: Linked list, boundary handling
- Thêm dummy node ở đầu/cuối để tránh xử lý edge case null
- Thêm boundary 0 ở 2 đầu array để tránh check bounds

---

### Reverse thinking
**Khi nào dùng**: Bài yêu cầu "remove" hoặc "destroy"
- Thay vì xóa → nghĩ ngược lại: thêm vào từ cuối
- Union-Find thường dễ hơn khi "add" thay vì "remove"

---

### Contribution technique
**Khi nào dùng**: Tính tổng contribution của mỗi element
- Thay vì tính tổng tất cả subarrays → tính mỗi element đóng góp bao nhiêu subarrays
- Element ở index i đóng góp cho (i+1) * (n-i) subarrays

---

### Prefix XOR
**Khi nào dùng**: XOR queries trên range
```
prefix[i] = a[0] ^ a[1] ^ ... ^ a[i-1]
XOR(l, r) = prefix[r+1] ^ prefix[l]
```

---

### Coordinate compression
**Khi nào dùng**: Giá trị lớn (10^9) nhưng số lượng ít (10^5)
- Sort unique values → map to 0, 1, 2, ...
- Dùng cho Segment Tree, BIT, counting

---

### Meet in the middle
**Khi nào dùng**: n ≤ 40, brute force 2^n quá chậm
- Chia array thành 2 nửa
- Brute force mỗi nửa: 2^(n/2) ≈ 10^6
- Combine results

---

### Sqrt decomposition (mental model)
**Khi nào dùng**: Khi cần trade-off giữa update và query
- Chia array thành √n blocks
- Query: O(√n), Update: O(√n)
- Đơn giản hơn Segment Tree cho một số bài

---

### Binary search on answer
**Khi nào dùng**: "Find minimum X such that condition holds"
- Nếu answer có tính monotonic (true/false boundary)
- Binary search trên answer space, validate với greedy/DP

---

### Two arrays → one sorted event array
**Khi nào dùng**: Interval problems, sweep line
- Tách start/end thành events
- Sort events by time
- Sweep qua và maintain state

---

### Modular arithmetic pitfalls
**Khi nào dùng**: Bài yêu cầu answer mod 10^9+7
```
(a + b) % MOD
(a - b + MOD) % MOD (tránh âm)
(a * b) % MOD
(a / b) % MOD → dùng modular inverse: a * b^(MOD-2) % MOD
```

---

### Graph: virtual source/sink
**Khi nào dùng**: Multi-source BFS/Dijkstra
- Thêm node ảo nối đến tất cả source nodes với weight 0
- Chạy single-source từ node ảo

---

### DP state reduction
**Khi nào dùng**: DP 2D mà chỉ dùng row trước
- dp[i][j] chỉ phụ thuộc dp[i-1][...] → dùng 2 rows hoặc 1 row
- Giảm space từ O(n*m) xuống O(m)

---

### Counting with inclusion-exclusion
**Khi nào dùng**: "Count elements satisfying A OR B OR C"
```
|A ∪ B ∪ C| = |A| + |B| + |C| - |A∩B| - |A∩C| - |B∩C| + |A∩B∩C|
```

---

### Pigeonhole principle
**Khi nào dùng**: Prove existence
- n+1 items in n boxes → at least one box has 2+ items
- Useful for cycle detection, duplicate proofs

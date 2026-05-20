---
day: 08
topic: Sliding Window
tags:
  - roadmap
  - dsa/topics/sliding-window
created: 2026-05-20
---
# Day 08 - Sliding Window

## Lý thuyết

### Fixed-size window

```cpp
int sum = 0;
for (int i = 0; i < k; i++) sum += arr[i];
int ans = sum;

for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i - k];
    ans = max(ans, sum);
}
```

### Variable-size window (expand-shrink)

```cpp
int l = 0, ans = 0;
for (int r = 0; r < n; r++) {
    // expand: add arr[r] to window
    while (window_invalid()) {
        // shrink: remove arr[l]
        l++;
    }
    ans = max(ans, r - l + 1);
}
```

### Khi nào dùng

| Use case | Window type |
|----------|-------------|
| Subarray độ dài k | Fixed |
| Substring không trùng ký tự | Variable |
| Max sum của subarray độ dài >= k | Variable |
| Đếm subarrays thỏa mãn | Variable |

## Practice

### Easy

- [ ] Maximum Average Subarray I (LC #643)
- [ ] Defuse the Bomb (LC #1652)

### Medium

- [ ] Longest Substring Without Repeating Characters (LC #3)
- [ ] Minimum Size Subarray Sum (LC #209)
- [ ] Longest Repeating Character Replacement (LC #424)
- [ ] Permutation in String (LC #567)
- [ ] Fruit Into Baskets (LC #904)
- [ ] Find All Anagrams in a String (LC #438)
- [ ] Subarrays with K Different Integers (LC #992)

### Hard

- [ ] Minimum Window Substring (LC #76)
- [ ] Sliding Window Maximum (LC #239) - dùng monotonic deque

## Tips

- Window điều kiện càng phức tạp, càng cần state (Counter/freq map)
- "Đếm subarrays với đúng K" = "với <=K" - "với <=K-1"

## Mistakes thường gặp

- Quên cập nhật `ans` SAU khi shrink (không phải trong loop shrink)
- Off-by-one: `r - l + 1` cho độ dài window

---

**Next**: [[Day-09-Hashing]]

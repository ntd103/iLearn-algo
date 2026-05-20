---
day: 05
topic: Complexity Analysis & Debugging
tags:
  - roadmap
  - fundamental
created: 2026-05-20
---
# Day 05 - Complexity & Debugging Skills

> **Mục tiêu**: Phân tích complexity, biết khi nào TLE, debug hiệu quả.

## Lý thuyết

### Big O - reminder

| n | Max complexity (1s) |
|------|---------------------|
| 10^9 | O(log n), O(1) |
| 10^8 | O(n) |
| 10^7 | O(n log n) cẩn thận |
| 10^6 | O(n log n) |
| 10^5 | O(n log n), O(n sqrt(n)) |
| 10^4 | O(n^2) |
| 500 | O(n^3) |
| 25 | O(2^n) |
| 11 | O(n!) |

**Quy tắc thực tế**: PC chạy ~10^8 operations/giây trong CP.

### Time complexity rules

```
Drop constants:    O(2n) -> O(n)
Drop non-dominant: O(n^2 + n) -> O(n^2)
Different vars:    O(n + m) - không gộp với O(n)
Nested loops:      multiply
Sequential ops:    add
```

### Space complexity

- Input KHÔNG tính (auxiliary space only)
- Recursion stack tính - O(depth)

### Analysis tricky cases

```cpp
// O(n log n) chứ không phải O(n^2)
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j *= 2) { }
}

// O(n) - amortized
vector<int> v;
for (int i = 0; i < n; i++) {
    v.push_back(i);  // amortized O(1)
}

// O(n) tổng - 2 pointer
int j = 0;
for (int i = 0; i < n; i++) {
    while (j < n && cond) j++;
}
```

## Debugging Techniques

### Print debugging

```cpp
#define dbg(x) cerr << #x << " = " << x << endl

int x = 5;
dbg(x);  // x = 5
```

```cpp
// Print vector
template<typename T>
void pv(const vector<T>& v) {
    for (auto& x : v) cerr << x << " ";
    cerr << endl;
}
```

### Stress testing

Khi không biết bug ở đâu - generate random test, so sánh brute force vs solution:

```bash
# gen.cpp tạo test ngẫu nhiên
# brute.cpp là solution chậm nhưng đúng
# sol.cpp là solution cần test

while true; do
    ./gen > test.in
    ./brute < test.in > brute.out
    ./sol < test.in > sol.out
    diff brute.out sol.out || break
done
```

### Common bugs trong CP

1. **Integer overflow**: dùng `long long` khi sum > 2*10^9
2. **Array out of bounds**: cẩn thận index ở edge case
3. **Off-by-one**: `<` vs `<=`, `n-1` vs `n`
4. **Uninitialized**: variables trong loop, vector size
5. **Mod negative**: `(a - b) % MOD` có thể âm trong C++
   - Fix: `((a - b) % MOD + MOD) % MOD`
6. **Long long literal**: `1 << 31` overflow, dùng `1LL << 31`
7. **double precision**: tránh `==` với double, dùng `abs(a-b) < EPS`

### Edge cases checklist

- [ ] n = 0, n = 1
- [ ] Toàn bộ phần tử giống nhau
- [ ] Đã sorted (tăng/giảm)
- [ ] Số âm, số 0
- [ ] Min/Max của constraint (e.g., 10^9 với int)
- [ ] Duplicate values
- [ ] Empty input

## Practice

### Complexity Analysis

Phân tích complexity của các đoạn code sau:

```cpp
// 1.
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j += i) { }
// Answer: O(n log n) - harmonic series

// 2.
function<void(int)> rec = [&](int n) {
    if (n <= 1) return;
    rec(n/2);
    rec(n/2);
};
// Answer: O(n) - T(n) = 2T(n/2) + O(1)

// 3.
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        for (int k = j; k < n; k++) { }
// Answer: O(n^3) cụ thể là C(n+2, 3)
```

### Debug Practice

- [ ] Stress test 1 bài đã giải - so sánh brute với optimized
- [ ] Tìm bug trong code có overflow (cố tình tạo)
- [ ] Tìm bug off-by-one trong binary search

## Notes

- Estimation skill quan trọng hơn academic Big O
- Test edge cases TRƯỚC khi submit
- Keep `04 mistakes/` updated - mỗi bug học được

---

**Next**: [[Day-06-Arrays-Basics]]

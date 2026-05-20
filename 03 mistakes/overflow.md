---
tags:
  - mistakes
  - dsa/topics/math
created: 2025-06-15
---
# Integer Overflow

Tràn số — silent bug nguy hiểm vì không báo lỗi.

## Khi nào xảy ra

| Kiểu | Range | Nguy hiểm khi |
|------|-------|---------------|
| int (32-bit) | ~2.1 × 10⁹ | n > 46340 mà nhân n*n |
| long long (64-bit) | ~9.2 × 10¹⁸ | Tổng > 10¹⁸ |

## Patterns thường gặp

### Nhân 2 số
```cpp
// SAI — overflow trước khi cast
long long result = a * b;

// ĐÚNG
long long result = (long long)a * b;
```

### Tổng prefix sum
```cpp
// n = 10^5, a[i] = 10^9 → sum tới 10^14
// Phải dùng long long cho prefix sum
```

### Modular arithmetic
```cpp
// Nhân trước khi mod
(a * b) % MOD  // overflow nếu a, b > 10^9

// An toàn
((long long)a * b) % MOD
```

### Binary search mid
```cpp
// Overflow khi lo + hi > INT_MAX
int mid = (lo + hi) / 2;       // nguy hiểm
int mid = lo + (hi - lo) / 2;  // an toàn
```

## Checklist

- [ ] Constraints có n > 10⁴ và cần nhân? → long long
- [ ] Prefix sum với a[i] lớn? → long long
- [ ] Dùng MOD? → cast trước khi nhân
- [ ] Kết quả trung gian có thể > 2×10⁹?

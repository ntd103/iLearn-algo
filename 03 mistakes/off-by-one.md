---
tags:
  - mistakes
  - dsa/topics/array
created: 2025-06-15
---
# Off-by-One Errors

Lỗi lệch 1 đơn vị — phổ biến nhất trong CP.

## Patterns thường gặp

### Loop bounds
- `i < n` vs `i <= n`
- `i = 0` vs `i = 1`
- Mảng 0-indexed vs 1-indexed

### Substring / Subarray
- `substr(pos, len)` — len là số ký tự, không phải end index
- `[left, right]` vs `[left, right)` — inclusive vs exclusive

### Binary Search
- `lo < hi` vs `lo <= hi`
- `mid = (lo + hi) / 2` vs `mid = (lo + hi + 1) / 2`
- Khi nào `hi = mid` vs `hi = mid - 1`

### Fence-post problems
- n phần tử có n-1 khoảng cách
- Đếm segments vs đếm points

## Checklist khi debug

- [ ] Loop có chạy đủ/thừa 1 lần không?
- [ ] Index cuối cùng có đúng không? (n-1 hay n)
- [ ] Kết quả trả về có cần +1/-1 không?
- [ ] Edge case: mảng 1 phần tử, chuỗi rỗng

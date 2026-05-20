---
tags:
  - mistakes
created: 2025-06-15
---
# Logic Errors

Sai logic — code chạy đúng syntax nhưng sai kết quả.

## Patterns thường gặp

### Greedy sai điều kiện
- Chọn locally optimal nhưng không globally optimal
- Quên chứng minh greedy choice property
- Sort sai tiêu chí

### DP sai transition
- Sai base case
- Sai thứ tự duyệt (top-down vs bottom-up direction)
- Thiếu state trong DP definition
- Nhầm min/max

### Điều kiện logic
```cpp
// Nhầm AND/OR
if (a > 0 && b > 0)  // cả hai
if (a > 0 || b > 0)  // ít nhất một

// Nhầm điều kiện dừng
while (left < right)   // không xét left == right
while (left <= right)  // xét cả left == right
```

### Sai hướng duyệt
- Duyệt xuôi khi cần duyệt ngược
- BFS khi cần DFS (hoặc ngược lại)
- Quên visited → infinite loop

### Nhầm biến
- Copy-paste quên đổi tên biến
- `i` vs `j` trong nested loop
- `left` vs `right`

## Checklist

- [ ] Trace bằng tay với example nhỏ
- [ ] Greedy: chứng minh exchange argument
- [ ] DP: kiểm tra base case và transition trên paper
- [ ] Điều kiện: viết truth table nếu phức tạp

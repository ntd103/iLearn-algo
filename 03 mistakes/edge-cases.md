---
tags:
  - mistakes
created: 2025-06-15
---
# Edge Cases

Các trường hợp biên thường bỏ sót.

## Input đặc biệt

### Empty / Single element
- Mảng rỗng `[]` hoặc 1 phần tử `[x]`
- Chuỗi rỗng `""` hoặc 1 ký tự
- n = 0, n = 1

### Giá trị cực trị
- Tất cả giống nhau: `[5,5,5,5]`
- Đã sorted (tăng/giảm)
- Giá trị âm, giá trị 0
- INT_MAX, INT_MIN

### Cấu trúc đặc biệt
- Tree: chỉ có 1 node, skewed tree (linked list)
- Graph: disconnected, self-loop, node đơn lẻ
- String: palindrome, tất cả cùng ký tự

## Patterns hay quên

### Boundary conditions
- Phần tử đầu/cuối mảng không có neighbor
- Node lá trong tree
- Source/sink trong graph

### Kết quả đặc biệt
- Kết quả = 0 (không tìm thấy)
- Kết quả = toàn bộ input
- Kết quả âm khi expect dương

### Division / Modulo
- Chia cho 0
- Modulo số âm (behavior khác nhau giữa C++ và Python)

## Checklist

- [ ] n = 0 hoặc n = 1 có crash không?
- [ ] Tất cả phần tử giống nhau?
- [ ] Giá trị âm / zero?
- [ ] Input đã sorted sẵn?
- [ ] Kết quả có thể rỗng?

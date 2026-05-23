# Phép Toán Modulo trong C++

## 1. Khái niệm
Phép toán modulo (`%`) trong C++ trả về **phần dư** của phép chia hai số nguyên. Kết quả của phép toán này có **dấu giống với số bị chia** (số đầu tiên).

## 2. Quy tắc
- Kết quả của `a % b` có dấu giống với `a`.
- Nếu `a` hoặc `b` là số âm, kết quả được tính dựa trên giá trị tuyệt đối của `a` và `b`, sau đó thêm dấu của `a`.

## 3. Ví dụ
### a) `-7 % 3`
- \( a = -7 \), \( b = 3 \).
- Tính giá trị tuyệt đối: \( | -7 | = 7 \), \( | 3 | = 3 \).
- Tính phần dư: \( 7 \div 3 = 2 \) dư \( 1 \).
- Kết quả: \( -7 \% 3 = -1 \).

### b) `7 % (-3)`
- \( a = 7 \), \( b = -3 \).
- Tính giá trị tuyệt đối: \( | 7 | = 7 \), \( | -3 | = 3 \).
- Tính phần dư: \( 7 \div 3 = 2 \) dư \( 1 \).
- Kết quả: \( 7 \% (-3) = 1 \).

### c) `-7 % (-3)`
- \( a = -7 \), \( b = -3 \).
- Tính giá trị tuyệt đối: \( | -7 | = 7 \), \( | -3 | = 3 \).
- Tính phần dư: \( 7 \div 3 = 2 \) dư \( 1 \).
- Kết quả: \( -7 \% (-3) = -1 \).

## 4. So sánh với Python
- Trong Python, kết quả của phép modulo luôn có dấu giống với số chia (số thứ hai).
- Ví dụ:
  - `-7 % 3` → Kết quả là `2`.
  - `7 % (-3)` → Kết quả là `-2`.
  - `-7 % (-3)` → Kết quả là `-1`.

## 5. Tóm tắt
- Trong C++, kết quả của `a % b` có dấu giống với `a`.
- Kết quả của các phép toán:
  - `-7 % 3` → `-1`
  - `7 % (-3)` → `1`
  - `-7 % (-3)` → `-1`
---
difficulty:
tags:
  - algorithm
  - Math/Modulo
  - cryptography
lastReviewed: 2026-05-19
reviewCount: 6
status: solved
---
>[!question]+ Tìm nghịch đảo $a^{-1} \mod n$
>



# Modular Inverse

Để tìm nghịch đảo của một số $a$ modulo $n$, ta sử dụng **Thuật toán Euclid Mở Rộng**. Thuật toán này không chỉ tìm được ước chung lớn nhất (gcd) của hai số mà còn trả về các hệ số sao cho:

$$
a \cdot x + n \cdot y = \text{gcd}(a, n)
$$

Khi $\text{gcd}(a, n) = 1$, giá trị $x$ chính là **nghịch đảo của $a$ modulo $n$**.

### Thuật toán Euclid Mở Rộng để Tìm Nghịch đảo Modulo và GCD

**Mục tiêu**: Tìm $x$ sao cho $a \cdot x \equiv 1 \pmod{n}$, tức là tìm nghịch đảo của $a$ modulo $n$. Cùng lúc đó, thuật toán này cũng giúp tính **GCD** của hai số $a$ và $n$.

Xem thêm: [[find gcd_extend_euler]]

### Các bước trong thuật toán Euclid Mở Rộng:

1. **Khởi tạo**:
   - $r_0 = n$, $r_1 = a$
   - $t_0 = 0$, $t_1 = 1$ (Hệ số của $n$ và $a$)
   - Tính $q = \left\lfloor \frac{r_0}{r_1} \right\rfloor$

2. **Lặp các bước cho đến khi $r_1 = 0$**:
   - Tính phần dư: $r_2 = r_0 - q \cdot r_1$
   - Cập nhật hệ số: $t_2 = t_0 - q \cdot t_1$
   - Cập nhật giá trị $r_0 = r_1$, $r_1 = r_2$, $t_0 = t_1$, $t_1 = t_2$.

3. **Kết quả**:
   - Khi $r_1 = 1$, nghĩa là **GCD** của $a$ và $n$ là 1, ta có nghịch đảo của $a$ modulo $n$ là $t_1$.
   - Nếu $t_1$ là số âm, bạn có thể cộng $n$ vào để chuyển nó thành một số dương: $t_1 = t_1 + n$.

### Ví dụ: $25^{-1} \mod 101$

Áp dụng thuật toán Euclid mở rộng để tìm nghịch đảo của $25 \mod 101$:

#### Các bước tính toán:

1. **Khởi tạo**:
   - $r_0 = 101$, $r_1 = 25$
   - $t_0 = 0$, $t_1 = 1$

2. **Bước 1**:
   - Tính $q = \left\lfloor \frac{101}{25} \right\rfloor = 4$
   - Cập nhật phần dư: $r_2 = 101 - 4 \cdot 25 = 101 - 100 = 1$
   - Cập nhật hệ số: $t_2 = 0 - 4 \cdot 1 = -4$

   Bảng sau bước 1:

   | Vòng | $r_0$ | $r_1$ | $r_2$ | $q$ | $t_0$ | $t_1$ | $t_2$ |
   |------|-------|-------|-------|-----|-------|-------|-------|
   | 0    | 101   | 25    | 1     | 4   | 0     | 1     | -4    |

3. **Bước 2**:
   - Tính $q = \left\lfloor \frac{25}{1} \right\rfloor = 25$
   - Cập nhật phần dư: $r_3 = 25 - 25 \cdot 1 = 0$
   - Cập nhật hệ số: $t_3 = 1 - 25 \cdot (-4) = 1 + 100 = 101$

   Bảng sau bước 2:

   | Vòng | $r_0$ | $r_1$ | $r_2$ | $q$ | $t_0$ | $t_1$ | $t_2$ |
   |------|-------|-------|-------|-----|-------|-------|-------|
   | 0    | 101   | 25    | 1     | 4   | 0     | 1     | -4    |
   | 1    | 25    | 1     | 0     | 25  | 1     | -4    | 101   |

4. **Kết quả**:
   - Khi $r_2 = 1$, ta biết $GCD(25, 101) = 1$, nghĩa là nghịch đảo tồn tại.
   - Hệ số $t_2 = -4$ là nghịch đảo modulo, nhưng vì nó âm, ta chuyển nó thành số dương bằng cách cộng $101$:
   $$
   t_2 + 101 = -4 + 101 = 97
   $$
   Do đó, $25^{-1} \mod 101 = 97$.

### Tóm tắt Thuật toán:

1. Khởi tạo các giá trị $r_0, r_1, t_0, t_1$.
2. Lặp qua các vòng cho đến khi $r_1 = 1$, tính toán các giá trị $q, r_2, t_2$.
3. Khi $r_2 = 1$, $t_2$ là nghịch đảo của $a$ modulo $n$. Nếu $t_2$ là âm, cộng $n$ để chuyển thành số dương.

Kết quả: $25^{-1} \mod 101 = 97$.

## Source

```cpp
// Hàm tìm GCD và nghịch đảo modulo thông qua thuật toán Euclid mở rộng
int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = gcdExtended(b, a % b, y, x);
    y -= (a / b) * x;

    return gcd;
}

// Hàm tìm nghịch đảo modulo của a với modulo n
int modInverse(int a, int n) {
    int x, y;
    int gcd = gcdExtended(a, n, x, y);
    if (gcd != 1) {
        cout << "Không có nghịch đảo modulo tồn tại." << endl;
        return -1;
    }
    // Đảm bảo kết quả dương
    return (x % n + n) % n;
}
```


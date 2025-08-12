---
difficulty: 
tags:
  - dsa/Problem
  - algorithm
  - cryptography
  - Math
---
>[!question]+

# exponentiation_by_squaring

## Mô tả
Thuật toán **bình phương và nhân** là một phương pháp hiệu quả để tính lũy thừa $a^b$ theo mô đun $n$ (tính $a^b \mod n$) với độ phức tạp $O(\log b)$. Thuật toán này rất hữu ích trong các ứng dụng yêu cầu tính toán lũy thừa lớn, như mật mã học và kiểm tra số nguyên tố.

## Ý tưởng cơ bản
- Thay vì tính lũy thừa bằng cách nhân dần $a$ với chính nó $b$ lần (độ phức tạp $O(b)$), thuật toán này chia $b$ thành các phần nhỏ hơn, cho phép giảm số phép nhân cần thực hiện.

## Nguyên tắc hoạt động
1. **Nếu $b$ là số chẵn**, ta có:
   $$
   a^b = (a^{b/2})^2
   $$
   Tức là, thay vì nhân $a$ với chính nó $b$ lần, ta chỉ cần tính $a^{b/2}$ và bình phương kết quả.
   
2. **Nếu $b$ là số lẻ**, ta có:
   $$
   a^b = a \cdot a^{b-1}
   $$
   Trong trường hợp này, ta tách ra một phép nhân, và phần còn lại $a^{b-1}$ được tính bằng phương pháp bình phương và nhân.

## Giả mã thuật toán

```pseudocode
MODULE calcExponent(a, b, n)
    // Biểu diễn b dưới dạng nhị phân
    f = 1
    for i = k downto 0 do
        f = (f * f) mod n
        if b_i = 1 then
            f = (f * a) mod n
        end_if
    end_for
    return f
END MODULE

```

1. **Khởi tạo:** 
   - Biến `f` được khởi tạo là 1.
   - `b` là số cần tính lũy thừa modulo.
   - Đổi b ra bin có k số

2. **Kiểm tra bit:** 
   - Kiểm tra bit thấp nhất của `b`. Nếu bit này là 1, nhân `f` với `a`.
   - Sau đó, bình phương giá trị `a`.

3. **Dịch phải b:**
   - Mỗi lần xử lý một bit của `b`, dịch phải `b` để kiểm tra bit tiếp theo.

4. **Kết quả:** 
   - Khi `b` bằng 0, trả về giá trị `f`.


```cpp
int modular_exponent(int a, int b, int n) {
    int f = 1; // Biến f khởi tạo là 1, dùng để lưu trữ kết quả trung gian.
    int len = log2(b) + 1; // số bit = [log_2(b)] + 1
    
    // Duyệt qua từng bit của b từ trái (bit cao nhất) sang phải (bit thấp nhất).
    for (int i = len - 1; i >= 0; --i) {
        // Bình phương f và lấy modulo n để đảm bảo kết quả nằm trong khoảng [0, n-1].
        f = (f * f) % n;
        
        // Kiểm tra xem bit thứ i của b có phải là 1 hay không.
        if ((b >> i) & 1) {
            // Nếu bit thứ i là 1, nhân thêm f với a và lấy modulo n.
            f = (f * a) % n;
        }
    }
    
    // Trả về kết quả cuối cùng là a^b % n.
    return f;
}
```

```plaintext
function powerMod(a, b, n):
    result = 1
    a = a % n  // Lấy dư ban đầu để đảm bảo a < n

    while b > 0:
        if b is odd:
            result = (result * a) % n  // Nếu b lẻ, nhân thêm a vào kết quả
        a = (a * a) % n  // Bình phương a
        b = b // 2  // Chia b cho 2 (dịch phải 1 bit)
    
    return result
```

```cpp
// Hàm tính a^b mod n
long long powerMod(long long a, long long b, long long n) {
    long long result = 1;
    a = a % n; // Lấy dư ban đầu để đảm bảo a < n
    while (b > 0) {
        // Nếu b là số lẻ, nhân thêm a vào kết quả
        if (b % 2 == 1) {
            result = (result * a) % n;
        }
        // Bình phương a
        a = (a * a) % n;
        // Chia b cho 2 (dịch phải 1 bit)
        b >>= 1; //dịch phải 1 bit => chia 2^1, dịch bit hiệu suất hơn
    }
    return result;
}
```

```cpp
long long powerMod(long long a, long long b, long long n) {
    long long result = 1;
    a %= n; // để a < n
    while (b > 0) {
        if (b & 1) result = (result * a) % n;
        a = (a * a) % n;
        b >>= 1; //dịch phải 1 bit => chia 2^1
    }
    return result;
}
```

## Ví dụ minh họa:

Giả sử ta cần tính $3^{13} \mod 7$:

1. $13$ là số lẻ → $result = 3$, $a = 3^2 = 9 \equiv 2 \mod 7$, $b = 6$
2. $6$ là số chẵn → $a = 2^2 = 4 \mod 7$, $b = 3$
3. $3$ là số lẻ → $result = (3 \cdot 4) \mod 7 = 12 \equiv 5 \mod 7$, $a = 4^2 = 16 \equiv 2 \mod 7$, $b = 1$
4. $1$ là số lẻ → $result = (5 \cdot 2) \mod 7 = 10 \equiv 3 \mod 7$, $b = 0$
Kết quả cuối cùng là $3^{13} \mod 7 = 3$.

**Độ phức tạp:**
Thuật toán chạy trong $O(\log b)$ phép nhân, giúp tính lũy thừa nhanh chóng ngay cả với các giá trị $b$ lớn.

**Ứng dụng:**
- Mật mã học: Tính lũy thừa mô đun trong các thuật toán như RSA, Diffie-Hellman.
- Kiểm tra số nguyên tố: Trong thuật toán Miller-Rabin và các thuật toán liên quan.
- Đồ họa máy tính và tính toán khoa học: Các tính toán yêu cầu lũy thừa lớn. 




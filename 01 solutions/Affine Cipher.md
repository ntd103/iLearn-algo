---
difficulty:
tags:
  - algorithm
  - cipher
  - cryptography
lastReviewed: 2026-05-19
reviewCount: 6
status: solved
---
>[!question]+

# Affine Cipher

## Thuật toán

P = C = $Z_n$, K = {a, b thuộc $Z_n * Z_n$ với $\gcd(a,n) = 1$} tức a và n là 2 số nguyên tố cùng nhau (cógcd = 1) để tồn tại $a^{-1} \mod n$ 

$e_k(x) = (ax + b) \mod n$
$d_k(y) = (a^{-1} * (y-b)) \mod n$
## Mã

**Hàm kiểm tra hệ affine có tồn tại không? -> gọi gcd(a, n)**

```cpp
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

```cpp
string affineEncode(string p, int x, int y) {
    string c = "";
    for(char ch : p)
        if(isalpha(ch))
            c += (x*(toupper(ch)-'A') + y) % 26 + 'A';
    return c;
}

string affineDecode(string c, int x, int y) {
    string p = "";
    int x_inv = 0;

	// dò tìm nghịch đảo
    for(int i = 0; i < 26; i++)
        if((x*i) % 26 == 1) {
            x_inv = i;
            break;
        }
    for(char ch : c)
        if(isalpha(ch)) 
            p += (x_inv*((toupper(ch)-'A') - y + 26)) % 26 + 'A';
    return p;
}
```

```cpp
// Hàm tìm nghịch đảo của x mod 26 bằng Thuật toán Euclid mở rộng
int modInverse(int x, int mod) {
    int t = 0, newT = 1;
    int r = mod, newR = x;
    while (newR != 0) {
        int quotient = r / newR;
        t = t - quotient * newT;
        r = r - quotient * newR;
        swap(t, newT);
        swap(r, newR);
    }
    if (r > 1) return -1; // Không có nghịch đảo
    if (t < 0) t = t + mod;
    return t;
}

string affineEncode(string p, int x, int y) {
    string c = "";
    for (char ch : p) {
        if (isalpha(ch)) {
            c += (x * (toupper(ch) - 'A') + y) % 26 + 'A';
        } else {
            c += ch;  // Giữ nguyên ký tự không phải chữ cái
        }
    }
    return c;
}

string affineDecode(string c, int x, int y) {
    string p = "";
    int x_inv = modInverse(x, 26);  // Tìm nghịch đảo của x mod 26
    if (x_inv == -1) {
        cerr << "Nghịch đảo không tồn tại!" << endl;
        return "";
    }

    for (char ch : c) {
        if (isalpha(ch)) {
            p += (x_inv * ((toupper(ch) - 'A') - y + 26)) % 26 + 'A';
        } else {
            p += ch;  // Giữ nguyên ký tự không phải chữ cái
        }
    }
    return p;
}
```

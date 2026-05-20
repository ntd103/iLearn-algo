---
difficulty: Easy
tags:
  - dsa/Problem
  - cryptography
  - algorithm
  - cipher
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+
>Thuật toán mã hóa cổ điển caesar

# Caesar cipher

```cpp
string caesar_encode(string s, int k) {
    string res = "";
    for (char c : s) {
        if (isalpha(c)) {
            res += (toupper(c) - 'A' + k) % 26 + 'A';
        } else {
            res += c;
        }
    }
    return res;
}

string caesar_decode(string s, int k) {
    return caesar_encode(s, 26 - (k % 26));
}
```

## Công thức

```
E = (i + shift) mod 26
D = (i - shift) mod 26
```

```ad-tip
title: Chuẩn hóa shift
shift > 26 => shift = shift mod 26
```

```ad-warning
title: Số âm khi decrypt
Nếu (i - shift) < 0 => cộng thêm 26
=> (i - shift + 26)
để giữ kết quả nằm trong $Z_{26}$
lấy từ kết quả $a \mod b = n$ => $(a + n) \equiv b \mod n$ 
--- 

Nếu shift (i - shift + 26) vẫn âm thì chuẩn hóa shift
```

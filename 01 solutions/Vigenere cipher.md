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

# Vigenere cipher

## Tiền xử lý khóa (bỏ space)

```cpp
//Tiền xử lý khóa
string preprocessKey(const string &key) {
    string cleanedKey = "";
    for (char c : key) {
        if (isalpha(c)) { // Chỉ giữ ký tự chữ cái
            cleanedKey += toupper(c); // Chuyển về chữ in hoa để đồng nhất
        }
    }
    return cleanedKey;
}

string vigenere_crypt(string t, string k, bool enc) {
    string res = "";
    k = preproces_key(k);
    for (int i = 0, j = 0; i != t.size(); ++i) {
        if (isalpha(t[i])) {
            char k_char = k[j++ % k.size()];
            // if decrypting, negate the key
            char shift = enc ? (k_char - 'A') : (26 - k_char + 'A');

            res += (toupper(t[i]) - 'A' + shift) % 26 + 'A';
        } else {
            res += t[i];
        }
    }
    return res;
}

string find_key(string p, string c) {
    string res = "";
    for (int i = 0; i != p.size(); ++i) {
        if (isalpha(p[i])) {
            res += (toupper(c[i]) - toupper(p[i]) + 26) % 26 + 'A';
        }
    }
    return res;
}

//
```

```ad-error
title: Lỗi hay mắc phải
1. Không xử lý space trong key và space trong plaintext
2. Cần biến đếm riêng cho key để không xử lý các index chứa space của plaintext
```


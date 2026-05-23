---
day: 01
topic: C++ Setup & Fast I/O
tags:
  - roadmap
  - cpp
created: 2026-05-20
---
# Day 01 - C++ Setup & Fast I/O cho CP

> **Mục tiêu**: Setup C++ environment cho competitive programming, master fast I/O.

## Lý thuyết

### Compile flags cho CP

```bash
g++ -std=c++17 -O2 -Wall solution.cpp -o solution
```

- `-std=c++17` hoặc `c++20`: dùng features mới
- `-O2`: optimization (BẮT BUỘC khi submit)
- `-Wall`: warnings để bắt bugs sớm

### Template chuẩn cho CP

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=(a); i<(b); i++)

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // code here
    
    return 0;
}
```

### Fast I/O

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

- `sync_with_stdio(false)`: tách C và C++ stream, tăng tốc cin/cout 5-10x
- `cin.tie(NULL)`: không flush cout trước mỗi cin
- **Lưu ý**: Sau khi tắt sync, KHÔNG được dùng `printf/scanf` cùng `cin/cout`

### scanf/printf vs cin/cout

| Method | Speed | Note |
|--------|-------|------|
| scanf/printf | Nhanh nhất | Cú pháp rườm rà |
| cin/cout (no sync) | Tương đương | Khuyến khích |
| cin/cout (sync) | Chậm 5-10x | Mặc định, tránh dùng |

### `endl` vs `"\n"`

```cpp
cout << x << endl;  // Flush buffer mỗi lần - CHẬM
cout << x << "\n";  // Không flush - NHANH
```

Trong CP luôn dùng `"\n"`.

## Programming

### String

`str.substr(pos,len)` Cắt chuỗi con, từ vị trí pos độ dài len

### Math

trong `include <numeric>`

- `gcd(integer1, integer2)` 

trong `include <algorithm>`

- `max(a, b, comparator)`
- `max_element(arr.begin(), arr.end())` return a iterator refer to max elm, call value via `*` 

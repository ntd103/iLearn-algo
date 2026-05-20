# C++ Tricks & Competitive Idioms

### Fast I/O
**Khi nào dùng**: Mọi bài competitive
```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```
**Tại sao**: Tắt sync giữa C và C++ streams, tăng tốc I/O ~5-10x

---

### Đọc cả dòng sau khi đọc số
**Khi nào dùng**: Input có mix số và string
```cpp
int n; cin >> n;
cin.ignore(); // bỏ '\n' còn sót
string s; getline(cin, s);
```

---

### Lambda sort custom
**Khi nào dùng**: Sort theo nhiều tiêu chí
```cpp
sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
 if (a.first != b.first) return a.first < b.first;
 return a.second > b.second;
});
```

---

### __builtin functions
**Khi nào dùng**: Bit manipulation
```cpp
__builtin_popcount(x) // đếm bit 1 (int)
__builtin_popcountll(x) // đếm bit 1 (long long)
__builtin_clz(x) // leading zeros
__builtin_ctz(x) // trailing zeros
__builtin_parity(x) // parity (odd number of 1s)
```

---

### Iterate subsets of a bitmask
**Khi nào dùng**: Bitmask DP, enumerate subsets
```cpp
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
 // process subset 'sub' of 'mask'
}
// don't forget empty subset (sub = 0)
```

---

### Ordered set (policy-based)
**Khi nào dùng**: Cần find_by_order / order_of_key
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
 tree_order_statistics_node_update> ordered_set;

ordered_set os;
os.find_by_order(k); // iterator to k-th element (0-indexed)
os.order_of_key(x); // number of elements < x
```

---

### Avoid TLE with unordered_map
**Khi nào dùng**: Khi unordered_map bị hack (Codeforces)
```cpp
struct custom_hash {
 size_t operator()(uint64_t x) const {
 x ^= x >> 33;
 x *= 0xff51afd7ed558ccdULL;
 x ^= x >> 33;
 return x;
 }
};
unordered_map<int, int, custom_hash> mp;
```

---

### Compress coordinates
**Khi nào dùng**: Giá trị lớn nhưng cần index nhỏ (segment tree, BIT)
```cpp
vector<int> vals = /* all values */;
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());
// compress: index of x = lower_bound(vals.begin(), vals.end(), x) - vals.begin()
```

---

### Multi-test case reset
**Khi nào dùng**: Nhiều test case, cần reset state
```cpp
// Dùng fill thay vì memset cho safety
fill(dist, dist + n + 1, INF);
// Hoặc dùng vector và resize
vector<int> dp(n + 1, 0);
```

---

### Đọc đến EOF
**Khi nào dùng**: Input không cho biết số lượng test
```cpp
int x;
while (cin >> x) {
 // process
}
```

---

### Pair/Tuple sort tự động
**Khi nào dùng**: Sort theo first rồi second tự động
```cpp
vector<pair<int,int>> v;
sort(v.begin(), v.end()); // sort by first, then second
// Nếu muốn sort by second: dùng {second, first} hoặc lambda
```

---

### INT_MAX overflow trap
**Khi nào dùng**: Khi cộng/nhân có thể overflow
```cpp
// Sai: dist[u] + w có thể overflow nếu dist[u] = INT_MAX
if (dist[u] + w < dist[v])

// Đúng: check trước
if (dist[u] != INT_MAX && dist[u] + w < dist[v])

// Hoặc dùng long long
```

---

### emplace_back vs push_back
**Khi nào dùng**: Tạo object trực tiếp trong vector
```cpp
vector<pair<int,int>> v;
v.push_back({1, 2}); // OK từ C++11
v.emplace_back(1, 2); // construct in-place, slightly faster
```

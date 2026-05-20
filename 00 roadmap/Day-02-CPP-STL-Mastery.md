---
day: 02
topic: C++ STL Mastery
tags:
  - roadmap
  - cpp
created: 2026-05-20
---
# Day 02 - C++ STL Mastery cho CP

> **Mục tiêu**: Master STL containers, iterators, algorithms.

## Lý thuyết

### Containers chính

#### vector - dynamic array

```cpp
vector<int> v;
v.push_back(x);          // O(1) amortized
v.pop_back();            // O(1)
v[i];                    // O(1) access
v.size(); v.empty();
v.resize(n, 0);          // resize và init bằng 0
v.clear();
sort(v.begin(), v.end());

// 2D vector
vector<vector<int>> grid(n, vector<int>(m, 0));
```

#### map / unordered_map

```cpp
map<string, int> mp;     // sorted, O(log n)
unordered_map<int, int> ump;  // hash, O(1) avg

mp[key] = value;
mp.count(key);           // 0 hoặc 1
mp.erase(key);
for (auto& [k, v] : mp) { /* ... */ }

// Lưu ý: mp[key] tạo entry mới nếu chưa có!
// Dùng mp.count(key) hoặc mp.find(key) để check tồn tại
```

#### set / unordered_set

```cpp
set<int> s;              // sorted unique
s.insert(x);
s.erase(x);
s.count(x);
auto it = s.lower_bound(x);  // smallest >= x
auto it = s.upper_bound(x);  // smallest > x
```

#### priority_queue

```cpp
priority_queue<int> maxPQ;  // max-heap mặc định
priority_queue<int, vector<int>, greater<int>> minPQ;

maxPQ.push(x);
maxPQ.top();
maxPQ.pop();
```

#### stack / queue / deque

```cpp
stack<int> st;
st.push(x); st.top(); st.pop();

queue<int> q;
q.push(x); q.front(); q.pop();

deque<int> dq;          // 2 đầu O(1)
dq.push_front(x); dq.push_back(x);
dq.pop_front(); dq.pop_back();
```

### Algorithms hữu ích

```cpp
sort(all(v));
sort(all(v), greater<int>());        // descending
reverse(all(v));
*max_element(all(v));
*min_element(all(v));
accumulate(all(v), 0LL);             // sum, dùng 0LL tránh overflow
count(all(v), x);
find(all(v), x);                     // returns iterator
binary_search(all(v), x);            // bool, v phải sorted
lower_bound(all(v), x);              // iterator first >= x
upper_bound(all(v), x);              // iterator first > x
next_permutation(all(v));            // generate next perm
unique(all(v));                      // remove consecutive duplicates
v.erase(unique(all(v)), v.end());    // dedupe (cần sort trước)
__gcd(a, b);                         // GCD (built-in)
__builtin_popcount(x);               // count 1 bits in int
__builtin_popcountll(x);             // count 1 bits in long long
__builtin_clz(x);                    // leading zeros
__builtin_ctz(x);                    // trailing zeros
```

### Pair & Tuple

```cpp
pair<int,int> p = {1, 2};
p.first; p.second;

tuple<int, string, double> t = {1, "abc", 3.14};
auto [a, b, c] = t;     // structured binding (C++17)
```

### String operations

```cpp
string s = "hello";
s.size(); s.length();
s.substr(pos, len);
s.find("ll");           // returns string::npos nếu không tìm thấy
s.replace(pos, len, "xyz");
to_string(123);
stoi("123"); stoll("123");
reverse(all(s));
```

## Tricks cho CP

### Sort với custom comparator

```cpp
sort(all(v), [](const pii& a, const pii& b) {
    return a.second < b.second;  // sort by second
});
```

### Coordinate compression

```cpp
vector<int> sorted_vals = v;
sort(all(sorted_vals));
sorted_vals.erase(unique(all(sorted_vals)), sorted_vals.end());
// index của x = lower_bound(all(sorted_vals), x) - sorted_vals.begin()
```

## Practice

### Easy

- [ ] Tạo vector chứa 10 số, sort tăng dần, in ra
- [ ] Đếm tần suất bằng map: input "abc bcd abc" -> "abc:2, bcd:1"
- [ ] Kth largest element bằng priority_queue
- [ ] Two Sum (LC #1) - dùng unordered_map

### Medium

- [ ] Group Anagrams (LC #49) - dùng map<string, vector<string>>
- [ ] Top K Frequent Elements (LC #347)
- [ ] LRU Cache (LC #146) - kết hợp list và unordered_map

## Notes

- Pattern: hash map cho O(1) lookup, ordered set khi cần lower/upper_bound
- Tránh: `mp[key]` khi chỉ check tồn tại (tạo entry rỗng)

---

**Next**: [[Day-03-Python-Setup-CP]]

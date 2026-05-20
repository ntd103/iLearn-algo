---
tags:
  - mistakes
created: 2025-06-15
---
# Implementation Errors

Code đúng ý tưởng nhưng sai khi implement.

## Patterns thường gặp

### STL / Library misuse
```cpp
// erase trong khi iterate → undefined behavior
for (auto it = v.begin(); it != v.end(); it++) {
    if (*it == x) v.erase(it);  // SAI
}
// ĐÚNG: it = v.erase(it) hoặc dùng remove-erase idiom

// priority_queue mặc định là max-heap
priority_queue<int> pq;  // max-heap
priority_queue<int, vector<int>, greater<int>> pq;  // min-heap

// map[] tạo entry mới nếu key không tồn tại
if (mp[key] == 0)  // tạo key với value 0!
if (mp.count(key))  // check tồn tại đúng cách
```

### String handling
```cpp
// to_string rồi so sánh → lexicographic, không phải numeric
"9" > "10"  // true! (lexicographic)

// substr(pos, len) — len không phải end index
s.substr(2, 3)  // 3 ký tự từ vị trí 2
```

### Recursion
- Quên return value trong recursive call
- Quên base case → stack overflow
- Pass by value thay vì reference → TLE

### Sorting custom comparator
```cpp
// Comparator phải strict weak ordering
// SAI: return a <= b (không strict)
// ĐÚNG: return a < b
sort(v.begin(), v.end(), [](int a, int b) {
    return a < b;  // strict less-than
});
```

### Bit manipulation
```cpp
// Operator precedence: & có priority thấp hơn ==
if (x & 1 == 0)    // SAI: parsed as x & (1 == 0)
if ((x & 1) == 0)  // ĐÚNG
```

## Checklist

- [ ] Container có bị modify trong khi iterate?
- [ ] Comparator có strict weak ordering?
- [ ] Recursive function có return đúng?
- [ ] Bit operations có đủ parentheses?
- [ ] Pass by reference hay value?

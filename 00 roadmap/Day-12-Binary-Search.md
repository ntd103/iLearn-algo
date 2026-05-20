---
day: 12
topic: Binary Search
tags:
  - roadmap
  - dsa/topics/binary-search
created: 2026-05-20
---
# Day 12 - Binary Search

## Lý thuyết

### Template chuẩn

```cpp
// Tìm target trong sorted array
int binary_search(vector<int>& a, int target) {
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        else if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### Lower bound / Upper bound

```cpp
// First index with a[i] >= target
int lower_bound(vector<int>& a, int target) {
    int lo = 0, hi = a.size();  // hi = n, không phải n-1
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // lo == n nếu không có
}

// First index with a[i] > target
int upper_bound(vector<int>& a, int target) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

### Binary Search on Answer

Tìm giá trị nhỏ nhất / lớn nhất thỏa mãn predicate monotonic.

```cpp
// Min x such that check(x) == true
int lo = MIN_X, hi = MAX_X;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
}
return lo;

// Max x such that check(x) == true
int lo = MIN_X, hi = MAX_X;
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;  // chú ý: round up
    if (check(mid)) lo = mid;
    else hi = mid - 1;
}
return lo;
```

### Binary Search on Float

```cpp
double lo = 0, hi = 1e9;
for (int iter = 0; iter < 100; iter++) {
    double mid = (lo + hi) / 2;
    if (check(mid)) hi = mid;
    else lo = mid;
}
// lo == hi (gần như)
```

100 iterations đủ cho precision 1e-30.

### Đặc điểm cần có

- Monotonic predicate: `[F F F F T T T T]`
- Tìm boundary giữa F và T

## Patterns

### Capacity / Speed problems

```
"Tốc độ tối thiểu để hoàn thành công việc trong K giờ"
- check(speed): tổng giờ cần với tốc độ này <= K
- Binary search trên speed, tìm min thỏa mãn
```

### Subarray sum >= K

Khi prefix monotonic, dùng binary search trên prefix.

### Peak finding

```cpp
// Tìm peak (a[i] > a[i-1] && a[i] > a[i+1])
int lo = 0, hi = n - 1;
while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] < a[mid + 1]) lo = mid + 1;
    else hi = mid;
}
return lo;
```

## Common Bugs

- Infinite loop: `lo = mid` thay vì `lo = mid + 1`
- Overflow: `(lo + hi) / 2` với lo, hi lớn -> dùng `lo + (hi - lo) / 2`
- Off-by-one: `hi = n` vs `hi = n-1` tùy template

## Practice

### Easy

- [ ] Binary Search (LC #704)
- [ ] First Bad Version (LC #278)
- [ ] Search Insert Position (LC #35)
- [ ] Sqrt(x) (LC #69)

### Medium

- [ ] Find First and Last Position (LC #34)
- [ ] Search in Rotated Sorted Array (LC #33)
- [ ] Find Peak Element (LC #162)
- [ ] Koko Eating Bananas (LC #875) - BS on answer
- [ ] Capacity To Ship Packages (LC #1011) - BS on answer
- [ ] Find Minimum in Rotated Sorted Array (LC #153)
- [ ] Search a 2D Matrix (LC #74)

### Hard

- [ ] Median of Two Sorted Arrays (LC #4)
- [ ] Split Array Largest Sum (LC #410) - BS on answer

---

**Next**: [[Day-13-Recursion]]

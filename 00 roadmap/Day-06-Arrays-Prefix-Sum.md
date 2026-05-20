---
day: 06
topic: Arrays - Prefix Sum & Difference Array
tags:
  - roadmap
  - dsa/topics/array
  - dsa/topics/prefix-sum
created: 2026-05-20
---
# Day 06 - Arrays: Prefix Sum & Difference Array

## Lý thuyết

### Prefix Sum 1D

Tính tổng đoạn `[l, r]` trong O(1) sau O(n) preprocessing.

```cpp
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] + arr[i];

// sum(arr[l..r]) = prefix[r+1] - prefix[l]
```

### Prefix Sum 2D

```cpp
// pref[i][j] = sum của rect (0,0) -> (i-1, j-1)
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];

// sum của rect (r1,c1) -> (r2,c2):
// pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]
```

### Difference Array

Update `[l, r]` += val nhiều lần trong O(1), query value tại i sau.

```cpp
vector<int> diff(n + 1, 0);

// update [l..r] += val
diff[l] += val;
diff[r + 1] -= val;

// final array
vector<int> arr(n);
arr[0] = diff[0];
for (int i = 1; i < n; i++)
    arr[i] = arr[i-1] + diff[i];
```

### Khi nào dùng

| Pattern | Use case |
|---------|----------|
| Prefix sum | Query sum [l,r] không update |
| Difference | Update [l,r] += val, query final |
| Cả hai | Static problem |

## Practice

### Easy

- [ ] Running Sum of 1d Array (LC #1480)
- [ ] Range Sum Query - Immutable (LC #303)

### Medium

- [ ] Range Sum Query 2D (LC #304)
- [ ] Subarray Sum Equals K (LC #560) - prefix + hashmap
- [ ] Continuous Subarray Sum (LC #523)
- [ ] Product of Array Except Self (LC #238) - prefix + suffix
- [ ] Corporate Flight Bookings (LC #1109) - difference array

## Mistakes thường gặp

- Quên `+1` size của prefix array
- Index lầm: `pref[r+1] - pref[l]` không phải `pref[r] - pref[l]`
- Long long cho sum khi a[i] lớn

---

**Next**: [[Day-07-Two-Pointers]]

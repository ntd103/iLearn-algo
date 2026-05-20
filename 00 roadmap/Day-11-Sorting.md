---
day: 11
topic: Sorting Algorithms
tags:
  - roadmap
  - dsa/topics/sorting
created: 2026-05-20
---
# Day 11 - Sorting Algorithms

## Lý thuyết

### Comparison của các thuật toán sort

| Algorithm | Best | Avg | Worst | Space | Stable |
|-----------|------|-----|-------|-------|--------|
| Bubble | O(n) | O(n^2) | O(n^2) | O(1) | Yes |
| Selection | O(n^2) | O(n^2) | O(n^2) | O(1) | No |
| Insertion | O(n) | O(n^2) | O(n^2) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n^2) | O(log n) | No |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes |
| Radix | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | O(n+k) | Yes |

### Built-in sort

```cpp
sort(all(v));                           // ascending
sort(all(v), greater<int>());           // descending
sort(all(v), [](int a, int b) {         // custom
    return a > b;
});
stable_sort(all(v));                    // giữ thứ tự equal
```

```python
arr.sort()
arr.sort(reverse=True)
arr.sort(key=lambda x: -x)
sorted(arr, key=lambda x: (x[0], -x[1]))  # multi-key
```

### Merge Sort - implement

```cpp
void merge_sort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = l; k <= r; k++) a[k] = tmp[k - l];
}
```

### Counting Sort

```cpp
// Khi range nhỏ (k <= 10^6)
void counting_sort(vector<int>& a, int max_val) {
    vector<int> cnt(max_val + 1, 0);
    for (int x : a) cnt[x]++;
    int idx = 0;
    for (int v = 0; v <= max_val; v++)
        while (cnt[v]--) a[idx++] = v;
}
```

### Khi nào dùng cái nào

- **n <= 10^7, range nhỏ**: counting sort
- **General**: built-in (introsort - kết hợp quick + heap)
- **Stable required**: stable_sort
- **Memory tight**: heap sort
- **Custom logic**: merge sort (dễ modify)

## Patterns

### Sort theo nhiều tiêu chí

```cpp
sort(all(v), [](const pii& a, const pii& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
});
```

### Sort indices (giữ index gốc)

```cpp
vector<int> idx(n);
iota(all(idx), 0);
sort(all(idx), [&](int a, int b) {
    return v[a] < v[b];
});
```

### Inversion count - Merge Sort

```cpp
ll merge_count(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    ll cnt = merge_count(a, l, mid) + merge_count(a, mid + 1, r);
    
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else {
            tmp.push_back(a[j++]);
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = l; k <= r; k++) a[k] = tmp[k - l];
    return cnt;
}
```

## Practice

### Easy

- [ ] Sort an Array (LC #912)
- [ ] Merge Sorted Array (LC #88)

### Medium

- [ ] Sort Colors (LC #75) - 3-way partition
- [ ] Kth Largest Element in Array (LC #215) - quickselect
- [ ] Largest Number (LC #179) - custom comparator
- [ ] Sort Characters By Frequency (LC #451)
- [ ] Reverse Pairs (LC #493) - inversion count

---

**Next**: [[Day-12-Binary-Search]]

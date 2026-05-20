---
day: 09
topic: Hashing - Maps & Sets
tags:
  - roadmap
  - dsa/topics/hashing
created: 2026-05-20
---
# Day 09 - Hashing

## Lý thuyết

### Hash Map operations

| Operation | C++ unordered_map | Python dict | Avg | Worst |
|-----------|-------------------|-------------|-----|-------|
| Insert | `mp[k] = v` | `d[k] = v` | O(1) | O(n) |
| Delete | `mp.erase(k)` | `del d[k]` | O(1) | O(n) |
| Lookup | `mp.count(k)` | `k in d` | O(1) | O(n) |

### map vs unordered_map

| Feature | map | unordered_map |
|---------|-----|---------------|
| Ordering | Sorted | None |
| Underlying | RB tree | Hash table |
| Lookup | O(log n) | O(1) avg |
| Memory | Less | More |
| Use when | Cần range/sorted | Pure lookup |

### Anti-hash attack (Codeforces)

`unordered_map<int, int>` có thể bị attack bằng các integer trùng hash. Fix:

```cpp
struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        x = x ^ (x >> 31);
        return x;
    }
};

unordered_map<long long, int, custom_hash> safe_map;
```

### Patterns

#### Frequency counting

```cpp
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;
```

#### Two Sum

```cpp
unordered_map<int, int> seen;
for (int i = 0; i < n; i++) {
    int need = target - arr[i];
    if (seen.count(need)) return {seen[need], i};
    seen[arr[i]] = i;
}
```

#### Group anagrams - sort key

```cpp
unordered_map<string, vector<string>> groups;
for (string& s : strs) {
    string key = s;
    sort(all(key));
    groups[key].push_back(s);
}
```

## Practice

### Easy

- [ ] Two Sum (LC #1)
- [ ] Contains Duplicate (LC #217)
- [ ] Valid Anagram (LC #242)
- [ ] First Unique Character (LC #387)
- [ ] Intersection of Two Arrays (LC #349)
- [ ] Ransom Note (LC #383)

### Medium

- [ ] Group Anagrams (LC #49)
- [ ] Top K Frequent Elements (LC #347)
- [ ] Subarray Sum Equals K (LC #560)
- [ ] Longest Consecutive Sequence (LC #128)
- [ ] LRU Cache (LC #146)

## Mistakes thường gặp

- `mp[key]` tạo entry mới nếu chưa có - dùng `count()` để check
- Quên reset map giữa các testcase
- Hash collision attack trong contest competitive

---

**Next**: [[Day-10-Strings-Pattern-Matching]]

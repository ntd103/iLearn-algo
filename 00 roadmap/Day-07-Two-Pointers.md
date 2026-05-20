---
day: 07
topic: Two Pointers Technique
tags:
  - roadmap
  - dsa/topics/two-pointers
created: 2026-05-20
---
# Day 07 - Two Pointers

## Lý thuyết

3 dạng chính:

### 1. Opposite ends (2 đầu)

```cpp
int l = 0, r = n - 1;
while (l < r) {
    if (cond) l++;
    else r--;
}
```

Use case: 2 sum sorted, palindrome check, container with most water.

### 2. Same direction (slow-fast)

```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (cond) {
        // process arr[slow], arr[fast]
        slow++;
    }
}
```

Use case: remove duplicates, partition array.

### 3. Fast-slow (linked list cycle)

```cpp
// Floyd's cycle detection
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;  // cycle
}
return false;
```

## Khi nào dùng Two Pointers

- Sorted array
- Palindrome / symmetric pattern
- Remove/partition in-place
- Tìm pair với điều kiện sum
- Linked list cycle detection

## Practice

### Easy

- [ ] Two Sum II - Input Array Is Sorted (LC #167)
- [ ] Valid Palindrome (LC #125)
- [ ] Remove Duplicates from Sorted Array (LC #26)
- [ ] Move Zeroes (LC #283)
- [ ] Squares of Sorted Array (LC #977)

### Medium

- [ ] 3Sum (LC #15)
- [ ] Container With Most Water (LC #11)
- [ ] Sort Colors (LC #75) - Dutch national flag
- [ ] Partition Array Such That Maximum Difference Is K (LC #2294)

### Hard

- [ ] Trapping Rain Water (LC #42)
- [ ] 4Sum (LC #18)

## Mistakes thường gặp

- Quên skip duplicates trong 3Sum
- `l <= r` vs `l < r` - tùy bài
- Sort trước khi áp dụng (nếu chưa sorted)

---

**Next**: [[Day-08-Sliding-Window]]

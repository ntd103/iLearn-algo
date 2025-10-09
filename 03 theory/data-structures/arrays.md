# Arrays - Lý Thuyết

## Định nghĩa

Array là cấu trúc dữ liệu lưu trữ các phần tử **cùng kiểu** trong **bộ nhớ liên tục**.

## Đặc điểm

- ✅ **Random Access**: Truy cập O(1) bằng index
- ✅ **Cache-friendly**: Dữ liệu liền kề nhau
- ❌ **Fixed size**: Kích thước cố định (static array)
- ❌ **Insert/Delete**: O(n) khi cần shift elements

## Operations

| Operation | Time Complexity |
|-----------|----------------|
| Access    | O(1)          |
| Search    | O(n)          |
| Insert (end) | O(1)       |
| Insert (middle) | O(n)    |
| Delete    | O(n)          |

## Implementation (C++)

```cpp
// Static array
int arr[100];

// Dynamic array (vector)
vector<int> v;
v.push_back(1);  // O(1) amortized
v[0];            // O(1) access
v.size();        // O(1)
```

## Common Patterns

### 1. Two Pointers
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process
    left++; right--;
}
```

### 2. Sliding Window
```cpp
for (int i = 0; i < n; i++) {
    // Add current element
    while (/* window invalid */) {
        // Remove from left
    }
    // Update result
}
```

### 3. Prefix Sum
```cpp
vector<int> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
// Sum [l, r] = prefix[r+1] - prefix[l]
```

## When to Use

- ✅ Need fast random access
- ✅ Know size in advance (or can use dynamic array)
- ✅ Iterate through all elements
- ❌ Frequent insertions/deletions in middle

## Common Problems

- Two Sum
- Best Time to Buy and Sell Stock
- Maximum Subarray (Kadane's Algorithm)
- Sliding Window Maximum
- Product of Array Except Self

## Tips

1. **Index out of bounds**: Always check `0 <= i < n`
2. **Empty array**: Handle edge case when `n == 0`
3. **Integer overflow**: Use `long long` for sums
4. **Sort first**: Many problems easier after sorting

---

**Next**: Practice in `roadmap/Day-01/`

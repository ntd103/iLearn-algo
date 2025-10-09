# Time Complexity - Big O Notation

## Định nghĩa

Time complexity đo lường **số operations** thuật toán thực hiện khi input size tăng.

## Ký hiệu Big O

O(f(n)) = "thuật toán chạy không quá f(n) operations"

## Common Complexities (Tốt → Xấu)

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Array access, hash lookup |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Iterate array once |
| O(n log n) | Linearithmic | Merge sort, heap sort |
| O(n²) | Quadratic | Nested loops |
| O(n³) | Cubic | Triple nested loops |
| O(2^n) | Exponential | Recursive fibonacci |
| O(n!) | Factorial | Permutations |

## Visualization

```
Operations
│
│                                        ╱ O(n!)
│                                    ╱
│                                ╱ O(2^n)
│                            ╱
│                        ╱ O(n²)
│                    ╱
│                ╱ O(n log n)
│            ╱ O(n)
│        ╱ O(log n)
│    ╱
│___╱__________________________________ n (input size)
   O(1)
```

## Rules

### 1. Drop Constants
```cpp
// O(2n) → O(n)
for (int i = 0; i < n; i++) { }
for (int i = 0; i < n; i++) { }
```

### 2. Drop Non-Dominant Terms
```cpp
// O(n² + n) → O(n²)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { }
}
for (int i = 0; i < n; i++) { }
```

### 3. Different Inputs = Different Variables
```cpp
// O(n + m), NOT O(n)
for (int i = 0; i < n; i++) { }
for (int j = 0; j < m; j++) { }
```

## Examples

### O(1) - Constant
```cpp
int x = arr[5];        // Direct access
hash.find(key);        // Hash lookup
return a + b;          // Arithmetic
```

### O(log n) - Logarithmic
```cpp
// Binary search
int left = 0, right = n - 1;
while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### O(n) - Linear
```cpp
// Single loop
for (int i = 0; i < n; i++) {
    // O(1) operations
}
```

### O(n log n)
```cpp
// Merge sort
sort(arr.begin(), arr.end());  // O(n log n)
```

### O(n²) - Quadratic
```cpp
// Nested loops
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operations
    }
}
```

## Best/Worst/Average Case

**Binary Search**:
- Best: O(1) - find immediately
- Worst: O(log n) - not found
- Average: O(log n)

**Quick Sort**:
- Best: O(n log n)
- Worst: O(n²) - bad pivot
- Average: O(n log n)

## Space Complexity

Tương tự time, nhưng đo **memory usage**.

```cpp
// O(1) space
int sum = 0;

// O(n) space
vector<int> temp(n);

// O(n²) space
vector<vector<int>> matrix(n, vector<int>(n));
```

## Practical Limits (1 second)

| Complexity | Max n |
|------------|-------|
| O(1) | ∞ |
| O(log n) | ∞ |
| O(n) | 10^8 |
| O(n log n) | 10^6 |
| O(n²) | 10^4 |
| O(n³) | 500 |
| O(2^n) | 20 |
| O(n!) | 11 |

## Tips

1. **Nested loops**: Multiply complexities
2. **Sequential operations**: Add complexities
3. **Recursive**: Solve recurrence relation
4. **Amortized**: Average over sequence of operations

---

**Apply**: Analyze every algorithm you write!

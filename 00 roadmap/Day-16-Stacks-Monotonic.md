---
day: 16
topic: Stacks & Monotonic Stack
tags:
  - roadmap
  - dsa/topics/stack
  - dsa/topics/monotonic-stack
created: 2026-05-20
---
# Day 16 - Stacks & Monotonic Stack

## Lý thuyết

### Stack basics

```cpp
stack<int> st;
st.push(x); st.top(); st.pop(); st.empty(); st.size();
```

LIFO - Last In First Out.

### Monotonic Stack

Stack mà các phần tử trong nó luôn theo thứ tự (tăng hoặc giảm).

#### Monotonic decreasing (next greater element)

```cpp
vector<int> nextGreater(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;  // indices, a[indices] giảm dần
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
```

#### Monotonic increasing (previous smaller element)

```cpp
vector<int> prevSmaller(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) ans[i] = a[st.top()];
        st.push(i);
    }
    return ans;
}
```

### Khi nào dùng Monotonic Stack

- Tìm next/previous greater/smaller
- Largest rectangle / area problems
- Stock span / temperature
- Trapping rain water

### Pattern: Sentinel

Thêm phần tử sentinel để xử lý cleanup tự động:

```cpp
// Largest rectangle in histogram
vector<int> heights = ...;
heights.push_back(0);  // sentinel - flush stack
stack<int> st;
int max_area = 0;
for (int i = 0; i < heights.size(); i++) {
    while (!st.empty() && heights[st.top()] > heights[i]) {
        int h = heights[st.top()]; st.pop();
        int w = st.empty() ? i : i - st.top() - 1;
        max_area = max(max_area, h * w);
    }
    st.push(i);
}
```

## Practice

### Easy

- [ ] Valid Parentheses (LC #20)
- [ ] Min Stack (LC #155)
- [ ] Implement Queue using Stacks (LC #232)
- [ ] Backspace String Compare (LC #844)

### Medium

- [ ] Daily Temperatures (LC #739) - monotonic
- [ ] Next Greater Element II (LC #503) - circular
- [ ] Online Stock Span (LC #901)
- [ ] Asteroid Collision (LC #735)
- [ ] Decode String (LC #394)
- [ ] Evaluate Reverse Polish Notation (LC #150)
- [ ] Remove K Digits (LC #402)
- [ ] 132 Pattern (LC #456)

### Hard

- [ ] Largest Rectangle in Histogram (LC #84)
- [ ] Trapping Rain Water (LC #42) - 2 monotonic stacks
- [ ] Maximal Rectangle (LC #85)
- [ ] Sum of Subarray Minimums (LC #907)

---

**Next**: [[Day-17-Queues-Deque]]

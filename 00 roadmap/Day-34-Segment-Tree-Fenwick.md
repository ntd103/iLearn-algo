---
day: 34
topic: Segment Tree & Fenwick Tree
tags:
  - roadmap
  - dsa/topics/segment-tree
  - dsa/topics/fenwick-tree
created: 2026-05-20
---
# Day 34 - Segment Tree & Fenwick Tree

## Lý thuyết

### Khi nào dùng

| Operation | Static array | Fenwick | Segment Tree |
|-----------|--------------|---------|--------------|
| Point update | - | O(log n) | O(log n) |
| Range query (sum) | O(1) prefix | O(log n) | O(log n) |
| Range update | - | Trick (diff) | O(log n) lazy |
| Range query (min/max) | Sparse table O(1) | No | O(log n) |
| Memory | O(n) | O(n) | O(4n) |
| Code complexity | Low | Low | Medium |

### Fenwick Tree (BIT)

Point update + prefix sum query.

```cpp
struct BIT {
    vector<ll> bit;
    int n;
    BIT(int n) : n(n), bit(n + 1, 0) {}
    
    void update(int i, ll val) {  // i là 1-indexed
        for (; i <= n; i += i & -i) bit[i] += val;
    }
    
    ll query(int i) {  // sum of [1..i]
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }
    
    ll range(int l, int r) {  // sum of [l..r]
        return query(r) - query(l - 1);
    }
};
```

### Range Update + Point Query với Fenwick

Dùng difference array.

```cpp
// update [l, r] += val
bit.update(l, val);
bit.update(r + 1, -val);

// query value at i
bit.query(i);
```

### Segment Tree - Sum

```cpp
struct SegTree {
    vector<ll> tree;
    int n;
    SegTree(int n) : n(n), tree(4 * n, 0) {}
    
    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }
    
    void update(int idx, ll val) { update(1, 0, n-1, idx, val); }
    ll query(int l, int r) { return query(1, 0, n-1, l, r); }
};
```

### Segment Tree với Lazy Propagation

Range update + range query.

```cpp
struct LazySeg {
    vector<ll> tree, lazy;
    int n;
    LazySeg(int n) : n(n), tree(4*n, 0), lazy(4*n, 0) {}
    
    void push(int node, int start, int end) {
        if (lazy[node]) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    void update(int node, int start, int end, int l, int r, ll val) {
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        push(node, start, end);
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }
};
```

### Iterative Segment Tree (faster)

```cpp
struct SegTreeIter {
    int n;
    vector<ll> tree;
    SegTreeIter(int n) : n(n), tree(2*n, 0) {}
    
    void update(int i, ll val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }
    
    ll query(int l, int r) {  // [l, r)
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};
```

### Sparse Table - O(1) min/max query

Static array, range min/max query trong O(1) sau O(n log n) preprocessing.

```cpp
const int LOG = 20;
int sparse[N][LOG];
int log_table[N];

void build(vector<int>& a) {
    int n = a.size();
    log_table[1] = 0;
    for (int i = 2; i <= n; i++) log_table[i] = log_table[i/2] + 1;
    for (int i = 0; i < n; i++) sparse[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {  // [l, r]
    int j = log_table[r - l + 1];
    return min(sparse[l][j], sparse[r - (1<<j) + 1][j]);
}
```

## Practice

### Medium

- [ ] Range Sum Query - Mutable (LC #307)
- [ ] Count of Smaller Numbers After Self (LC #315) - BIT
- [ ] Count of Range Sum (LC #327)
- [ ] Range Frequency Queries (LC #2080)

### Hard

- [ ] Reverse Pairs (LC #493) - BIT/MergeSort
- [ ] My Calendar III (LC #732)
- [ ] Falling Squares (LC #699)
- [ ] Range Module (LC #715)

---

**Next**: [[Day-35-Contest-Strategy]]

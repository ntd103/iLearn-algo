// ========================================
// Segment Tree (Range Queries & Updates)
// Time: O(log n) per query/update
// ========================================

template <typename T>
class SegmentTree {
private:
    vector<T> tree;
    vector<T> lazy;
    int n;
    T default_value;

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void build(const vector<T> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update_range(int node, int start, int end, int l, int r, T val) {
        push(node, start, end);
        if (start > r || end < l)
            return;

        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update_range(2 * node, start, mid, l, r, val);
        update_range(2 * node + 1, mid + 1, end, l, r, val);
        push(2 * node, start, mid);
        push(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    T query_range(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (start > r || end < l)
            return default_value;

        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        T left_sum = query_range(2 * node, start, mid, l, r);
        T right_sum = query_range(2 * node + 1, mid + 1, end, l, r);
        return left_sum + right_sum;
    }

public:
    SegmentTree(int size, T def_val = 0) : n(size), default_value(def_val) {
        tree.resize(4 * n, default_value);
        lazy.resize(4 * n, 0);
    }

    SegmentTree(const vector<T> &arr) : n(arr.size()), default_value(0) {
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void update(int l, int r, T val) {
        update_range(1, 0, n - 1, l, r, val);
    }

    T query(int l, int r) {
        return query_range(1, 0, n - 1, l, r);
    }
};

// Usage:
// SegmentTree<ll> seg(n);
// seg.update(l, r, val);  // Add val to range [l, r]
// ll sum = seg.query(l, r);  // Query sum in range [l, r]

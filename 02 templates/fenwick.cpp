// ========================================
// Fenwick Tree (Binary Indexed Tree)
// Time: O(log n) per query/update
// ========================================

template <typename T>
class Fenwick {
private:
    vector<T> tree;
    int n;

public:
    Fenwick(int size) : n(size) {
        tree.resize(n + 1, 0);
    }

    Fenwick(const vector<T> &arr) : n(arr.size()) {
        tree.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }

    // Add val to index i (0-indexed)
    void update(int i, T val) {
        i++; // Convert to 1-indexed
        while (i <= n) {
            tree[i] += val;
            i += i & (-i);
        }
    }

    // Query prefix sum [0, i] (0-indexed)
    T query(int i) {
        i++; // Convert to 1-indexed
        T sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    // Query range sum [l, r] (0-indexed)
    T query(int l, int r) {
        if (l > 0)
            return query(r) - query(l - 1);
        return query(r);
    }

    // Find index with prefix sum >= k (for ordered statistics)
    int lower_bound(T k) {
        int pos = 0;
        int pw = 1;
        while (pw * 2 <= n)
            pw *= 2;

        while (pw > 0) {
            if (pos + pw <= n && tree[pos + pw] < k) {
                k -= tree[pos + pw];
                pos += pw;
            }
            pw /= 2;
        }
        return pos;
    }
};

// Usage:
// Fenwick<ll> fen(n);
// fen.update(i, val);      // Add val to arr[i]
// ll sum = fen.query(l, r); // Get sum of arr[l..r]

// ========================================
// String Algorithms Library
// ========================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ============ KMP (KNUTH-MORRIS-PRATT) ============
// Time: O(n + m)
vector<int> compute_prefix(const string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];

        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

vector<int> kmp_search(const string &text, const string &pattern) {
    vector<int> pi = compute_prefix(pattern);
    vector<int> matches;

    int n = text.size();
    int m = pattern.size();
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (text[i] == pattern[j]) {
            j++;
        }

        if (j == m) {
            matches.push_back(i - m + 1); // Match found at position i - m + 1
            j = pi[j - 1];
        }
    }

    return matches;
}

// ============ Z-ALGORITHM ============
// Time: O(n)
vector<int> z_algorithm(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

// ============ ROLLING HASH ============
// Time: O(n) preprocessing, O(1) per query
class RollingHash {
private:
    static const ll MOD1 = 1e9 + 7;
    static const ll MOD2 = 1e9 + 9;
    static const ll BASE = 31;

    vector<ll> hash1, hash2;
    vector<ll> pow1, pow2;
    int n;

public:
    RollingHash(const string &s) {
        n = s.size();
        hash1.resize(n + 1, 0);
        hash2.resize(n + 1, 0);
        pow1.resize(n + 1, 1);
        pow2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] * BASE + s[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * BASE + s[i]) % MOD2;
            pow1[i + 1] = (pow1[i] * BASE) % MOD1;
            pow2[i + 1] = (pow2[i] * BASE) % MOD2;
        }
    }

    // Get hash of substring [l, r) (0-indexed, exclusive r)
    pair<ll, ll> get_hash(int l, int r) {
        ll h1 = (hash1[r] - hash1[l] * pow1[r - l] % MOD1 + MOD1) % MOD1;
        ll h2 = (hash2[r] - hash2[l] * pow2[r - l] % MOD2 + MOD2) % MOD2;
        return {h1, h2};
    }
};

// ============ SUFFIX ARRAY (O(n log n)) ============
vector<int> suffix_array(string s) {
    s += "$"; // Sentinel character
    int n = s.size();

    vector<int> sa(n), rank(n), tmp(n);

    // Initial ranking
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            int ri = (i + k < n) ? rank[i + k] : -1;
            int rj = (j + k < n) ? rank[j + k] : -1;
            return ri < rj;
        };

        sort(sa.begin(), sa.end(), cmp);

        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }

        rank = tmp;
    }

    sa.erase(sa.begin()); // Remove sentinel
    return sa;
}

// ============ LCP ARRAY (Longest Common Prefix) ============
// Time: O(n)
vector<int> lcp_array(const string &s, const vector<int> &sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n - 1);

    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
                h++;
            }
            lcp[rank[i] - 1] = h;
            if (h > 0)
                h--;
        }
    }

    return lcp;
}

// ============ TRIE ============
class Trie {
private:
    struct Node {
        map<char, Node *> children;
        bool is_end = false;
    };

    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string &word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->is_end = true;
    }

    bool search(const string &word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->is_end;
    }

    bool starts_with(const string &prefix) {
        Node *curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};

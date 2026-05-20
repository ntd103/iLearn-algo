---
day: 20
topic: BST & Tree DP
tags:
  - roadmap
  - dsa/topics/bst
  - dsa/topics/dp/tree
created: 2026-05-20
---
# Day 20 - BST & Tree DP

## Lý thuyết

### Binary Search Tree (BST)

Property: với mọi node, `left < node < right`.

Inorder traversal của BST -> sorted array.

### BST Operations

```cpp
TreeNode* search(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (val < root->val) root->left = deleteNode(root->left, val);
    else if (val > root->val) root->right = deleteNode(root->right, val);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}
```

### Validate BST

```cpp
bool valid(TreeNode* root, long lo, long hi) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return valid(root->left, lo, root->val) && 
           valid(root->right, root->val, hi);
}

bool isValidBST(TreeNode* root) {
    return valid(root, LONG_MIN, LONG_MAX);
}
```

### Tree DP

DP trên cây, thường tính theo postorder.

#### Pattern: Return value cho parent

```cpp
struct Result {
    int withRoot;     // include root
    int withoutRoot;  // exclude root
};

Result dfs(TreeNode* root) {
    if (!root) return {0, 0};
    Result l = dfs(root->left);
    Result r = dfs(root->right);
    return {
        root->val + l.withoutRoot + r.withoutRoot,
        max(l.withRoot, l.withoutRoot) + max(r.withRoot, r.withoutRoot)
    };
}
```

#### House Robber III (LC #337)

```cpp
pii rob(TreeNode* root) {
    if (!root) return {0, 0};
    auto [l_rob, l_not] = rob(root->left);
    auto [r_rob, r_not] = rob(root->right);
    return {
        root->val + l_not + r_not,        // rob this node
        max(l_rob, l_not) + max(r_rob, r_not)  // skip this node
    };
}
```

#### Diameter / Longest Path

```cpp
int ans = 0;
int depth(TreeNode* root) {
    if (!root) return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    ans = max(ans, l + r);  // path qua root
    return 1 + max(l, r);
}
```

### Tree on Graph (rooted tree)

```cpp
vector<vector<int>> adj;
vector<int> dp;

void dfs(int u, int parent) {
    dp[u] = 1;  // base
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u] += dp[v];  // example: subtree size
    }
}
```

## Practice

### Easy

- [ ] Validate BST (LC #98)
- [ ] Lowest Common Ancestor of BST (LC #235)
- [ ] Convert Sorted Array to BST (LC #108)
- [ ] Range Sum of BST (LC #938)

### Medium

- [ ] Kth Smallest Element in BST (LC #230)
- [ ] Insert into BST (LC #701)
- [ ] Delete Node in BST (LC #450)
- [ ] House Robber III (LC #337) - tree DP
- [ ] Path Sum III (LC #437)
- [ ] Binary Tree Cameras (LC #968) - tree DP

### Hard

- [ ] Recover BST (LC #99)
- [ ] Serialize and Deserialize Binary Tree (LC #297)
- [ ] Binary Tree Maximum Path Sum (LC #124)

---

**Next**: [[Day-21-Graphs-Basics]]

---
day: 15
topic: Linked Lists
tags:
  - roadmap
  - dsa/topics/linked-list
created: 2026-05-20
---
# Day 15 - Linked Lists

## Lý thuyết

### Definition

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

### Operations

| Operation | Singly | Doubly |
|-----------|--------|--------|
| Access by index | O(n) | O(n) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(n) hoặc O(1) với tail ptr | O(1) |
| Delete | O(n) - find prev | O(1) nếu có ptr |

### Dummy Head Technique

Tránh edge case khi modify head:

```cpp
ListNode dummy(0);
dummy.next = head;
ListNode* prev = &dummy;
// ... modifications ...
return dummy.next;
```

### Reverse linked list

```cpp
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

Recursive version:

```cpp
ListNode* reverse(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}
```

### Floyd's Cycle Detection

```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

Find cycle start:

```cpp
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
```

### Find middle

```cpp
ListNode* middle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // Nếu chẵn nodes, trả về node thứ n/2 + 1
}
```

### Merge 2 sorted lists

```cpp
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

## Practice

### Easy

- [ ] Reverse Linked List (LC #206)
- [ ] Merge Two Sorted Lists (LC #21)
- [ ] Linked List Cycle (LC #141)
- [ ] Middle of Linked List (LC #876)
- [ ] Remove Duplicates from Sorted List (LC #83)
- [ ] Palindrome Linked List (LC #234)

### Medium

- [ ] Add Two Numbers (LC #2)
- [ ] Remove Nth Node From End (LC #19)
- [ ] Reorder List (LC #143)
- [ ] Linked List Cycle II (LC #142)
- [ ] Copy List with Random Pointer (LC #138)
- [ ] Reverse Linked List II (LC #92)
- [ ] LRU Cache (LC #146) - DLL + hashmap

### Hard

- [ ] Merge K Sorted Lists (LC #23)
- [ ] Reverse Nodes in K-Group (LC #25)

## Mistakes thường gặp

- Lost reference: gán `next` trước khi save
- Quên dummy head -> nhiều edge case
- Memory leak: quên delete (CP thường không quan trọng)
- Cycle khi reverse: tạo cycle nếu không cẩn thận

---

**Next**: [[Day-16-Stacks-Monotonic]]

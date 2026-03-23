# AVL Tree – Introduction

An AVL Tree is a **self-balancing Binary Search Tree (BST)**.

For every node in an AVL Tree, the height difference between the
left and right subtrees is **-1 or 0 or 1**.

---

## Balance Factor

Balance Factor is calculated as:

Balance Factor = Height(left subtree) - Height(right subtree)

Allowed values:
- -1
- 0
- +1

If the balance factor becomes less than -1 or greater than +1,
the tree becomes **unbalanced**.

---

## Why AVL Tree?

- Guarantees O(log n) time complexity
- Faster search than normal BST
- Automatically balances itself

---

## AVL Tree Properties

- Follows all BST rules
- Self-balancing tree
- Uses rotations to maintain balance

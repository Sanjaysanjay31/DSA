# AVL Tree Rotations

Rotations are used in AVL Trees to **restore balance** when the balance
factor becomes greater than `+1` or less than `-1`.

## **Contents :**
  - [RightRotation Function](#rightrotation-function)
  - [LeftRotation Function](#leftrotation-function)
  - [Left Left Rotation](#left-left-ll-rotation)
  - [Right Right Rotation](#right-right-rr-rotation)
  - [Left Right Rotation](#left-right-lr-rotation)
  - [Right Left Rotation](#right-left-rl-rotation)

---




## RightRotation Function

Right Rotation is applied in an AVL Tree when a node becomes **left heavy**,
that is, when its balance factor becomes **greater than +1**.

In this rotation:
- The left child of the unbalanced node becomes the new root
- The unbalanced node moves to the right
- The right subtree of the left child is reassigned

After rotation, the heights of the affected nodes are updated to
restore the AVL balance condition.

### **Code**
```cpp
// Right rotation (used to balance AVL tree)
tree* RightRotation(tree* p){
    tree* c = p->left;     // Left child becomes new root
    tree* cr = c->right;   // Right child of left subtree

    // Perform rotation
    c->right = p;
    p->left = cr;

    // Update heights
    p->height = 1 + max(Height(p->left), Height(p->right));
    c->height = 1 + max(Height(c->left), Height(c->right));

    return c;              // Return new root
}
```

---
## LeftRotation Function

Left Rotation is applied in an AVL Tree when a node becomes **right heavy**,
that is, when its balance factor becomes **less than -1**.

In this rotation:
- The right child of the unbalanced node becomes the new root
- The unbalanced node moves to the left
- The left subtree of the right child is reassigned

After rotation, the heights of the affected nodes are updated to
restore the AVL balance condition.

### **Code**
```Cpp
// Left rotation (used to balance AVL tree)
tree* LeftRotation(tree* p){
    tree* c = p->right;    // Right child becomes new root
    tree* cl = c->left;    // Left child of right subtree

    // Perform rotation
    c->left = p;
    p->right = cl;

    // Update heights
    p->height = 1 + max(Height(p->left), Height(p->right));
    c->height = 1 + max(Height(c->left), Height(c->right));

    return c;              // Return new root
}
```
---

## **Types of Rotations in AVL Tree**

AVL Tree uses different rotations to restore balance when the balance
factor of a node becomes invalid.



## Left Left (LL) Rotation

LL Rotation occurs when:
- The tree becomes **left heavy**
- Insertion or deletion happens in the **left subtree of the left child**

**Rotation Used:**
- Right Rotation

**Purpose:**
- Reduce left subtree height
- Restore AVL balance

---

## Right Right (RR) Rotation

RR Rotation occurs when:
- The tree becomes **right heavy**
- Insertion or deletion happens in the **right subtree of the right child**

**Rotation Used:**
- Left Rotation

**Purpose:**
- Reduce right subtree height
- Restore AVL balance

---

## Left Right (LR) Rotation

LR Rotation occurs when:
- The tree becomes **left heavy**
- Insertion or deletion happens in the **right subtree of the left child**

**Rotation Used:**
1. Left Rotation on left child
2. Right Rotation on unbalanced node

**Purpose:**
- Convert LR case into LL case
- Restore balance

---

## Right Left (RL) Rotation

RL Rotation occurs when:
- The tree becomes **right heavy**
- Insertion or deletion happens in the **left subtree of the right child**

**Rotation Used:**
1. Right Rotation on right child
2. Left Rotation on unbalanced node

**Purpose:**
- Convert RL case into RR case
- Restore balance


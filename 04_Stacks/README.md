# 04. Stacks Implementation & Challenges

This repository contains robust implementations of the **Stack** data structure in C++ and solutions to specialized stack problems.

## Table of Contents
1. [Overview of Stack](#overview-of-stack)
2. [Implementations](#implementations)
   - [Array-Based Stack](#1-array-based-stack)
   - [Linked List-Based Stack](#2-linked-list-based-stack)
   - [Min Stack (O(1) GetMin)](#3-min-stack-o1-getmin)
3. [Operations & Complexities](#operations--complexities)
4. [How to Run](#how-to-run)

---

## Overview of Stack
A **Stack** is a linear data structure that follows the **LIFO (Last-In, First-Out)** principle. The element inserted last is the first one to be removed. It behaves similarly to a pile of plates where you can only add or remove from the top.

---

## Implementations

### 1. Array-Based Stack
- **File:** `Stack_Implement_Using_Array.cpp` 
- **Concept:** Uses a fixed-size array (`MAX_SIZE = 100`) to store elements and an integer pointer `topIdx` to track the top of the stack.
- **Key Methods:**
  - `push(x)`: Inserts element `x` at the top (with stack overflow check).
  - `pop()`: Removes the top element (with stack underflow check).
  - `peek()`: Returns the top element without removing it.
  - `size()`: Returns current count of elements.
  - `isEmpty()` / `isFull()`: Checks stack status.

### 2. Linked List-Based Stack
- **File:** `Stack_Implement_Using_LinkedList.cpp`
- **Concept:** Dynamic implementation where each node contains a value and a pointer to the next element. This avoids any fixed capacity limit.
- **Key Methods:**
  - `push(v)`: Adds a new node at the head (top) of the list.
  - `pop()`: Removes the head node and frees memory.
  - `top()`: Returns the head node's value.
  - `size()`: Traverses the list to count nodes.
  - `isempty()`: Checks if the head pointer is `nullptr`.

### 3. Min Stack (O(1) GetMin)
- **File:** `LeetCode_155_MinStack.cpp`
- **Concept:** A specialized stack that supports standard stack operations while retrieving the minimum element in **O(1) time complexity**.
- **Implementation Detail:** Each node in the linked list tracks both its standard `val` and the `mini` (the minimum value present in the stack from this node down to the bottom).
  - When pushing `value`, the node's `mini` is set to `min(topNode->mini, value)`.
  - When retrieving the minimum, we simply return `topNode->mini`.

---

## Operations & Complexities

| Operation | Array-Based Stack | Linked List-Based Stack | Min Stack (Linked List) |
| :--- | :--- | :--- | :--- |
| **Push** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Pop** | $O(1)$ | $O(1)$ | $O(1)$ |
| **Top / Peek** | $O(1)$ | $O(1)$ | $O(1)$ |
| **GetMin** | N/A | N/A | $O(1)$ |
| **Size** | $O(1)$ | $O(N)$ | N/A |
| **Space Complexity** | $O(\text{MAX\_SIZE})$ | $O(N)$ (Dynamic) | $O(N)$ (Dynamic) |

---



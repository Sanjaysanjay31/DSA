# ***AVL Tree Insertion***

Insertion in an AVL Tree follows the **Binary Search Tree (BST)** rules,
and after insertion, the tree is balanced using **rotations**.

---

## **Steps Followed in Insertion**

1. Insert the value like a normal BST  
   - Smaller values go to the left subtree  
   - Larger values go to the right subtree  
   - Duplicate values are not allowed  

2. Update the height of the current node  
   - Height is calculated as:
     ```
     1 + max(height of left subtree, height of right subtree)
     ```

3. Calculate the Balance Factor 
4. Check for imbalance and apply rotations  

---

## **Rotation Cases During Insertion**

### **Left Left (LL) Case :**
- Tree becomes left heavy  
- Insertion occurs in the left subtree of the left child  

**Rotation Used:** Right Rotation  


### **Right Right (RR) Case :**
- Tree becomes right heavy  
- Insertion occurs in the right subtree of the right child  

**Rotation Used:** Left Rotation  


### **Left Right (LR) Case :**
- Tree becomes left heavy  
- Insertion occurs in the right subtree of the left child  

**Rotation Used:**  
1. Left Rotation on left child  
2. Right Rotation on current node  


### **Right Left (RL) Case :**
- Tree becomes right heavy  
- Insertion occurs in the left subtree of the right child  

**Rotation Used:**  
1. Right Rotation on right child  
2. Left Rotation on current node  

---

<details>
<summary><b><mark>AVL Tree Insertion Function </summary>

```cpp

// Function to insert a value into AVL Tree
tree* Insert(tree* root, int v){
    // Normal BST insertion
    if(!root) return new tree(v);

    if(v < root->val)
        root->left = Insert(root->left, v);
    else if(v > root->val)
        root->right = Insert(root->right, v);
    else
        return root;       // Duplicate values not allowed

    // Update height of current node
    root->height = 1 + max(Height(root->left), Height(root->right));

    // Calculate balance factor
    int bf = Height(root->left) - Height(root->right);

    // Left Left Case
    if(bf > 1 && root->left->val > v){
        return RightRotation(root);
    }

    // Right Right Case
    if(bf < -1 && root->right->val < v){
         return LeftRotation(root);
    }

    // Left Right Case
    if(bf > 1 && root->left->val < v){
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

    // Right Left Case
    if(bf < -1 && root->right->val > v){
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }

    return root;   // Return balanced node
}
```
</details>
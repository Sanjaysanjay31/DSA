# **AVL Tree Deletion Function**

The `Delete_Node()` function is used to remove a node from an AVL Tree
while maintaining the **AVL balance property**.


### **Purpose of Deletion Function :**

- Delete a node using **BST deletion rules**
- Update the height of affected nodes
- Restore balance using rotations if needed



### **Steps Followed in Deletion :**

1. Search for the node using BST rules  
2. Delete the node based on the number of children  
3. Update the height of the current node  
4. Calculate the balance factor  
5. Apply suitable rotations to rebalance the tree  


### **Deletion Cases:**

### **Case 1: Node with No Child or One Child**
- Delete the node directly
- Replace it with its child if present

---

### **Case 2: Node with Two Children**
- Find the inorder successor (minimum value in right subtree)
- Copy successor value to the current node
- Delete the successor node


### **Rebalancing After Deletion :**

- After deletion, balance factor is calculated.  
- If the balance factor becomes invalid, rotations are applied.



### **Rotation Cases After Deletion :**

- **LL Case** → Right Rotation  
- **RR Case** → Left Rotation  
- **LR Case** → Left Rotation + Right Rotation  
- **RL Case** → Right Rotation + Left Rotation  

---

<details>
<summary><b><mark>AVL Tree Deletion Function </summary>

```cpp

// Function to find inorder successor (smallest value in right subtree)
tree* Inorder_Successor(tree* root){
    tree* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

// Function to delete a node from AVL Tree
tree* Delete_Node(tree* root, int key){
    // If tree is empty
    if(root == NULL) return root;

    // Go to left subtree
    if(key < root->val)
        root->left = Delete_Node(root->left, key);

    // Go to right subtree
    else if(key > root->val)
        root->right = Delete_Node(root->right, key);

    // Node found
    else{
        // Case 1: Node has one child or no child
        if(!root->left || !root->right){
            tree* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else{
            // Case 2: Node has two children
            // Find inorder successor
            tree* mi = Inorder_Successor(root->right);

            // Copy successor value to current node
            root->val = mi->val;

            // Delete the inorder successor
            root->right = Delete_Node(root->right, mi->val);
        }
    }

    // If tree had only one node
    if(!root) return root;

    // Update height
    root->height = 1 + max(Height(root->left), Height(root->right));

    // Check balance factor
    int bf = Height(root->left) - Height(root->right);

    // Left Left Case
    if(bf > 1 && Height(root->left->left) >= Height(root->left->right))
        return RightRotation(root);

    // Left Right Case
    if(bf > 1 && Height(root->left->left) < Height(root->left->right)){
        root->left = LeftRotation(root->left);
        return RightRotation(root);
    }

    // Right Right Case
    if(bf < -1 && Height(root->right->left) <= Height(root->right->right))
        return LeftRotation(root);

    // Right Left Case
    if(bf < -1 && Height(root->right->left) > Height(root->right->right)){
        root->right = RightRotation(root->right);
        return LeftRotation(root);
    }

    return root;
}

```
</details>


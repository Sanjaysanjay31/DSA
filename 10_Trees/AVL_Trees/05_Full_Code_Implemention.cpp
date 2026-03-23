#include<bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// Node structure for AVL Tree
class tree{
    public:
        int val;        // Value of the node
        tree* left;     // Pointer to left child
        tree* right;    // Pointer to right child
        int height;     // Height of the node

        // Constructor to initialize node
        tree(int val){
            this->val = val;
            height = 1;     // New node is initially a leaf
            left = NULL;
            right = NULL;
        }
};

// Function to get height of a node
int Height(tree* root){
    if(!root) return 0;     // Height of empty tree is 0
    return root->height;
}

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

// Preorder traversal (Root → Left → Right)
void Preorder(tree* root){
    if(!root) return;
    cout << root->val << " ";
    Preorder(root->left);
    Preorder(root->right);
}

// Inorder traversal (Left → Root → Right)
void inorder(tree* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    tree* root = NULL;
    int n, v;

    cout << "\nEnter the number of elements : ";
    cin >> n;

    cout << "\nEnter the Elements : ";
    for(int i = 0; i < n; i++){
        cin >> v;
        root = Insert(root, v);
    }

    cout << "\nThe inorder Traversal is : ";
    inorder(root);

    cout << "\nThe Preorder Traversal is : ";
    Preorder(root);

    int d;
    cout << "\nEnter the key value to delete : ";
    cin >> d;

    // Delete first key
    root = Delete_Node(root, d);
    cout << "\nAfter deleting the key, Preorder Traversal is : ";
    Preorder(root);

    int d1;
    cout << "\nEnter the key value to delete : ";
    cin >> d1;

    // Delete second key
    root = Delete_Node(root, d1);
    cout << "\nAfter deleting the key, Preorder Traversal is : ";
    Preorder(root);
}

#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Linked List Node for Algorithms
// ======================================================
struct node {
    int val;
    node *next, *prev;
    node(int v) : val(v), next(nullptr), prev(nullptr) {}
};

// ======================================================
// Helper: Merge Two Sorted Lists
// ======================================================
node* merge(node* l1, node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// ======================================================
// Merge Sort (Advanced - O(N log N))
// ======================================================
node* merge_sort(node* head) {
    if (!head || !head->next) return head;
    
    // Split into halves
    node *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* mid = slow->next;
    slow->next = nullptr;
    
    return merge(merge_sort(head), merge_sort(mid));
}

// ======================================================
// Is Palindrome? (Advanced - O(N) Time, O(1) Space)
// ======================================================
bool is_palindrome(node* head) {
    if (!head || !head->next) return true;
    
    // 1. Find middle
    node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 2. Reverse second half
    node *prev = nullptr, *curr = slow;
    while (curr) {
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // 3. Compare halves
    node* left = head;
    node* right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

// ======================================================
// Reorder List (Odd/Even positions)
// ======================================================
void reorder_list(node* &head) {
    if (!head || !head->next) return;
    
    node* odd = head;
    node* even = head->next;
    node* evenHead = even;
    
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
}

// ======================================================
// Fundamental Algorithms
// ======================================================
bool detect_cycle(node* head) {
    node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void remove_cycle(node* head) {
    if (!head) return;
    node *slow = head, *fast = head;
    bool loop = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { loop = true; break; }
    }
    if (loop) {
        slow = head;
        while (slow->next != fast->next) { slow = slow->next; fast = fast->next; }
        fast->next = nullptr;
    }
}

node* reverse_list(node* head) {
    node *prev = nullptr, *curr = head, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// ======================================================
// Main Menu
// ======================================================
int main() {
    node* head = nullptr; // Note: In practice, construct lists here
    int choice;
    while (true) {
        cout << "\n\n========== ADVANCED ALGORITHMS ==========\n";
        cout << "1. Merge Sort\n2. Is Palindrome?\n3. Reorder Odd/Even\n";
        cout << "4. Detect Cycle\n5. Remove Cycle\n6. Reverse\n7. Exit\n";
        cout << "\nEnter Choice: "; cin >> choice;
        switch (choice) {
            case 1: head = merge_sort(head); cout << "Sorted.\n"; break;
            case 2: cout << (is_palindrome(head) ? "Yes\n" : "No\n"); break;
            case 3: reorder_list(head); cout << "Reordered.\n"; break;
            case 4: cout << (detect_cycle(head) ? "Yes\n" : "No\n"); break;
            case 5: remove_cycle(head); cout << "Done.\n"; break;
            case 6: head = reverse_list(head); cout << "Reversed.\n"; break;
            case 7: return 0;
            default: cout << "Invalid.\n";
        }
    }
}

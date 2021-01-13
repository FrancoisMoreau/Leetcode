//
// Created by brayden on 2020-10-27.
//

#include "problem109.h"
#include <vector>


// My solution, O(NlogN), O(logN)
TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode *p1 = head, *p2 = head->next;
    while (p1->next && p2->next && p2->next->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1->next;
    p1->next = nullptr;
    TreeNode *node = new TreeNode(p2->val);
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(p2->next);
    return node;
}

// don't change the raw list
TreeNode *subsorted(ListNode *head, ListNode *tail) {
    if (head == tail) return nullptr;
    if (head->next == tail) {
        TreeNode *root = new TreeNode(head->val);
        return root;
    }
    ListNode *p1 = head, *p2 = head;
    while (p2 != tail && p2->next != tail) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    TreeNode *root = new TreeNode(p1->val);
    root->left = subsorted(head, p1);
    root->right = subsorted(p1->next, tail);
    return root;
}

TreeNode *sortedListToBST2(ListNode *head) {
    return subsorted(head, nullptr);
}

// use an array, O(n), O(n)
TreeNode *subconvert(const std::vector<int> &list, int lo, int hi) {
    if (lo > hi) return nullptr;
    int mid = lo + (hi - lo) / 2;
    TreeNode *root = new TreeNode(list[mid]);
//    if (lo == hi) return root;
    root->left = subconvert(list, lo, mid - 1);
    root->right = subconvert(list, mid + 1, hi);
    return root;
}

TreeNode *sortedListToBST3(ListNode *head) {
    std::vector<int> list;
    while (head) {
        list.push_back(head->val);
        head = head->next;
    }
    int lo = 0, hi = list.size() - 1;
    return subconvert(list, lo, hi);
}


// inorder simulation, O(N), O(logN);

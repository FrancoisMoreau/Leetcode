#include <iostream>
#include "problem1249.h"
#include "problem1269.h"
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;

// Arista network

struct ListNode {
    ListNode(int a) : a(a) {}
    int a;
    ListNode *next;
};

// BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

TreeNode *findMin(TreeNode *node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

TreeNode *findNext(TreeNode *node) {
    if (node->right) return findMin(node->right);
    TreeNode *p = node->parent;
    while (p && p->right == node) {
        node = p;
        p = p->parent;
    }
    return p;
}

void printbst(TreeNode *root) {
    TreeNode *min = findMin(root);
    printf("%d\n", min->val);
    TreeNode *next = findNext(min);
    while (next) {
        printf("%d\n", next->val);
        next = findNext(next);
    }
}

// vercmp
int vercmp2(char *v1, char *v2) {
    if (strcmp(v1, v2) == 0) return 0;
    char c1[strlen(v1)], c2[strlen(v2)];
    strcpy(c1, v1);
    strcpy(c2, v2);
    printf("%s and %s\n", c1, c2);
    char *tok1 = strtok(c1, ".");
    char *tok2 = strtok(c2, ".");
    while (tok1 != NULL && tok2 != NULL) {
        printf("%s  ,  %s\n", tok1, tok2);
        if (strcmp(tok1, tok2) > 0) return 1;
        else if (strcmp(tok1, tok2) < 0) return -1;
        tok1 = strtok(NULL, ".");
        tok2 = strtok(NULL, ".");
    }
    printf("%s  ,  %s\n", tok1, tok2);
    return tok1 ? 1 : -1;
}

int vercmp(char *v1, char *v2) {
    std::string s1(v1), s2(v2);
    if (s1 == s2) return 0;
    std::stringstream ss1(s1), ss2(s2);
    string tmp1, tmp2;
    while (getline(ss1, tmp1, '.') && getline(ss2, tmp2, '.')) {
        if (tmp1 < tmp2) return -1;
        else if (tmp1 > tmp2) return 1;
    }
    return ss1 ? 1 : -1;
}

// find the missing number
int search(int arr[], int size) {
    int offset = arr[0];
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] != mid + offset && arr[mid - 1] == mid - 1 + offset)
            return arr[mid - 1] + 1;
        if (arr[mid] != mid + offset)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

// LinkedList problem

struct sm{
    double f;
    int i;
    char c[3];
    void *p;
    int x[0];
};

int main() {
    cout << "problem1249: \n";
    string input1249 = "))((";
    cout << minRemoveToMakeValid(input1249) << endl;

    cout << "problem1269: \n";
    cout << numWays(3, 2) << endl;

    printf("Arista Network interview\n");


    assert(vercmp("1.1", "1.0") == 1);
    assert(vercmp("1.0", "1.1") == -1);
    assert(vercmp("1.0", "1.0") == 0);
    assert(vercmp("1", "1.0") == -1);
    assert(vercmp("1.0", "1") == 1);


    printf("Arista search\n");
    int search_in1[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    cout << search(search_in1, 9) << endl;

    printf("size: %d\n", sizeof(sm));
    void *p;
    printf("size: %d\n", sizeof(p));


//    ListNode list0(0);
//    ListNode *cur = &list0;
//    for (int i = 0; i < 100; ++i) {
//        cur->next = new ListNode(i + 1);
//        cur = cur->next;
//    }
//
//    int fib_prev = 1, fib_cur = 1;
//    cur = &list0;
//    int count = 0;
//    while (cur) {
//        if (count == fib_cur) {
//            printf("%d\n", cur->a);
//            std::swap(fib_cur, fib_prev);
//            fib_cur += fib_prev;
//        }
//        count++;
//        cur = cur->next;
//    }

    return 0;
}
#include <iostream>
using namespace std;

// Зв’язаний список
struct N {
    int d;
    N *nxt;
    N(int v) : d(v), nxt(nullptr) {}
};

N *rev(N *h) {
    N *prev = nullptr, *cur = h, *nxt = nullptr;
    while (cur) {
        nxt = cur->nxt;
        cur->nxt = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

bool cmp(N *h1, N *h2) {
    while (h1 && h2) {
        if (h1->d != h2->d) return false;
        h1 = h1->nxt;
        h2 = h2->nxt;
    }
    return h1 == nullptr && h2 == nullptr;
}

N *add(N *n1, N *n2) {
    N tmp(0), *cur = &tmp;
    int c = 0;
    while (n1 || n2 || c) {
        int s = c + (n1 ? n1->d : 0) + (n2 ? n2->d : 0);
        c = s / 10;
        cur->nxt = new N(s % 10);
        cur = cur->nxt;
        if (n1) n1 = n1->nxt;
        if (n2) n2 = n2->nxt;
    }
    return tmp.nxt;
}

void printL(N *h) {
    while (h) {
        cout << h->d << " ";
        h = h->nxt;
    }
    cout << endl;
}

// Бінарне дерево
struct T {
    int v;
    T *l, *r;
    T(int val) : v(val), l(nullptr), r(nullptr) {}
};

T *mirror(T *root) {
    if (!root) return nullptr;
    T *n = new T(root->v);
    n->l = mirror(root->r);
    n->r = mirror(root->l);
    return n;
}

int treeSum(T *root) {
    if (!root) return 0;
    if (!root->l && !root->r) return root->v;
    int lSum = treeSum(root->l), rSum = treeSum(root->r);
    root->v = lSum + rSum;
    return root->v;
}

void printT(T *root) {
    if (root) {
        printT(root->l);
        cout << root->v << " ";
        printT(root->r);
    }
}

int main() {
    // Тестування зв’язаного списку
    N *lst = new N(7);
    lst->nxt = new N(9);
    lst->nxt->nxt = new N(11);
    lst->nxt->nxt->nxt = new N(12);

    cout << "Original List: ";
    printL(lst);

    lst = rev(lst);
    cout << "Reversed List: ";
    printL(lst);

    N *l1 = new N(2);
    l1->nxt = new N(6);
    l1->nxt->nxt = new N(7);

    N *l2 = new N(3);
    l2->nxt = new N(5);
    l2->nxt->nxt = new N(8);

    cout << "Lists equal? " << (cmp(l1, l2) ? "Yes" : "No") << endl;

    l2->nxt->nxt->d = 7;
    cout << "Lists equal after change? " << (cmp(l1, l2) ? "Yes" : "No") << endl;

    N *num1 = new N(5);
    num1->nxt = new N(6);
    num1->nxt->nxt = new N(7);

    N *num2 = new N(1);
    num2->nxt = new N(2);
    num2->nxt->nxt = new N(1);

    N *sum = add(num1, num2);
    cout << "Sum: ";
    printL(sum);

    // Тестування дерева 
    T *root = new T(1);
    root->l = new T(3);
    root->r = new T(4);
    root->l->l = new T(2);
    root->l->r = new T(5);

    cout << "Original Tree: ";
    printT(root);
    cout << endl;

    T *mRoot = mirror(root);
    cout << "Mirrored Tree: ";
    printT(mRoot);
    cout << endl;

    T *sTree = new T(1);
    sTree->l = new T(2);
    sTree->r = new T(3);
    sTree->l->l = new T(4);
    sTree->l->r = new T(5);

    cout << "Tree before sum: ";
    printT(sTree);
    cout << endl;

    treeSum(sTree);
    cout << "Tree after sum: ";
    printT(sTree);
    cout << endl;

    return 0;
}

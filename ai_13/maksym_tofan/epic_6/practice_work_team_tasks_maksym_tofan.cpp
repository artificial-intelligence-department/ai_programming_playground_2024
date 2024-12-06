#include <iostream>
using namespace std;

template <typename T>
// Двонаправлений список
struct DCLNode {
    T data;
    DCLNode* next;
    DCLNode* prev;
    DCLNode(T value) : data(value), next(nullptr), prev(nullptr) {}

    DCLNode<T>& operator<<(T value) {
        DCLNode<T>* temp = new DCLNode<T>(value);
        next = temp;
        temp->prev = this;
        return *next;
    }
};

// Бінарне дерево пошуку
template <typename T>
struct BSTNode {
    T data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}

    void insert(T value) {
        if (value < data) {
            if (!left) left = new BSTNode<T>(value);
            else left->insert(value);
        } else if (value > data) {
            if (!right) right = new BSTNode<T>(value);
            else right->insert(value);
        }
    }

    void print() {
        if (left) left->print();
        cout << data << " ";
        if (right) right->print();
    }
};

// Завдання 1: Реверсування списку
template <typename T>
DCLNode<T>* reverse(DCLNode<T>* head) {
    DCLNode<T>* prev = nullptr;
    DCLNode<T>* curr = head;
    while (curr) {
        DCLNode<T>* next = curr->next;
        curr->next = prev;
        if (prev) prev->prev = curr;
        prev = curr;
        curr = next;
    }
    return prev;
}

template <typename T>
void output(DCLNode<T>* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Завдання 2: Порівняння двох списків
template <typename T>
bool compare(DCLNode<T>* list1, DCLNode<T>* list2) {
    while (list1 && list2) {
        if (list1->data != list2->data) return false;
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1 == nullptr && list2 == nullptr;
}

// Завдання 3: Додавання двох чисел, представлених списками
template <typename T>
DCLNode<T>* add(DCLNode<T>* node1, DCLNode<T>* node2) {
    int num1 = 0, num2 = 0, multiplier = 1;

    while (node1 || node2) {
        if (node1) {
            num1 += node1->data * multiplier;
            node1 = node1->next;
        }
        if (node2) {
            num2 += node2->data * multiplier;
            node2 = node2->next;
        }
        multiplier *= 10;
    }

    int sum = num1 + num2;
    DCLNode<T>* result = new DCLNode<T>(sum % 10);
    DCLNode<T>* current = result;
    sum /= 10;

    while (sum) {
        current->next = new DCLNode<T>(sum % 10);
        current = current->next;
        sum /= 10;
    }

    return result;
}

// Завдання 4: Створення дзеркального відображення дерева
template <typename T>
BSTNode<T>* mirror(BSTNode<T>* root) {
    if (!root) return nullptr;
    BSTNode<T>* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    return root;
}

// Завдання 5: Обчислення суми елементів дерева
int tree_sum(BSTNode<int>* root) {
    if (!root) return 0;
    return root->data + tree_sum(root->left) + tree_sum(root->right);
}

int main() {
    // Завдання 1
    DCLNode<int> list1(3);
    list1 << 2 << 4 << 6 << 7;
    output(&list1);
    DCLNode<int>* reversed = reverse(&list1);
    output(reversed);

    // Завдання 2
    DCLNode<int> list2(1);
    list2 << 2 << 3 << 4 << 5 << 6;
    DCLNode<int> list3(1);
    list3 << 2 << 3 << 4 << 5;
    cout << (compare(&list2, &list3) ? "\nlist2 and list3 are similar\n" : "\nlists are different\n");

    // Завдання 3
    DCLNode<int> list4(1);
    list4 << 3 << 7 << 9;
    DCLNode<int> list5(1);
    list5 << 2 << 5;
    DCLNode<int>* list6 = add(&list4, &list5);
    output(list6);

    // Завдання 4
    BSTNode<int> tree1(5);
    tree1.insert(11);
    tree1.insert(64);
    tree1.insert(57);
    tree1.insert(68);
    tree1.print();
    cout << "\nMirror of tree1: ";
    mirror(&tree1)->print();

    // Завдання 5
    cout << "Tree sum: " << tree_sum(&tree1) << endl;

    return 0;
}






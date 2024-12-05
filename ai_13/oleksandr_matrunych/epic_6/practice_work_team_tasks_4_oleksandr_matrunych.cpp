#include <iostream>
using namespace std;

// Структура для представлення вузла дерева
struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функція для створення дзеркальної версії дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    // Створюємо новий вузол з тим самим значенням
    TreeNode* new_node = new TreeNode(root->value);
    
    // Рекурсивно віддзеркалюємо ліву та праву гілки
    new_node->left = create_mirror_flip(root->right);
    new_node->right = create_mirror_flip(root->left);
    
    return new_node;
}

// Функція для виведення дерева (для тестування)
void print_tree(TreeNode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        print_tree(root->left);
        print_tree(root->right);
    }
}

int main() {
    // Створення дерева: 
    //       1
    //      / \
    //     2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Створення дзеркальної версії дерева
    TreeNode* mirrored_root = create_mirror_flip(root);

    // Виведення дзеркальної версії дерева
    cout << "Mirrored tree: ";
    print_tree(mirrored_root); // Виведе 1 3 2

    return 0;
}

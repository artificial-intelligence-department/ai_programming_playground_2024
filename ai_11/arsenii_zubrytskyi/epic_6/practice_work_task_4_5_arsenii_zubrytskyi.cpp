#include <iostream>
using namespace std;

// Структура вузла дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для створення нового вузла
TreeNode* createNode(int data) {
    return new TreeNode(data);
}

// Функція для друку дерева (обхід у порядку)
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

// Задача №4: Віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) return nullptr;

    // Створюємо новий вузол з тим самим значенням
    TreeNode* newRoot = createNode(root->data);

    // Міняємо місцями ліву і праву вітки рекурсивно
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

// Задача №5: Записати кожному батьківському вузлу суму підвузлів
int tree_sum(TreeNode* root) {
    if (!root) return 0;

    // Якщо це листок, його значення не змінюється
    if (!root->left && !root->right) return root->data;

    // Рекурсивно обчислюємо суму підвузлів
    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    // Записуємо суму підвузлів у вузол
    root->data = leftSum + rightSum;

    return root->data;
}

int main() {
    // Створення дерева
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Original tree (in-order): ";
    printTree(root);
    cout << endl;

    // Задача №4: Віддзеркалення дерева
    TreeNode* mirroredTree = create_mirror_flip(root);
    cout << "Mirrored tree (in-order): ";
    printTree(mirroredTree);
    cout << endl;

    // Задача №5: Сума підвузлів
    tree_sum(root);
    cout << "Tree with summed nodes (in-order): ";
    printTree(root);
    cout << endl;

    return 0;
}

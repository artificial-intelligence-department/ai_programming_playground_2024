#include <iostream>

using namespace std;

// Структура дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
};

// Функція створення дзеркального віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    // Якщо дерево порожнє, повертаємо null
    if (root == nullptr) {
        return nullptr;
    }
    
    // Створюємо новий вузол для поточного кореня
    TreeNode* newRoot = new TreeNode{root->data};
    
    //  віддзеркалення для лівої і правої гілок
    //для нового дерева іде вліво а операції виконує для нашого дерева справа
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);
    
    return newRoot;
}

// Функція для виведення дерева (це обхід в глибину)
void print_inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

// Функція для видалення дерева (для очищення пам'яті)
void delete_tree(TreeNode* root) {
    if (root == nullptr) return;
    
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}


//-  реалізувати функцію, яка ітеративно проходить по бінарному дереві і записує
 // у батьківський вузол суму значень підвузлів
int tree_sum(TreeNode* root) {
    // Якщо вузол порожній, повертаємо 0
    if (root == nullptr) {
        return 0;
    }

    // Якщо це тільки корінь, його значення не змінюється, повертаємо його
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    // Рекурсивно обчислюємо суми для лівого і правого підвузлів
    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    // Оновлюємо значення поточного вузла сумою підвузлів
    root->data = leftSum + rightSum;

    // Повертаємо нове значення вузла
    return root->data;
}

int main() {
    //дерево:
    //        4
    //       / \
    //      2   5
    //     / \
    //    1   3
    TreeNode* root = new TreeNode{4};
    root->left = new TreeNode{2};
    root->right = new TreeNode{5};
    root->left->left = new TreeNode{1};
    root->left->right = new TreeNode{3};
    
    // Виведемо дерево до оновлення
    cout << "Наше дерево: ";
    print_inorder(root);
    cout << endl;

    root = create_mirror_flip(root);
    cout << "Наше дерево після дзеркала: ";
    print_inorder(root);
    cout << endl;

    root = create_mirror_flip(root);
    // Оновлюємо дерево, записуючи суми підвузлів у кожний батьківський вузол
    tree_sum(root);

    // Виведемо дерево після оновлення
    cout << "Дерево коли ми сумуємо його два дочірні елементи: ";
    // ідемо в кінець потім вверх оновляєм елементи з кінця і обходим так само знизу вверх ";
    print_inorder(root);
    cout << endl;

    // Очищаємо пам'ять
    delete_tree(root);

    return 0;
}
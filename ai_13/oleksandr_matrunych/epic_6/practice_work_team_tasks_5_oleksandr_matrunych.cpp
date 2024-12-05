#include <iostream>
#include <stack>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode *root) {
    if (!root) return;

    std::stack<TreeNode*> stack;
    TreeNode* current = root;
    TreeNode* lastVisited = nullptr; // останнє число з яким працювали

    // Проходимо дерево в постфіксному порядку
    while (!stack.empty() || current != nullptr) {
        if (current != nullptr) {
            stack.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = stack.top();

            // Якщо правий підвузол є або він вже був відвіданий
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                // Обробляємо поточний вузол
                if (peekNode->left || peekNode->right) {
                    int sum = 0;
                    if (peekNode->left) sum += peekNode->left->value;
                    if (peekNode->right) sum += peekNode->right->value;
                    peekNode->value += sum;
                }
                lastVisited = stack.top();
                stack.pop();
            }
        }
    }
}

void print_tree(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->value << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    // Створюємо бінарне дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Before tree_sum: ";
    print_tree(root);
    std::cout << std::endl;

    // Викликаємо функцію для підрахунку сум підвузлів
    tree_sum(root);

    std::cout << "After tree_sum: ";
    print_tree(root);
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <queue>
#include <stack>
#include <list>

using namespace std;


void stack_example() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Stack top: " << s.top() << endl;
    s.pop();
    cout << "Stack top after pop: " << s.top() << endl;
}


void queue_example() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue front: " << q.front() << endl;
    q.pop();
    cout << "Queue front after pop: " << q.front() << endl;
}


void list_example() {
    list<int> lst = { 1, 2, 3 };
    lst.push_back(4);
    lst.push_front(0);
    cout << "List: ";
    for (int val : lst) cout << val << " ";
    cout << endl;
}


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void tree_example() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Inorder traversal of tree: ";
    inorder(root);
    cout << endl;
}

int main() {
    
    stack_example();

    
    queue_example();

  
    list_example();

   
    tree_example();

    return 0;
}

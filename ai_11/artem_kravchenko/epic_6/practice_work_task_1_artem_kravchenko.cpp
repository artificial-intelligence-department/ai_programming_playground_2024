#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node(int value) : data(value), next(nullptr){}
};

node* reverse(node* head){
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void print(node* head){
    node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool compare(node* h1, node* h2){
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data != h2->data)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return (h1 == nullptr && h2 == nullptr);
}

node* add(node *n1, node *n2){
    node* result = nullptr;
    node* tail = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum = carry;
        if (n1 != nullptr)
        {
            sum += n1->data;
            n1 = n1->next;
        }
        if (n2 != nullptr)
        {
            sum += n2->data;
            n2 = n2->next;
        }
        carry = sum / 10;
        node* new_node = new node(sum % 10);
        if (result == nullptr)
        {
            result = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            tail = new_node;
        }
        
    }
    return result;
}

struct tree{
    int val;
    tree* left;
    tree* right;

    tree(int value) : val(value), left(nullptr), right(nullptr){}
};

tree* mirror(tree* root){
    if (root == nullptr)
    {
        return nullptr;
    }
    tree* new_root = new tree(root->val);
    new_root->left = mirror(root->right);
    new_root->right = mirror(root->left);
    return new_root;
}

void print_tree(tree* root){
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int tree_sum(tree* root){
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->val;
    }
    int left_sum = tree_sum(root->left);
    int right_sum = tree_sum(root->right);
    root->val = left_sum + right_sum;
    return root->val;
}

int main(){
    cout << "Завдання 1:" << endl;
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    cout << "Заданий список:" << endl;
    print(head);
    head = reverse(head);

    cout << "Обернений список:" << endl;
    print(head);

    cout << "Завдання 2:" << endl;
    node* list1 = new node(1);
    list1->next = new node(2);
    list1->next->next = new node(3);

    node* list2 = new node(1);
    list2->next = new node(2);
    list2->next->next = new node(3);
    cout << "Порівняння списків: " << (compare(list1, list2) ? "списки рівні" : "списки не рівні") << endl;

    cout << "Завдання 3:" << endl;
    node* num1 = new node(9);
    num1->next = new node(9);
    num1->next->next = new node(9);

    node* num2 = new node(1);

    node* sum = add(num1, num2);
    cout << "Результат: " << endl;
    print(sum);

    cout << "Завдання 4:" << endl;
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);

    cout << "Задане дерево:" << endl;
    print_tree(root);
    cout << endl;

    cout << "Відзеркалене дерево:" << endl;
    tree* mirrored = mirror(root);
    print_tree(mirrored);
    cout << endl;

    cout << "Завдання 5:" << endl;
    tree* root_sum = new tree(1);
    root_sum->left = new tree(2);
    root_sum->right = new tree(3);
    root_sum->left->left = new tree(4);
    root_sum->left->right = new tree(5);

    tree_sum(root_sum);
    cout << "Результат: " << endl;
    print_tree(root_sum);
    return 0;
}
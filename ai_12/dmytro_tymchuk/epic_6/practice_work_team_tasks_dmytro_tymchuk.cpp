#include<iostream>
#include<string>
using namespace std;


//Linked list
struct Node
{
    int data;
    Node* next;
};

//Додавання елемента в кінець
Node* push_back(Node* head, const int& element)
{
    Node* new_node = new Node;
    new_node->data = element;
    new_node->next = nullptr;

    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = new_node;
    }

    return head;
}

//Виведення списку
void print_list(Node* head)
{
    if (head == nullptr)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
}

//Реверс списку
Node* reverse_list(Node* head)
{
    if (head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return 0;
    }
    else
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        
        return prev;
    }
}

//Порівняння на рівність двох списків
bool compare(Node* head_1, Node* head_2)
{
    Node* current_1 = head_1;
    Node* current_2 = head_2;

    while ((current_1 != nullptr) && (current_2 != nullptr))
    {
        if (current_1->data != current_2->data)
        {
            return false;
        }
        current_1 = current_1->next;
        current_2 = current_2->next;
    }

    if ((current_1 != nullptr) || (current_2 != nullptr))
    {
        return false;
    }
    else return true;
}

//Додавання двох великих чисел
Node* add_two_numbers(Node* n1, Node* n2)
{
    Node* current_1 = n1;
    Node* current_2 = n2;
    Node* sum = nullptr;
    int r = 0;
    int s = 0;
    while (current_2 != nullptr)
    {
        s = current_1->data + current_2->data + r;

        if (s > 9)
        {
            sum = push_back(sum, s % 10);
            r = s / 10;
        }
        else
        {
            sum = push_back(sum, s);
            r = 0;
        }

        current_1 = current_1->next;
        current_2 = current_2->next;
    }

    if (current_1 != nullptr)
    {
        while (current_1 != nullptr)
        {
            s = current_1->data + r;

            if (s > 9)
            {
                sum = push_back(sum, s % 10);
                r = s / 10;
            }
            else
            {
                sum = push_back(sum, s);
                r = 0;
            }

            current_1 = current_1->next;
        } 
    }
    else if (r != 0)
    {
        sum = push_back(sum, r);
    }
    
    return sum;
}

//Виведення числа
void print_number(Node* head)
{
    if (head == nullptr)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout<<current->data;
            current = current->next;
        }
        cout<<endl;
    }
}
//Linked list

//Binary tree
struct tree_node
{
    int data;
    tree_node* left;
    tree_node* right;

    tree_node(int value) : data(value), left(nullptr), right(nullptr){}
};



//Функція для вставлення елемента в дерево
tree_node* insert(tree_node* node, int value)
{
    if (node == nullptr)
    {
        return new tree_node(value);
    }
    else 
    {
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

}

//Віддзеркалення дерева
tree_node* create_mirror_flip(tree_node* node)
{

    if (node == nullptr)
    {
        return nullptr;
    }

    tree_node* new_node = new tree_node(node->data);

    new_node->right = create_mirror_flip(node->left);
    new_node->left = create_mirror_flip(node->right);

    return new_node;
}

//Сума підвузлів
tree_node* tree_sum (tree_node* node)
{
    
    if ((node == nullptr) || ((node->left == nullptr) && (node->right == nullptr))) return nullptr;
     
    tree_sum(node->left);
    tree_sum(node->right);

    node->data = 0;
    if (node->right != nullptr)
    {
       node->data += node->right->data; 
    }
    if (node->left != nullptr)
    {
       node->data += node->left->data; 
    }

    return node;
}

//Виведення дерева
void print_tree(tree_node* node)
{
    if (node == nullptr)
    {
        return;
    }

    cout<<node->data<<" ";
    print_tree(node->left);
    print_tree(node->right);

}
//Binary tree

int main()
{
    //task_1
    Node* head = nullptr;

    for (int i = 0; i < 10; i++)
    {
        head = push_back(head, i);
    }
    
    cout<<"Starting list: ";
    print_list(head);

    Node* new_head = reverse_list(head);
    cout<<"Reversed list: ";
    print_list(new_head);

    //task 2
    Node* head_1 = nullptr;
    Node* head_2 = nullptr;

    head_1 = push_back(head_1, 5);
    head_1 = push_back(head_1, 6);
    head_1 = push_back(head_1, 5);
    head_1 = push_back(head_1, 7);
    head_1 = push_back(head_1, 8);

    head_2 = push_back(head_2, 5);
    head_2 = push_back(head_2, 6);
    head_2 = push_back(head_2, 4);

    if (compare(head_1, head_2))
    {
        cout<<"Lists are equal"<<endl;
    }
    else cout<<"Lists aren`t equal"<<endl;

    //task 3
    string num_1, num_2, box;
    cout<<"Enter first number: ";
    cin>>num_1;
    cout<<"Enter second number: ";
    cin>>num_2;

    if (num_2.length() > num_1.length())
    {
        box = num_1;
        num_1 = num_2;
        num_2 = box;
    }

    Node* n1 = nullptr;
    Node* n2 = nullptr;

    for (int i = num_1.length() - 1; i >= 0; i--)
    {
        n1 = push_back(n1, (int)num_1[i] - 48);
    }
    for (int i = num_2.length() - 1; i >= 0; i--)
    {
        n2 = push_back(n2, (int)num_2[i] - 48);
    }
    
    Node* sum;
    sum = add_two_numbers(n1, n2);

    Node* new_sum = reverse_list(sum);
    cout<<num_1<<" + "<<num_2<<" = ";
    print_number(new_sum);
   
    //task 4
    tree_node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 10);

    
    tree_node* new_root;
    new_root = create_mirror_flip(root);

    cout<<"First tree: ";
    print_tree(root);

    cout<<"\nMirrored tree: ";
    print_tree(new_root);

    root = tree_sum(root);
    cout<<"\nSum tree: ";
    print_tree(root);

    return 0;
}
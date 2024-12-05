#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *pushBack(Node *head, int element)
{
    Node *newEl = new Node{element, nullptr};

    if (head == nullptr)
    {
        head = newEl;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newEl;
    }
    return head;
};
void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
void printNum(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data;
        current = current->next;
    }
}
Node *reverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return 0;
    }
    else
    {
        Node *current = head;
        Node *next = nullptr;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = temp;
            temp = current;
            current = next;
        }
        return temp;
    }
};
bool compare(Node *headF, Node *headS)
{

    Node *current1 = headF;
    Node *current2 = headS;

    while (current1 != nullptr && current2 != nullptr)
    {
        if (current1->data != current2->data)
        {
            return false;
        };
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 != nullptr || current2 != nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
};

Node *addNum(Node *num1, Node *num2)
{
    Node *current1 = num1;
    Node *current2 = num2;
    Node *sum = nullptr;
    int tempSum = 0;
    int over = 0;

    while (current2 != nullptr)
    {
        tempSum = current1->data + current2->data + over;

        if (tempSum <= 9)
        {
            sum = pushBack(sum, tempSum);
            over = 0;
        }
        if (tempSum > 9)
        {
            sum = pushBack(sum, tempSum % 10);
            over = tempSum / 10;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 != nullptr)
    {
        while (current1 != nullptr)
        {
            tempSum = current1->data + over;
            if (tempSum <= 9)
            {
                sum = pushBack(sum, tempSum);
                over = 0;
            }
            if (tempSum > 9)
            {
                sum = pushBack(sum, tempSum % 10);
                over = tempSum / 10;
            }
            current1 = current1->next;
        }
    }
    else if (over != 0)
    {
        sum = pushBack(sum, over);
    }
    return sum;
};

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int value) : data(value), left(nullptr), right(nullptr) {};
};

treeNode *insert(treeNode *node, int value)
{
    if (node == nullptr)
    {
        return new treeNode(value);
    }
    else
    {
        if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            node->left = insert(node->left, value);
        }
        return node;
    }
};
void printTree(treeNode *node)
{
    if (!node)
    {
        return;
    }
    cout << node->data << " ";
    printTree(node->left);
    printTree(node->right);
}

treeNode *mirror(treeNode *node)
{
    if (!node)
        return 0;

    swap(node->left, node->right);
    mirror(node->left);
    mirror(node->right);
    return node;
};

treeNode *treeSum(treeNode *node)
{
    if ((node == nullptr) || ((node->left == nullptr) && (node->right == nullptr)))
        return nullptr;

    treeSum(node->left);
    treeSum(node->right);

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

int main()
{
    cout << "TASK 1" << endl;
    cout << endl;
    Node *head = nullptr;

    for (int i = 1; i < 16; i++)
    {
        head = pushBack(head, i);
    }
    cout << "First list:" << endl;
    printList(head);
    Node *head1 = reverse(head);
    cout << endl;
    cout << "Reversed List:" << endl;
    printList(head1);

    cout << endl;
    cout << endl;
    cout << "TASK 2" << endl;
    cout << endl;

    Node *headF = nullptr;
    Node *headS = nullptr;

    headF = pushBack(headF, 1);
    headF = pushBack(headF, 5);
    headF = pushBack(headF, 3);
    headF = pushBack(headF, 1);
    headF = pushBack(headF, 5);
    headF = pushBack(headF, 7);

    headS = pushBack(headS, 1);
    headS = pushBack(headS, 5);
    headS = pushBack(headS, 3);
    headS = pushBack(headS, 100);
    headS = pushBack(headS, 5);
    headS = pushBack(headS, 7);

    if (compare(headF, headS))
    {
        cout << "List are identical" << endl;
    }
    else
    {
        cout << "List are different" << endl;
    }

    cout << endl;
    cout << "TASK 3" << endl;
    cout << endl;

    string num1, num2, temp;
    cout << "First number" << endl;
    cin >> num1;
    cout << "Second number" << endl;
    cin >> num2;

    if (num2.length() > num1.length())
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    Node *n1 = nullptr;
    Node *n2 = nullptr;

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        n1 = pushBack(n1, (int)num1[i] - 48);
    }
    for (int i = num2.length() - 1; i >= 0; i--)
    {
        n2 = pushBack(n2, (int)num2[i] - 48);
    }
    Node *sum = addNum(n1, n2);

    cout << "Sum is equal to: ";
    printNum(reverse(sum));
    cout << endl;
    cout << endl;
    cout << "TASK 4" << endl;
    cout << endl;

    treeNode *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 20);
    root = insert(root, 23);
    root = insert(root, 12);
    root = insert(root, 3);
    cout << "Binary tree:" << endl;
    printTree(root);
    treeNode *newTree = mirror(root);
    cout << endl;
    cout << "Mirrored tree:" << endl;
    printTree(root);
    cout << endl;
    cout << endl;
    cout << "TASK 5" << endl;
    cout << endl;
    cout << "Tree Sum:" << endl;
    root = treeSum(root);
    printTree(root);

    return 0;
}
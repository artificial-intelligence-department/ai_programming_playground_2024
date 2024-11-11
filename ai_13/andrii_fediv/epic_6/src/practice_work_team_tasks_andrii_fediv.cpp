#include <iostream>
#include <vector>

using namespace std;

template <typename T>
// double linked list
struct DCLNode
{
    T data;
    DCLNode *next;
    DCLNode *prev;
    DCLNode(T value)
    {
        this->data = value;
        this->next = nullptr;
        this->prev = nullptr;
    };
    DCLNode<T> &operator<<(T value)
    {
        DCLNode<T> *temp = new DCLNode<T>(value);
        this->next = temp;
        return *this->next;
    };
};

template <typename T>
// bynary search tree
struct BSTNode
{
    T data;
    BSTNode *lchild;
    BSTNode *rchild;
    int size;

    BSTNode(T value)
    {
        this->data = value;
        this->lchild = nullptr;
        this->rchild = nullptr;
        this->size = 1;
    };

    void setplace(BSTNode *node, T value)
    {
        if (node->data > value)
        {
            if (node->lchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->lchild = newNode;
                return;
            }
            else
                setplace(node->lchild, value);
        }
        else if (node->data < value)
        {
            if (node->rchild == nullptr)
            {
                BSTNode<T> *newNode = new BSTNode<T>(value);
                node->rchild = newNode;
                return;
            }
            else
                setplace(node->rchild, value);
        }
        else
        {
            cerr << "\nTHIS VALUE ALREDY EXISTS\n";
            return;
        }
    }

    BSTNode<T> &operator<<(T value)
    {
        setplace(this, value);
        return *this;
    };

    void print(const std::string &prefix, const BSTNode *node, bool left)
    {
        if (node == nullptr)
            cout << prefix << (left ? "├──" : "└──") << "#" << endl;
        else
        {
            cout << prefix << (left ? "├──" : "└──") << node->data << endl;
            if (node->lchild == nullptr & node->rchild == nullptr)
                return;
            print(prefix + (left ? "│   " : "    "), node->lchild, true);
            print(prefix + (left ? "│   " : "    "), node->rchild, false);
        }
    };

    void print() { print("", this, false); };
};

///////////////////////////TASK 1//////////////////////
template <typename T>
DCLNode<T> &reverse(const DCLNode<T> &node)
{

    const DCLNode<T> *current = &node;
    DCLNode<T> *head = nullptr;
    while (current != nullptr)
    {
        DCLNode<T> *newDCLNode = new DCLNode<T>(current->data);
        newDCLNode->next = head;
        head = newDCLNode;
        current = current->next;
    }
    return *head;
}

template <typename T>
void output(DCLNode<T> node)
{
    while (node.next != nullptr)
    {
        cout << node.data << " ";
        node = *(node.next);
    }
    cout << node.data << endl;
}
///////////////////////////TASK 2//////////////////////
template <typename T>
bool compare(const DCLNode<T> &list1, const DCLNode<T> &list2)
{
    const DCLNode<T> *node1 = &list1;
    const DCLNode<T> *node2 = &list2;
    while (true)
    {
        if (node1 == nullptr && node2 == nullptr)
            break;
        if ((node1->data != node2->data) || node2->next == nullptr && node1->next != nullptr || node2->next != nullptr && node1->next == nullptr)
            return false;
        node1 = node1->next;
        node2 = node2->next;
    }
    return true;
}
///////////////////////////TASK 3//////////////////////
template <typename T>
DCLNode<T> *add(DCLNode<T> *node1, DCLNode<T> *node2)
{

    int number1 = 0, number2 = 0, acc = 1;

    while (node1 != nullptr || node2 != nullptr)
    {
        if (node1 != nullptr)
        {
            number1 += (node1->data) * acc;
            node1 = node1->next;
        }
        if (node2 != nullptr)
        {
            number2 += (node2->data) * acc;
            node2 = node2->next;
        }
        acc *= 10;
    }
    int sum = number1 + number2, acc2 = 1;
    DCLNode<T> *current = new DCLNode<T>(sum % 10);
    DCLNode<T> *answer = current;
    while (sum / (acc2 * 10) != 0)
    {
        acc2 *= 10;
        DCLNode<T> *temp = new DCLNode<T>(((sum / acc2) % 10));
        current->next = temp;
        current = current->next;
    }
    return answer;
}
///////////////////////////TASK 4//////////////////////
template <typename T>
BSTNode<T> *create_mirror_flip(BSTNode<T> *root)
{
    if (root == nullptr)
    {
        return root;
    }
    BSTNode<T> *temp = root->lchild;
    root->lchild = create_mirror_flip(root->rchild);
    root->rchild = create_mirror_flip(temp);
    return root;
}

///////////////////////////TASK 5//////////////////////
int tree_sum(BSTNode<int> *root)
{
    if (root->lchild == nullptr && root->rchild == nullptr)
        return root->data;
    if (root->lchild == nullptr)
        return root->data = tree_sum(root->rchild);
    if (root->rchild == nullptr)
        return root->data = tree_sum(root->lchild);
    return root->data = tree_sum(root->lchild) + tree_sum(root->rchild);
}

int main()
{
    ///////////////////////////TASK 1
    DCLNode<int> list1(3);
    list1 << 2 << 4 << 6 << 7;
    output(list1);
    list1 = reverse(list1);
    output(list1);
    ///////////////////////////TASK 2
    DCLNode<int> list2(1);
    list2 << 2 << 3 << 4 << 5 << 6;
    DCLNode<int> list3(1);
    list3 << 2 << 3 << 4 << 5;
    cout << (compare(list2, list3) ? "\nlist2 and list 3 are similar\n" : "\nlists are different\n");
    ///////////////////////////TASK 3
    DCLNode<int> list4(1);
    list4 << 3 << 7 << 9;
    DCLNode<int> list5(1);
    list5 << 2 << 5;
    DCLNode<int> *list6 = add(&list4, &list5);
    output(*list6);
    ///////////////////////////TASK 4
    BSTNode<int> tree1(5);
    tree1 << 11 << 64 << 57 << 68 << 464 << 47 << 1000 << 61 << 66 << -7 << -332 << -23 << -13 << 45 << -33 << 48;
    tree1.print();
    create_mirror_flip(&tree1)->print();
    ///////////////////////////TASK 5
    tree_sum(&tree1);
    tree1.print();
    return 0;
}
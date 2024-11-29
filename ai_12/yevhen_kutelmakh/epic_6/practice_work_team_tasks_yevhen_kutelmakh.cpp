#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    TreeNode *root;
    void mirrorHelper(TreeNode* original, TreeNode*& mirrored) {
        if (original == nullptr) return;
        mirrored = new TreeNode(original->value);
        mirrorHelper(original->right, mirrored->left);
        mirrorHelper(original->left, mirrored->right);
    }
public:
    BinaryTree() {
        root = nullptr;
    }

    void add(int val) {
        if(root == nullptr) {
            root = new TreeNode(val);
        } else {
            TreeNode *cur = root;
                while(true) {
                if(val < cur->value) {
                    if(cur->left == nullptr) {
                        cur->left = new TreeNode(val);
                        break;
                    } else 
                        cur = cur->left;
                } else {
                    if(cur->right == nullptr) {
                        cur->right = new TreeNode(val);
                        break;
                    } else 
                        cur = cur->right;
                }
            }
        }
    }

    TreeNode* getroot() {
        return root;
    }

    void postorderTraverse(TreeNode* r) {
        if (r != nullptr) {
            postorderTraverse(r->left); 
            postorderTraverse(r->right);
            cout << r->value << " "; 
        }
    }

    BinaryTree mirror() {
        BinaryTree tree;
        mirrorHelper(root, tree.root);
        return tree;
    }

    void treeSum(TreeNode *r) {
        if(r == nullptr || (r->left == nullptr && r->right == nullptr)) return;
        treeSum(r->left);
        treeSum(r->right);
        r->value = 0;
        if(r->left != nullptr)
            r->value += r->left->value;
        if(r->right != nullptr)
            r->value += r->right->value;
    }
};

class LinkedList {
    Node* head;
    int size;
public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr)
            head = newNode;
        else {
            Node* curr = head;
            while(curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void print() {
        if(head == nullptr)
            cout << "The list is empty";
        else {
            Node* curr = head;
            while(curr != nullptr) {
                cout << curr->value << " ";
                curr = curr->next;
            }
        } 
        cout << endl;
    }

    void reverse() {
        if (!head || !head->next) 
            return;
        Node* start = head;
        Node *last = head;
        for(int i = 1; i < size; i++)
            last = last->next;
        while(start != last && start->next != last) {
            int temp = start->value;
            start->value = last->value;
            last->value = temp;

            start = start->next;
            Node* prev = head;
            while(prev->next != last)
                prev = prev->next;
            last = prev;
        }
    }

    bool compare(LinkedList &l) {
        if(size != l.size) return false;
        Node *N1 = head;
        Node *N2 = l.head;
        for(int i = 0; i < size; i++) {
            if(N1->value != N2->value) return false;
            N1 = N1->next;
            N2 = N2->next;
        }
        return true;
    }

    int task3() {
        Node* newN = head;
        LinkedList list;
        int sum = 0;
        for(int i = 0; i < size; i++) {
            int n = newN->value * pow(10, i);
            list.pushBack(n);
            sum += n;
            newN = newN->next;
        }
        return sum;
    }
};

int main() {
    cout << "Working with Linked List\n";
    LinkedList list1;
    list1.pushBack(5);
    list1.pushBack(3);
    list1.pushBack(9);
    list1.pushBack(5);
    list1.pushBack(7);
    cout << "Our list: \n";
    list1.print();
    list1.reverse();
    cout << "Our list after reversing: \n";
    list1.print();
    list1.reverse();
    cout << "We have reversed starting list one more time:\n";
    list1.print();

    LinkedList list2;
    list2.pushBack(5);
    list2.pushBack(3);
    list2.pushBack(9);
    list2.pushBack(5);
    list2.pushBack(7); // Змінений елмент - 7 щоб були однакові
    cout << "Our second list:\n";
    list2.print();

    if(list1.compare(list2)) cout << "Lists are equal!\n";
    else cout << "Lists are not equal!\n";

    cout << "Sum for task 3 of the first tree is: " << list1.task3(); 

    cout << "\n--------------------------\n";

    cout << "Working with Binary Tree\n";
    BinaryTree tree1;
    tree1.add(7);
    tree1.add(10);
    tree1.add(4);
    tree1.add(1);
    tree1.add(5);
    tree1.add(8);
    tree1.add(9);
    tree1.add(12);
    cout << "Post-order traverse will look like this for our first tree: \n";
    TreeNode* r1 = tree1.getroot();
    tree1.postorderTraverse(r1);
    BinaryTree tree2 = tree1.mirror();
    cout << "\nThe new - mirrored tree has been created, post-order traverse looks likse this:\n";
    TreeNode* r2 = tree2.getroot();
    tree2.postorderTraverse(r2);

    tree1.treeSum(r1);
    tree1.treeSum(r2);
    cout << "\nPost-order traverse will look like this for our first tree after task5: \n";
    r1 = tree1.getroot();
    tree1.postorderTraverse(r1);
    cout << "\nPost-order traverse will look like this for our second tree after task5: \n";
    r2 = tree2.getroot();
    tree2.postorderTraverse(r2);
    return 0;
}
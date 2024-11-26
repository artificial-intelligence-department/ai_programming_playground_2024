#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void printLL(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* insert(Node* head, const vector<int>& values) {
    Node* newNode = new Node(values[0]);
    head = newNode;
    Node* current = head;
    for (int i = 1; i < values.size(); i++) {
        Node* newNode = new Node(values[i]);
        current->next = newNode;  
        current = newNode;
    }
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool compare(Node* head1, Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == nullptr && head2 == nullptr;
}

Node* add(Node* head1, Node* head2) {
    Node* result = new Node(0);
    Node* current1 = head1;
    Node* current2 = head2;
    Node* currentr = result;
    
    int sum, carry = 0;
    
    while (current1 != nullptr || current2 != nullptr || carry != 0) {
        sum = carry;

        if (current1 != nullptr) {
            sum += current1->data;
            current1 = current1->next;
        }

        if (current2 != nullptr) {
            sum += current2->data;
            current2 = current2->next;
        }

        carry = sum / 10;
        currentr->next = new Node(sum % 10);
        currentr = currentr->next;
    }
    
    return result->next;
}

struct TreeNode {
    int data;      
    TreeNode* left;    
    TreeNode* right;   


    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createMirrorFlip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(root->data);

    newNode->left = createMirrorFlip(root->right);
    newNode->right = createMirrorFlip(root->left);

    return newNode;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int treeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    int leftSum = treeSum(root->left);
    int rightSum = treeSum(root->right);

    root->data = leftSum + rightSum;

    return root->data;
}


int main() {
    Node* list = nullptr;
    vector<int> initVec;

    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 100 + 1;
        initVec.push_back(randomNumber);
    }
// FIRST TASK
    cout << "First Task" << endl;

    list = insert(list, initVec);

    cout << "Original List: ";
    printLL(list);

    Node* originalList = insert(nullptr, initVec);
    Node* reversedList = reverse(list);

    cout << "Reversed List: ";
    printLL(reversedList);

// SECOND TASK
    cout << endl << "Second Task" << endl;


    if (compare(originalList, originalList)) {
        printLL(originalList);
        printLL(originalList);
        cout << "Lists are identical";
    }
    else {
        printLL(originalList);
        printLL(originalList);
        cout << "Lists are different";
    }

    cout << endl << endl;

    if (compare(originalList, reversedList)) {
        printLL(originalList);
        printLL(reversedList);
        cout << "Lists are identical";
    }
    else {
        printLL(originalList);
        printLL(reversedList);
        cout << "Lists are different";
    }

// THIRD TASK
    cout << endl << endl << "Third Task" << endl;
    vector<int> num1 = {6, 7, 5, 1, 2};
    vector<int> num2 = {5, 6, 2};

    Node* list1 = insert(list1, num1);
    Node* list2 = insert(list2, num2);

    cout << "Number 1: ";
    printLL(list1);

    cout << "Number 2: ";
    printLL(list2);

    Node* result = add(list1, list2);

    cout << "Sum: ";
    printLL(result);

// FORTH TASK
    cout << endl << "Forth Task" << endl;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(2);

    TreeNode* mirrorRoot = createMirrorFlip(root);

    cout << "Original tree (in order): ";
    printTree(root);
    cout << endl;

    cout << "Mirror tree (in order): ";
    printTree(mirrorRoot);
    cout << endl;

// FIFTH TASK
    cout << endl << "Fifth Task" << endl;
    

    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    treeSum(root);

    cout << "Tree after updating node values with subtree sums: ";
    printTree(root);
    cout << endl;

    return 0;
}
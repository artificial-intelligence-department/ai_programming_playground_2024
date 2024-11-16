#include <iostream>
using namespace std;



struct Node{
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) { } 
    Node() : next(nullptr) {}
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : data(data), left(left), right(right) {}
};

Node* reverse(Node *head)
{
    Node* tmp = head;
    Node* tmpCopy = nullptr;
    Node* prev = nullptr;

    while(tmp != nullptr)
    {
        tmpCopy = tmp->next; // head = 1 : tmpCopy = 4
        tmp->next = prev; // 1 -> nullptr
        
        prev = tmp; 


        tmp = tmpCopy;
    }
    return prev;
}



void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

bool compare(Node *h1, Node *h2)
{
    unsigned int size1 = 0, size2= 0;
    Node* h1Copy = h1, *h2Copy = h2;
    while(h1Copy)
    {
        size1++;
        h1Copy = h1Copy->next;
    }

    while(h2Copy)
    {
        size2++;
        h2Copy = h2Copy->next;
    }

    if(size1 != size2) { return false; }
    else
    {
        while(h1 && h2)
        {
            if(h1->data != h2->data) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
    }

    return true;
}

Node* add(Node *head1, Node *head2)
{
    Node* reversehead1 = reverse(head1);
    Node* reversehead2 = reverse(head2);
    int numb1 = 0 , numb2 = 0;
   
    Node* reversehead1Copy = reversehead1;
    Node* reversehead2Copy = reversehead2;

    while(reversehead1Copy)
    {
        numb1 = numb1 * 10 + reversehead1Copy->data;
        reversehead1Copy = reversehead1Copy->next;
    }

    
    while(reversehead2Copy)
    {
        numb2 = numb2 * 10 + reversehead2Copy->data;
        reversehead2Copy = reversehead2Copy->next;
    }


    int sum = numb1 + numb2;
    Node* newhead = nullptr;
    Node* current = nullptr;
    do {
        int digit = sum % 10;  
        Node* newNode = new Node(digit, nullptr);  

        if (newhead == nullptr) {
            newhead = newNode; 
            current = newhead;
        } else {
            current->next = newNode; 
            current = current->next;
        }

        sum /= 10; 
    } while (sum > 0);
    return newhead;
}

TreeNode *create_mirror_flip(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    
    TreeNode* newValue = new TreeNode(root->data);

    
    newValue->left = create_mirror_flip(root->right);
    newValue->right = create_mirror_flip(root->left);

    return newValue;
}

void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) return;
    printTree(root->right, level + 1);
    cout << string(level * 4, ' ') << root->data << endl;
    printTree(root->left, level + 1);
}

TreeNode* tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* leftSumTree = tree_sum(root->left);
    TreeNode* rightSumTree = tree_sum(root->right);

    int leftSum = (leftSumTree != nullptr) ? leftSumTree->data : 0;
    int rightSum = (rightSumTree != nullptr) ? rightSumTree->data : 0;

    TreeNode* newNode = new TreeNode(root->data + leftSum + rightSum, leftSumTree, rightSumTree);

    return newNode;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){

    // Node* head1 =  new Node(9,new Node(9,new Node(9,nullptr)));
    // Node *copy1 = head1;
    // Node* head2 =  new Node(1, nullptr);

    // cout << "Listт 1: ";
    // printList(head1);
    // cout << endl;

    // cout << "Listт 2: ";
    // printList(head2);
    // cout << endl;
    
    //  boolalpha(cout);
    // cout << "Is equal: " << compare(head1,head2);
    // cout << endl;

    // cout << "Summ of 2 listd equal: " << endl;
    // printList(add(head1,head2));
    //  cout << endl;

    // Node* reversedList = reverse(copy1);
    // cout << "Reversed List: ";
    // printList(reverse(copy1));
    // cout << endl;

    Node* head = new Node(1,nullptr);
    head->next = new Node(2,nullptr);
    head->next->next = new Node(3,nullptr);
    head->next->next->next = new Node(4,nullptr);
    head->next->next->next->next = new Node(5,nullptr);

    cout << "List:" << endl;
    printList(head);
    head = reverse(head);

    cout << "Reversed list:" << endl;
    printList(head);

    Node* list1 = new Node(1,nullptr);
    list1->next = new Node(2,nullptr);
    list1->next->next = new Node(3,nullptr);

    Node* list2 = new Node(1,nullptr);
    list2->next = new Node(2,nullptr);
    list2->next->next = new Node(3,nullptr);
    cout << (compare(list1, list2) ? "Lists equal" : "Lists not equal") << endl;

    Node* num1 = new Node(9,nullptr);
    num1->next = new Node(9,nullptr);
    num1->next->next = new Node(9,nullptr);

    Node* num2 = new Node(1,nullptr);

    Node* sum = add(num1, num2);
    cout << "Summ: " << endl;
    sum = reverse(sum);
    printList(sum);

    

    TreeNode* root = new TreeNode(1, nullptr, nullptr);
    root->left = new TreeNode(2, nullptr, nullptr);
    root->right = new TreeNode(3, nullptr, nullptr);

    root->left->left = new TreeNode(4, nullptr, nullptr);
    root->left->right = new TreeNode(5, nullptr, nullptr);

    root->right->left = new TreeNode(8, nullptr, nullptr);
    root->right->right = new TreeNode(4, nullptr, nullptr);

    cout << "Tree in vertical format" << endl;
    printTree(root);

    cout << "Reversed tree in vertical format" << endl;
    TreeNode* mirroredRoot = create_mirror_flip(root);
    printTree(mirroredRoot);

    cout << "Tree sum:" << endl;
    TreeNode* sumTree = tree_sum(root);
    printTree(sumTree);

    



    return 0;
}

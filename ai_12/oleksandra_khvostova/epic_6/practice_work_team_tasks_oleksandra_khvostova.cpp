#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class List{
    private:
    struct Node{
        int data;
        Node* previous;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;

    public:
    #include <string>
        List()
            : head(nullptr), tail(nullptr), size(0)
        {}

        void Show() const{
            if (size == 0){
                cout<<"List is empty"<<endl;
                return;
            }
            Node *current = head;
            while(current!=nullptr){
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }

        void Clear(){
            while (head!=nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        void PushBack(const int& value){
            if (size==0){
                head = new Node {value, nullptr, nullptr};
                tail=head;
            }
            else{
                tail->next = new Node {value, tail, nullptr};
                tail=tail->next;
            }
            size++;
        }

    //Задача 1
    void Reverse(){
        Node* current = head;
        Node* temp = nullptr;
        
        while(current != nullptr){
            temp=current->previous;
            current->previous = current->next;
            current->next = temp;

            current = current->previous;
        }
        if(temp!=nullptr){
            head = temp->previous;
        }
    }

    //Задача 2
    bool Compare(const List& list1, const List& list2){
        if(list1.size!=list2.size){
            return false;
        }
        Node* current1 = list1.head;
        Node* current2 = list2.head;
            while(current1!=nullptr && current1!=nullptr){
                if(current1->data!=current2->data){
                    return false;
                }
                current1=current1->next;
                current2=current2->next;
            }
            return (current1==nullptr && current1==nullptr);
    }

    //Задача 3
        static List AddArrays(const vector<int>& arr1, const vector<int>& arr2) {
            List result;
            int carry = 0;
            size_t i = 0;
            size_t maxLength = max(arr1.size(), arr2.size());

            while (i < maxLength || carry != 0) {
                int x = (i < arr1.size()) ? arr1[i] : 0;
                int y = (i < arr2.size()) ? arr2[i] : 0;
                int sum = carry + x + y;
                carry = sum / 10;
                result.PushBack(sum % 10);
                i++;
            }

            return result;
        }

        static List AddLists(const List& list1, const List& list2) {
            string num1_str, num2_str;
            Node* current1 = list1.head;
            Node* current2 = list2.head;

            while (current1 != nullptr) {
                num1_str += to_string(current1->data);
                current1 = current1->next;
            }
            while (current2 != nullptr) {
                num2_str += to_string(current2->data);
                current2 = current2->next;
            }

            vector<int> num1, num2;
            for (char c : num1_str) num1.push_back(c - '0');
            for (char c : num2_str) num2.push_back(c - '0');

            List result = AddArrays(num1, num2);
            return result;
        }

};

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* CreateMirrorFlip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = CreateMirrorFlip(root->right);
    newRoot->right = CreateMirrorFlip(root->left);

    return newRoot;
}

void InorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    InorderTraversal(root->left);
    cout << root->val <<" ";
    InorderTraversal(root->right);
}

int TreeSum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = TreeSum(root->left);
    int rightSum = TreeSum(root->right);

    if (root->left || root->right) {
        root->val += leftSum + rightSum;
    }

    return root->val;
}

int main(){
    List list1;
    for (int i=1; i<6; i++){
        list1.PushBack(i);
    }
    List list2;
    for (int i=1; i<5; i++){
        list2.PushBack(i);
    }
    list1.Reverse(); //Задача 1
    cout<<"Reversed list1: ";
    list1.Show();
    list1.Reverse();
    cout<<"list1: ";
    list1.Show();
    cout<<"list2: ";
    list2.Show();

    if(list1.Compare(list1, list2)){ //Задача 2
        cout<<"the lists are equal"<<endl;
    }
    else{
        cout<<"the lists are not equal"<<endl;
    }
    
    List result = List::AddLists(list1, list2); //Задача 3
    result.Show();
    
    // Дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree (inorder): ";
    InorderTraversal(root);
    cout << endl;

    //Задача 4
    TreeNode* mirrorRoot = CreateMirrorFlip(root);

    cout << "Mirror flipped tree (inorder): ";
    InorderTraversal(mirrorRoot);
    cout << endl;

    TreeSum(root);

    //Задача 5
    cout << "Tree after sum operation (inorder): ";
    InorderTraversal(root);
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    delete mirrorRoot->left->left;
    delete mirrorRoot->left->right;
    delete mirrorRoot->left;
    delete mirrorRoot->right->left;
    delete mirrorRoot->right->right;
    delete mirrorRoot->right;
    delete mirrorRoot;

    result.Clear();
    list1.Clear();
    list2.Clear();
    return 0;
}
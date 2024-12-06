#include <iostream>

using namespace std;

template<typename T>

class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    int treesize;

    void insert(Node*& node, T value){
        if (node == nullptr){
            node = new Node(value);
            treesize ++; 
        }else if(value< node->data){
            insert(node->left,value);
        }else if(value > node->data){
            insert(node->right,value);
        }
    }
    bool contains(Node* node, T value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void print(Node* node) const {
        if (node != nullptr) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
public:
    BinarySearchTree() : root(nullptr), treesize(0) {}
    ~BinarySearchTree(){
        clear(root);
    }
void insert(T value){
    insert(root,value);
}
bool contains(T value) const{
    return contains(root, value);
}

int size() const { 
    return treesize;
}
void print() const {
    print(root);
    cout<<endl;
}
};

int main(){
    BinarySearchTree<int> bst;
    int Q;
    cin>>Q;
    for(int i = 0; i<Q;i++){
        string command;
        cin>>command;
        if(command == "insert"){
            int value;
            cin>>value;
            bst.insert(value);
        }else if(command == "contains"){
            int value;
            cin>>value;
            if(bst.contains(value)){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else if(command == "size"){
            cout<<bst.size()<<endl;
        }else if(command == "print"){
            bst.print();
        }
    }
    return 0;
}


#include <iostream>

template <typename T>
struct Node
{
    T val;
    Node<T>* parrent;
    Node<T>* left;
    Node<T>* right;

    Node(){
        val = 0;
        parrent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    Node(T val){
        this->val = val;
        parrent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node<T>*& node){
        os << node->val;
        return os;
    }
};

template <typename T>
class BinarySearchTree{
    Node<T>* root;
    int size;

    void print(Node<T>*& node){
        if(node->left != nullptr) print(node->left);
        std::cout << node->val << " ";
        if(node->right != nullptr) print(node->right);
    }

    public:

    BinarySearchTree(){
        root = nullptr;
        size = 0;
    }

    void insert(T val){
        if(root == nullptr) root = new Node<T>(val);
        else{
            Node<T>* temp = root;
            Node<T>* parrent = nullptr;
            while(temp != nullptr){
                parrent = temp;
                if(val < temp->val) temp = temp->left;
                else if(val > temp->val) temp = temp->right;
                else return;
            }
            temp = new Node<T>();
            temp->parrent = parrent;
            temp->val = val;
            if(parrent != nullptr){
                if(val < parrent->val) parrent->left = temp;
                else parrent->right = temp;
            }
        }
        
        
        size++;
    }

    bool contains(T val){
        Node<T>* temp = root;
        while(temp != nullptr){
            if(val < temp->val) temp = temp->left;
            else if(val > temp->val) temp = temp->right;
            else return true;
        }
        return false;
    }


    int getSize() {return size;}

    void print(){
        if(root != nullptr) print(root);
        std::cout << std::endl;
    }


};

int main(){
    BinarySearchTree<int> tree;
    int Q;
    std::string type;
    std::cin >> Q;
    int argument;
    for(int i = 0; i < Q; i++){
        std::cin >> type;
        if(type == "insert"){
            std::cin >> argument;
            tree.insert(argument);
        }
        else if(type == "contains"){
            std::cin >> argument;
            bool contains = tree.contains(argument);
            std::cout << (contains ? "Yes" : "No") << std::endl;
        }
        else if(type == "size") std::cout << tree.getSize() << std::endl;
        else tree.print();
    }
    return 0;
}
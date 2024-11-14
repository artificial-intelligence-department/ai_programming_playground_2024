#include <iostream>

template <typename T>
struct Node
{
    T val;
    T subnodesSum;
    Node<T>* parrent;
    Node<T>* left;
    Node<T>* right;

    Node(){
        val = 0;
        subnodesSum = 0;
        parrent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    Node(T val){
        this->val = val;
        subnodesSum = 0;
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

    void mirrorNode(Node<T>*& node){
        if(node->left != nullptr) mirrorNode(node->left);
        if(node->right != nullptr) mirrorNode(node->right);
        std::swap(node->left, node->right);
    }

    void printSubnodesSums(Node<T>*& node){
        if(node->left != nullptr) printSubnodesSums(node->left);
        if(node->right != nullptr) printSubnodesSums(node->right);
        std::cout << "Sum of subnodes for node of value " << node->val << " = " << node->subnodesSum << std::endl;
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
                if(parrent != nullptr)parrent->subnodesSum += val;
                parrent = temp;
                if(val < temp->val) temp = temp->left;
                else if(val > temp->val) temp = temp->right;
                else return;
            }
            temp = new Node<T>();
            temp->parrent = parrent;
            temp->val = val;
            if(parrent != nullptr){
                parrent->subnodesSum += val;
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

    void printSubnodesSums(){
        if(root != nullptr) printSubnodesSums(root);
        std::cout << std::endl;
    }

    void mirrorTree(){
        mirrorNode(root);
    }

};

int main(){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(3);
    tree.insert(6);
    tree.insert(11);
    tree.insert(15);
    tree.print();
    std::cout << "Mirrored tree:\n";
    tree.mirrorTree();
    tree.print();
    tree.mirrorTree();
    std::cout << "Sums of subnodes of a tree:\n";
    tree.printSubnodesSums();
}
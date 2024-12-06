#include <iostream>
#include <string>

template <typename T>
class TreeNode {
public:
 T data;
 TreeNode* left;
 TreeNode* right;

 TreeNode(T value): data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
public:
 BinarySearchTree() : root(nullptr) {}

 void insert(T value) {
  root = insert(root, value);
 }

 void print() const {
  print(root);
  std::cout << std::endl;
 }

 bool contains(T value) const {
  return contains(root, value);
 }

 int size() const {
  return size(root);
 }

private:
 TreeNode<T>* root;

 TreeNode<T>* insert(TreeNode<T>* node, T value) {
  if (node == nullptr) {
   return new TreeNode<T>(value);
  }
  if (value < node->data) {
   node->left = insert(node->left, value);
  } else if (value > node->data) {
   node->right = insert(node->right, value);
  }
  return node;
 }

 bool contains(TreeNode<T>* node, T value) const {
  if (node == nullptr) return false;
  if (value == node->data) return true;
  if (value < node->data) return contains(node->left, value);
  return contains(node->right, value);
 }

 void print(TreeNode<T>* node) const {
  if (node != nullptr) {
   print(node->left);
   std::cout << node->data << " ";
   print(node->right);
  }
 }

 int size(TreeNode<T>* node) const {
  if (node == nullptr) return 0;
  return 1 + size(node->left) + size(node->right);
 }
};

int main() {
 BinarySearchTree<int> myTree;
 int N;
 std::cin >> N;

 for (int i = 0; i < N; ++i) {
  std::string operation;
  std::cin >> operation;

  if (operation == "insert") {
   int value;
   std::cin >> value;
   myTree.insert(value);
  } else if (operation == "print") {
   myTree.print();
  } else if (operation == "contains") {
   int value;
   std::cin >> value;
   std::cout << (myTree.contains(value) ? "Yes" : "No") << std::endl;
  } else if (operation == "size") {
   std::cout << myTree.size() << std::endl;
  }
 }

 return 0;
}

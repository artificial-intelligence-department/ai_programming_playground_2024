#include <iostream>

template <typename T>
struct TreeNode
{
	T data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T> *root;

	TreeNode<T> *insertNode(TreeNode<T> *node, T value)
	{
		if (node == nullptr)
			return new TreeNode<T>(value);

		if (value < node->data)
		{
			node->left = insertNode(node->left, value);
		}
		else if (value > node->data)
		{
			node->right = insertNode(node->right, value);
		}
		return node;
	}

	bool contains(TreeNode<T> *node, T value)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value == node->data)
		{
			return true;
		}
		else if (value < node->data)
		{
			return contains(node->left, value);
		}
		else
		{
			return contains(node->right, value);
		}
	}

	int size(TreeNode<T> *node)
	{
		if (node != nullptr)
		{
			int sum = 1;
			sum += size(node->left);
			sum += size(node->right);

			return sum;
		}
		else
		{
			return 0;
		}
	}

	void print(TreeNode<T> *node)
	{
		if (node != nullptr)
		{
			print(node->left);
			std::cout << node->data << " ";
			print(node->right);
		}
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(T value)
	{
		root = insertNode(root, value);
	}

	bool contains(int value)
	{
		return contains(root, value);
	}

	void size()
	{
		std::cout << size(root) << std::endl;
	}

	void print()
	{
		print(root);
	}
};

int main()
{

	BinarySearchTree<int> tree;

	int Q;
	std::string option;
	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		std::cin >> option;
		if (option == "insert")
		{
			int num;
			std::cin >> num;
			tree.insert(num);
		}
		else if (option == "contains")
		{
			int num;
			std::cin >> num;
			if (tree.contains(num))
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
			}
		}
		else if (option == "print")
		{
			tree.print();
			std::cout << std::endl;
		}
		else if (option == "size")
		{
			tree.size();
		}
		else
		{
			std::cout << "Wrong option";
		}
	}

	return 0;
}

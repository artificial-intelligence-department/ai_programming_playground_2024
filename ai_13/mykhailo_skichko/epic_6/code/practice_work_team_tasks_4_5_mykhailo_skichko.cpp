#include <iostream>
#include <queue>

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

	TreeNode<T> *create_mirror_flip(TreeNode<T> *node)
	{
		if (node == nullptr)
			return nullptr;

		TreeNode<T> *mirrored = new TreeNode<T>(node->data);
		mirrored->left = create_mirror_flip(node->right);
		mirrored->right = create_mirror_flip(node->left);

		return mirrored;
	}

	T subtreeSum(TreeNode<T> *node)
	{
		if (node == nullptr)
			return 0;
		if (node->left == nullptr && node->right == nullptr)
			return node->data;

		T leftSum = subtreeSum(node->left);
		T rightSum = subtreeSum(node->right);
		node->data = leftSum + rightSum;
		return node->data;
	}

	void printPyramid(TreeNode<T> *root)
	{
		if (root == nullptr)
		{
			std::cout << "Tree is empty." << std::endl;
			return;
		}

		std::queue<TreeNode<T> *> level_q;
		level_q.push(root);

		while (!level_q.empty())
		{
			int levelSize = level_q.size();

			for (int i = 0; i < levelSize; ++i)
			{
				TreeNode<T> *node = level_q.front();
				level_q.pop();

				if (node)
				{
					std::cout << node->data << " ";
					level_q.push(node->left);
					level_q.push(node->right);
				}
			}
			std::cout << std::endl;
		}
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(T value)
	{
		root = insertNode(root, value);
	}

	BinarySearchTree<T> mirror()
	{
		BinarySearchTree<T> mirroredTree;
		mirroredTree.root = create_mirror_flip(root);
		return mirroredTree;
	}

	void calculateSubtreeSums()
	{
		subtreeSum(root);
	}

	void print()
	{
		printPyramid(root);
		std::cout << std::endl;
	}
};

int main()
{
	BinarySearchTree<int> bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);
    bst.insert(9);

	std::cout << "Initial tree: \n";
	bst.print();

	BinarySearchTree<int> mirroredTree = bst.mirror();
	std::cout << "Mirrored tree: \n";
	mirroredTree.print();

	bst.calculateSubtreeSums();
	std::cout << "After tree summation: \n";
	bst.print();

	return 0;
}

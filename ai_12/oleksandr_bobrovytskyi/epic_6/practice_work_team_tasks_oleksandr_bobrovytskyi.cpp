#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *next;

	Node(int value) : data(value), next(nullptr) {}
};

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void deleteList(Node *&head)
{
	Node *current = head;
	while (current != nullptr)
	{
		Node *next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

void deleteTree(TreeNode *&root)
{
	if (root == nullptr)
	{
		return;
	}

	deleteTree(root->left);
	deleteTree(root->right);

	delete root;
	root = nullptr;
}

Node *createList(vector<int> v)
{
	Node *head = new Node(v[0]);
	Node *current = head;

	for (int i = 1; i < v.size(); i++)
	{
		current->next = new Node(v[i]);
		current = current->next;
	}

	return head;
}

Node *reverse(Node *head)
{
	Node *previous = nullptr;
	Node *next = nullptr;
	Node *current = head;

	while (current != nullptr)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	return previous;
}

void printList(Node *head)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

bool compare(Node *h1, Node *h2)
{
	Node *temp1 = h1;
	Node *temp2 = h2;
	while (temp1 != nullptr && temp2 != nullptr)
	{
		if ((temp1->data != temp2->data) || (temp1 == nullptr && temp2 != nullptr) || (temp2 == nullptr && temp1 != nullptr))
		{
			return false;
		}

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return true;
}

Node *add(Node *n1, Node *n2)
{
	Node *resultHead = nullptr;
	Node *resultTail = nullptr;
	Node *temp1 = n1;
	Node *temp2 = n2;
	int num = 0, carry = 0, sum = 0;

	while (temp1 != nullptr || temp2 != nullptr || carry != 0)
	{
		sum = carry;
		if (temp1 != nullptr)
		{
			sum += temp1->data;
			temp1 = temp1->next;
		}

		if (temp2 != nullptr)
		{
			sum += temp2->data;
			temp2 = temp2->next;
		}

		carry = sum / 10;

		num = sum % 10;

		Node *newNode = new Node(num);

		if (resultHead == nullptr)
		{
			resultHead = newNode;
		}
		else
		{
			resultTail->next = newNode;
		}
		resultTail = newNode;
	}

	return resultHead;
}

TreeNode *create_mirror_flip(TreeNode *root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	TreeNode *mirrored = new TreeNode(root->data);

	mirrored->left = create_mirror_flip(root->right);
	mirrored->right = create_mirror_flip(root->left);

	return mirrored;
}

void inorderTraversal(TreeNode *root)
{
	if (root == nullptr)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

void tree_sum(TreeNode *root)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> NodeStack;
	TreeNode *lastVisited = nullptr;
	TreeNode *current = root;
	int sum;

	while (!NodeStack.empty() || current != nullptr)
	{
		while (current != nullptr)
		{
			NodeStack.push(current);
			current = current->left;
		}

		TreeNode *topNode = NodeStack.top();

		if (topNode->right == nullptr || lastVisited == topNode->right)
		{
			NodeStack.pop();

			if (topNode->left != nullptr || topNode->right != nullptr)
			{
				sum = 0;
				sum += (topNode->left != nullptr) ? topNode->left->data : 0;
				sum += (topNode->right != nullptr) ? topNode->right->data : 0;
				topNode->data = sum;
			}

			lastVisited = topNode;
		}
		else
		{
			current = topNode->right;
		}
	}
}

int main()
{
	int n = 6;
	vector<int> values1 = {4, 6, 9};
	vector<int> values2 = {3, 2, 5};

	Node *head = createList(values1);

	cout << "Original list: ";
	printList(head);

	head = reverse(head);

	cout << "\nReversed list: ";
	printList(head);

	Node *head2 = createList(values2);

	cout << "\nResult of the comparison: " << compare(head, head2) << endl;

	Node *additionHead = add(head, head2);

	printList(additionHead);

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	cout << "\nInorder traversal of the original tree: " << endl;
	inorderTraversal(root);

	TreeNode *mirrored = create_mirror_flip(root);

	cout << "\nInorder traversal after mirroring: " << endl;
	inorderTraversal(mirrored);

	tree_sum(root);

	cout << "\nInorder traversal after finding sum of nodes: " << endl;
	inorderTraversal(root);

	deleteList(head);
	deleteList(head2);
	deleteList(additionHead);
	deleteTree(mirrored);
	deleteTree(root);

	return 0;
}
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node *next;

	Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
	Node<T> *head;

public:
	LinkedList() : head(nullptr) {}

	void insertAtBeginning(T value)
	{
		Node<T> *newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	void insertAtEnd(T value)
	{
		Node<T> *newNode = new Node<T>(value);

		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		Node<T> *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void insertAtPosition(T value, int position)
	{
		if (position < 1)
		{
			std::cout << "Position should be >= 1." << std::endl;
			return;
		}

		if (position == 1)
		{
			insertAtBeginning(value);
			return;
		}

		Node<T> *newNode = new Node<T>(value);
		Node<T> *temp = head;
		for (int i = 1; (i < position - 1) && (temp != nullptr); ++i)
		{
			temp = temp->next;
		}

		if (temp == nullptr)
		{
			std::cout << "Position out of range." << std::endl;
			delete newNode;
			return;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}

	void deleteFromBeginning()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty." << std::endl;
			return;
		}

		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	void deleteFromEnd()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty." << std::endl;
			return;
		}

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node<T> *temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = nullptr;
	}

	void deleteFromPosition(int position)
	{
		if (position < 1)
		{
			std::cout << "Position should be >= 1." << std::endl;
			return;
		}

		if (position == 1)
		{
			deleteFromBeginning();
			return;
		}

		Node<T> *temp = head;
		for (int i = 1; (i < position - 1) && (temp != nullptr); ++i)
		{
			temp = temp->next;
		}

		if (temp == nullptr || temp->next == nullptr)
		{
			std::cout << "Position out of range." << std::endl;
			return;
		}

		Node<T> *nodeToDelete = temp->next;
		temp->next = temp->next->next;
		delete nodeToDelete;
	}

	void reverse()
	{
		Node<T> *prev = nullptr;
		Node<T> *current = head;
		Node<T> *next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	bool compare(const LinkedList<T> &otherList)
	{
		Node<T> *temp1 = head;
		Node<T> *temp2 = otherList.head;

		while (temp1 != nullptr && temp2 != nullptr)
		{
			if (temp1->data != temp2->data)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return temp1 == nullptr && temp2 == nullptr;
	}

	LinkedList<T> add(const LinkedList<T> &otherList)
	{
		Node<T> *node1 = head;
		Node<T> *node2 = otherList.head;

		LinkedList<T> result;
		Node<T> *current = nullptr;

		int carry = 0;
		T sum;

		while (node1 != nullptr || node2 != nullptr || carry != 0)
		{
			sum = carry;

			if (node1 != nullptr)
			{
				sum += node1->data;
				node1 = node1->next;
			}

			if (node2 != nullptr)
			{
				sum += node2->data;
				node2 = node2->next;
			}

			carry = sum / 10;

			Node<T> *newNode = new Node<T>(sum % 10);

			if (current == nullptr)
			{
				result.head = newNode;
				current = result.head;
			}
			else
			{
				current->next = newNode;
				current = current->next;
			}
		}

		return result;
	}

	void display()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty." << std::endl;
			return;
		}

		Node<T> *temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << " -> ";
			temp = temp->next;
		}
		std::cout << "NULL" << std::endl;
	}
};

int main()
{
	LinkedList<int> list1;
	list1.insertAtEnd(5);
	list1.insertAtEnd(6);
	list1.insertAtBeginning(1);
	list1.insertAtBeginning(2);
	list1.insertAtPosition(4, 3);
	list1.insertAtPosition(3, 4);

	std::cout << "List 1: ";
	list1.display();

	LinkedList<int> list2;
	list2.insertAtEnd(5);
	list2.insertAtEnd(6);
	list2.insertAtBeginning(2);
	list2.insertAtBeginning(1);
	list2.insertAtPosition(4, 3);
	list2.insertAtPosition(3, 4);

	std::cout << "List 2: ";
	list2.display();

	std::cout << "Are List 1 and List 2 equal? -- ";
	std::cout << (list1.compare(list2) ? "Equal" : "Not Equal") << std::endl;

	std::cout << "Reversed List 1: ";
	list1.reverse();
	list1.display();

	LinkedList<int> num1;
	num1.insertAtEnd(9);
	num1.insertAtEnd(7);
	num1.insertAtEnd(3);

	LinkedList<int> num2;
	num2.insertAtEnd(6);
	num2.insertAtEnd(8);

	std::cout << "Number 1: ";
	num1.display();

	std::cout << "Number 2: ";
	num2.display();

	LinkedList<int> result = num1.add(num2);
	std::cout << "Sum: ";
	result.display();

	return 0;
}

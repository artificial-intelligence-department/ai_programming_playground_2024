#include <iostream>
#include <vector>

template <class T>
struct Node
{
	T data;
	Node *next;
	Node *prev;

	Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <class T>
class DoublyLinkedList
{
	Node<T> *head;
	Node<T> *tail;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	void insert(int index, std::vector<T> &array)
	{
		if (index == 0)
		{
			for (int i = array.size() - 1; i >= 0; --i)
			{
				Node<T> *newNode = new Node<T>(array[i]);
				newNode->next = head;
				if (head != nullptr)
					head->prev = newNode;
				head = newNode;
				if (tail == nullptr)
					tail = newNode; // update tail if list was empty
			}
		}
		else
		{
			Node<T> *temp = head;
			int position = 0;
			while (temp != nullptr && position < index - 1)
			{
				temp = temp->next;
				position++;
			}
			Node<T> *lastNode = temp->next;
			for (const T &elm : array)
			{
				Node<T> *newNode = new Node<T>(elm);
				temp->next = newNode;
				newNode->prev = temp;
				temp = newNode;
			}
			temp->next = lastNode;
			if (lastNode != nullptr)
				lastNode->prev = temp;
			if (tail == temp->next)
				tail = temp; // Update tail if necessary.
		}
	}

	void erase(int index, int n)
	{
		if (index > 0)
		{
			int position = 0;
			Node<T> *firstNode = head;
			while (firstNode != nullptr && position != index - 1)
			{
				firstNode = firstNode->next;
				position++;
			}

			Node<T> *temp = firstNode;
			for (int i = 0; i < n && temp->next != nullptr; i++)
			{
				temp = temp->next;
			}

			Node<T> *lastNode = temp->next;
			firstNode->next = lastNode;

			if (lastNode != nullptr)
				lastNode->prev = firstNode;
			temp = firstNode->next;

			while (temp != lastNode)
			{
				Node<T> *nodeToDelete = temp;
				temp = temp->next;
				delete nodeToDelete;
			}
		}
		else
		{
			for (int i = 0; i < n && head != nullptr; i++)
			{
				Node<T> *nodeToDelete = head;
				head = head->next;
				delete nodeToDelete;
			}
			if (head != nullptr)
				head->prev = nullptr;
		}
	}

	void size()
	{
		int count = 0;
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		std::cout << count << std::endl;
	}

	void get(int index)
	{
		int start = 0;
		Node<T> *temp = head;
		while (temp != nullptr && start != index)
		{
			temp = temp->next;
			start++;
		}
		if (temp != nullptr)
			std::cout << temp->data << std::endl;
		else
			std::cout << "Index out of bounds" << std::endl;
	}

	void set(int index, T value)
	{
		int start = 0;
		Node<T> *temp = head;
		while (temp != nullptr && start != index)
		{
			temp = temp->next;
			start++;
		}
		if (temp != nullptr)
			temp->data = value;
		else
			std::cout << "Index out of bounds" << std::endl;
	}

	void print()
	{
		Node<T> *temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};

int main()
{
	DoublyLinkedList<int> list;
	std::string option;
	int Q;
	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		std::cin >> option;
		if (option == "insert")
		{
			int index, size;
			std::cin >> index >> size;
			std::vector<int> arr(size);
			for (int j = 0; j < size; j++)
			{
				std::cin >> arr[j];
			}
			list.insert(index, arr);
		}
		else if (option == "erase")
		{
			int index, n;
			std::cin >> index >> n;
			list.erase(index, n);
		}
		else if (option == "size")
		{
			list.size();
		}
		else if (option == "get")
		{
			int index;
			std::cin >> index;
			list.get(index);
		}
		else if (option == "set")
		{
			int index, a;
			std::cin >> index >> a;
			list.set(index, a);
		}
		else if (option == "print")
		{
			list.print();
		}
		else
		{
			std::cout << "Wrong option.";
		}
	}
	return 0;
}

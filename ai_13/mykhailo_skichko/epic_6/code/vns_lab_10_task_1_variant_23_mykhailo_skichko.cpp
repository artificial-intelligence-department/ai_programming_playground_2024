#include <iostream>
#include <fstream>
#include <cstring>

struct Node
{
	char *key;
	Node *next;
	Node *prev;

	Node(const char *value)
	{
		key = new char[strlen(value) + 1];
		strcpy(key, value);
		next = nullptr;
		prev = nullptr;
	}
};

class DoublyLinkedList
{
private:
	Node *head;
	Node *tail;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	~DoublyLinkedList()
	{
		clear();
	}

	void create()
	{
		clear();
		std::cout << "List created.\n";
	}

	void insertAtEnd(const char *key)
	{
		Node *newNode = new Node(key);
		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		std::cout << "Element \"" << key << "\" added.\n";
	}

	void insertAtBeginning(const char *key)
	{
		Node *newNode = new Node(key);
		if (!head)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		std::cout << "Element \"" << key << "\" added at the beginning.\n";
	}

	void insertAtPosition(const char *key, int position)
	{
		if (position < 1)
		{
			std::cout << "Position should be >= 1.\n";
			return;
		}
		if (position == 1)
		{
			insertAtBeginning(key);
			return;
		}

		Node *newNode = new Node(key);
		Node *temp = head;

		for (int i = 1; (i < position - 1) && (temp != nullptr); i++)
		{
			temp = temp->next;
		}

		if (temp == nullptr)
		{
			std::cout << "Position greater than the number of nodes.\n";
			delete newNode;
			return;
		}

		newNode->next = temp->next;
		newNode->prev = temp;

		if (temp->next)
		{
			temp->next->prev = newNode;
		}
		temp->next = newNode;

		if (newNode->next == nullptr)
		{
			tail = newNode;
		}

		std::cout << "Element \"" << key << "\" added at position " << position << ".\n";
	}

	void deleteByKey(const char *key)
	{
		Node *current = head;
		while (current)
		{
			if (strcmp(current->key, key) == 0)
			{
				if (current->prev)
				{
					current->prev->next = current->next;
				}
				else
				{
					head = current->next;
				}

				if (current->next)
				{
					current->next->prev = current->prev;
				}
				else
				{
					tail = current->prev;
				}

				delete current;
				std::cout << "Element \"" << key << "\" deleted.\n";
				return;
			}
			current = current->next;
		}
		std::cout << "Element \"" << key << "\" not found.\n";
	}

	void deleteAtBeginning()
	{
		if (head == nullptr)
		{
			std::cout << "The list is already empty.\n";
			return;
		}
		Node *temp = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete temp;
		std::cout << "First element deleted.\n";
	}

	void deleteAtEnd()
	{
		if (tail == nullptr)
		{
			std::cout << "The list is already empty.\n";
			return;
		}
		Node *temp = tail;
		tail = tail->prev;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete temp;
		std::cout << "Last element deleted.\n";
	}

	void printListForward()
	{
		if (head == nullptr)
		{
			std::cout << "The list is empty.\n";
			return;
		}
		Node *temp = head;
		std::cout << "Forward List: ";
		while (temp != nullptr)
		{
			std::cout << temp->key << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void saveToFile(const char *filename) const
	{
		std::ofstream file(filename);
		if (!file)
		{
			std::cerr << "Error opening file for writing.\n";
			return;
		}
		Node *temp = head;
		while (temp != nullptr)
		{
			file << temp->key << std::endl;
			temp = temp->next;
		}
		file.close();
		std::cout << "List saved to file \"" << filename << "\".\n";
	}

	void restoreFromFile(const char *filename)
	{
		clear();
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "Error opening file for reading.\n";
			return;
		}
		char key[256];
		while (file.getline(key, 256))
		{
			insertAtEnd(key);
		}
		file.close();
		std::cout << "List restored from file \"" << filename << "\".\n";
	}

	void clear()
	{
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
		std::cout << "The list is cleared.\n";
	}
};

int main()
{
	DoublyLinkedList list;
	const char *filename = "DLL.txt";

	list.create();
	list.insertAtEnd("one");
	list.insertAtEnd("two");
	list.insertAtBeginning("zero");
	list.insertAtBeginning("four");
	list.insertAtPosition("five", 2);

	std::cout << "\nAfter Insertions:\n";
	list.printListForward();
	std::cout << std::endl;

	list.deleteAtBeginning();
	list.deleteAtEnd();
	list.deleteByKey("five");

	std::cout << "\nAfter Deletions:\n";
	list.printListForward();
	std::cout << std::endl;

	list.saveToFile(filename);
	list.clear();
	list.printListForward();

	std::cout << std::endl;
	list.restoreFromFile(filename);
	list.printListForward();
	std::cout << std::endl;

	return 0;
}

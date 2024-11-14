#include <iostream>
#include <fstream>
#include <vector>

struct Node
{
    int val;
    Node *next;

    Node()
    {
        next = nullptr;
    }

    Node(int val, Node *node = nullptr)
    {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;
    int size;
    std::string fileName;

    Node *&reverse(Node *&node)
    {
        if (node->next == nullptr)
        {
            head = node;
            return node;
        }
        reverse(node->next)->next = node;
        return node;
    }

public:
    LinkedList()
    {
        size = 0;
        head = nullptr;
        fileName = "";
    };

    LinkedList(int val)
    {
        head = new Node(val);
        size = 1;
        fileName = "";
    }

    void const insert(int i, std::vector<int> &vec)
    {
        Node *temp = head;
        int index = 1;
        int const SIZE = vec.size();
        if (i == 0 || size == 0)
        {
            Node *newHead = new Node(vec[0]);
            temp = newHead;
            for (int i = 1; i < SIZE; i++)
            {
                temp->next = new Node(vec[i]);
                temp = temp->next;
            }
            temp->next = head;
            head = newHead;
        }
        else
        {
            while (temp != nullptr)
            {
                if (index == i)
                {
                    Node *next = temp->next;
                    temp->next = new Node(vec[0]);
                    temp = temp->next;
                    for (int i = 1; i < SIZE; i++)
                    {
                        temp->next = new Node(vec[i]);
                        temp = temp->next;
                    }
                    temp->next = next;
                    break;
                }
                temp = temp->next;
                index++;
            }
        }
        size += vec.size();
    }

    void deleteElems(int i, int size = -1)
    {
        size = i + size > this->size ? this->size - i : size;
        this->size -= size;
        if (size == -1)
        {
            i = 0;
            size = this->size;
        }
        Node *temp = head;
        Node *prev;
        if (this->size == 0)
            return;
        int index = 1;
        if (i == 0)
        {
            while (size && temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
                size--;
            }
            head = temp;
        }
        else
        {
            while (index != i)
            {
                temp = temp->next;
                index++;
            }
            Node *cHead = temp;
            temp = temp->next;
            while (size && temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
                size--;
            }
            cHead->next = temp;
        }
    }

    void const saveToFile(const std::string &fileName)
    {
        this->fileName = fileName;
        std::ofstream file(fileName, std::ofstream::out | std::ofstream::binary);
        if (file)
        {
            file.write(reinterpret_cast<char *>(&size), sizeof(size));
            Node *temp = head;
            while (temp != nullptr)
            {
                file.write(reinterpret_cast<char *>(&temp->val), sizeof(temp->val));
                temp = temp->next;
            }
            deleteElems(0);
        }

        file.close();
    }

    void const getFromFile(const std::string &fName = "")
    {
        if (fName != "")
            fileName = fName;
        std::ifstream file(fileName, std::ifstream::in | std::ifstream::binary);
        deleteElems(0);
        if (file)
        {
            file.read(reinterpret_cast<char *>(&size), sizeof(size));
            if (size != 0)
            {
                head = new Node();
                file.read(reinterpret_cast<char *>(&head->val), sizeof(head->val));
                Node *temp = head;
                for (int i = 1; i < size; i++)
                {
                    temp->next = new Node();
                    file.read(reinterpret_cast<char *>(&temp->next->val), sizeof(temp->next->val));
                    temp = temp->next;
                }
            }
        }
        file.close();
    }

    void const show()
    {
        if (size == 0)
        {
            std::cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->val << "  ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void reverse()
    {
        Node *temp = head;
        reverse(head);
        temp->next = nullptr;
    }

    friend LinkedList operator+(const LinkedList &list1, const LinkedList &list2)
    {
        std::vector<int> elems;
        Node *temp = list1.head;
        if (temp != nullptr)
        {
            elems.push_back(temp->val);
            temp = temp->next;
            while (temp != nullptr)
            {
                if (elems[elems.size() - 1] < temp->val)
                {
                    elems.push_back(temp->val);
                }
                else
                {
                    for (int i = 0; i < elems.size(); i++)
                    {
                        if (temp->val <= elems[i])
                        {
                            elems.insert(elems.begin() + i, temp->val);
                            break;
                        }
                    }
                }
                temp = temp->next;
            }
        }
        temp = list2.head;
        while (temp->next != nullptr)
        {
            if (elems[elems.size() - 1] < temp->val)
            {
                elems.push_back(temp->val);
            }
            else
            {
                for (int i = 0; i < elems.size(); i++)
                {
                    if (temp->val <= elems[i])
                    {
                        elems.insert(elems.begin() + i, temp->val);
                        break;
                    }
                }
            }
            temp = temp->next;
        }
        LinkedList list;
        list.insert(0, elems);
        return list;
    }

    friend bool operator==(const LinkedList &list1, const LinkedList &list2)
    {
        Node *temp1 = list1.head;
        Node *temp2 = list2.head;
        while (temp1->next != nullptr && temp2->next != nullptr)
        {
            if (temp1->val != temp2->val)return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1->next != nullptr && temp2->next == nullptr || temp2->next != nullptr && temp1->next == nullptr)
            return false;
        return true;
    }

    ~LinkedList()
    {
        deleteElems(0);
    }
};

int main()
{
    int size;
    int q;
    std::vector<int> vals;
    LinkedList linkedList;
    std::cout << "Enter number of elements you want to add: ";
    std::cin >> size;
    std::cout << "Enter values: ";
    for (int j = 0; j < size; j++)
    {
        std::cin >> q;
        vals.push_back(q);
    }
    linkedList.insert(0, vals);

    std::cout << "Reversed list:\n";
    linkedList.reverse();
    linkedList.show();
    std::cout << "List is reversed back\n";
    linkedList.reverse();
    LinkedList linkedList2;
    vals.clear();
    std::cout << "Enter number of elements you want to add into second list: ";
    std::cin >> size;
    std::cout << "Enter values: ";
    for (int j = 0; j < size; j++)
    {
        std::cin >> q;
        vals.push_back(q);
    }
    linkedList2.insert(0, vals);
    std::cout << "List are equal : " << std::boolalpha << (linkedList == linkedList2) << std::endl;

    std::cout << "List1 + List2 =\n";
    LinkedList list = linkedList + linkedList2;
    list.show();
    return 0;
}
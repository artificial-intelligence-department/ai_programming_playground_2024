#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct DCLNode
{
    string data;
    DCLNode *prev;
    DCLNode *next;
};

class DCL
{
private:
    DCLNode DCList;
    DCLNode *last = &DCList;

    /////////////////////////////////////////////////////////////////////////
    DCLNode *push_after(DCLNode &node, string &first)
    {
        DCLNode *node1 = new DCLNode{
            first,
            &node,
            node.next,
        };
        node.next = node1;
        cout << "\nsuccessfully added " << first << " in list\n";
        return node1;
    }
    /////////////////////////////////////////////////////////////////////////
    void delete_element(int k)
    {
        DCLNode *current = this->last;
        int n = k;
        while (n--)
        {
            if (current->prev)
            {
                DCLNode *node = current->prev;
                delete current;
                current = node;
            }
            else
            {
                current->data = "";
                break;
            }
        }
        current->next = nullptr;
        last = current;
        cout << "\ndeleted " << k << " elements from the end\n";
    }

    void delete_element(string &data)
    {
        DCLNode *current = &this->DCList;
        int found = 0;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                found++;
                if (current->prev)
                    current->prev->next = current->next;
                if (current->next)
                    current->next->prev = current->prev;
                DCLNode *next = current->next;
                delete current;
                current = next;
            }
            else
                current = current->next;
        }
        if (this->DCList.next == nullptr)
            this->last = &this->DCList;
        if (found == 0)
            cout << "\ncan`t delete element or element is absent in list\n";
        else
            cout << "\n seccesfully deleted " << found << " element" << (found > 1 ? "s" : "") << "\n";
    }
    /////////////////////////////////////////////////////////////////////////
public:
    DCL(char *first) // delegate its args in push after
    {
        this->DCList = DCLNode{first, nullptr, nullptr};
    }

    DCL(const char *first) // delegate its args in push after
    {
        string el = first;
        this->DCList = DCLNode{el.data(), nullptr, nullptr};
    }

    DCL(string first) // delegate its args in push after
    {
        this->DCList = DCLNode{first, nullptr, nullptr};
    }

    DCL()
    {
        this->DCList = DCLNode{"", nullptr, nullptr};
    }
    /////////////////////////////////////////////////////////////////////////
    DCL &operator+(char *data)
    {
        string el = data;
        DCLNode *last = push_after(*this->last, el);
        this->last = last;
        return *this;
    }

    DCL &operator+(const char *data)
    {
        string el = data;
        DCLNode *last = push_after(*this->last, el);
        this->last = last;
        return *this;
    }

    DCL &operator+(string &data)
    {
        DCLNode *last = push_after(*this->last, data);
        this->last = last;
        return *this;
    }

    DCL &operator+(int data)
    {
        string el = to_string(data);
        DCLNode *last = push_after(*this->last, el);
        this->last = last;
        return *this;
    }
    ////////////////////////////////////////////////////////////////////////
    DCL &operator-(string &data)
    {
        delete_element(data);
        return *this;
    }

    DCL &operator-(char *data)
    {
        string el = data;
        delete_element(el);
        return *this;
    }

    DCL &operator-(const char *data)
    {
        string el = data;
        delete_element(el);
        return *this;
    }

    DCL &operator-(int k)
    {
        delete_element(k);
        return *this;
    }
    ////////////////////////////////////////////////////////////////////////
    template <typename T1, typename T2>
    DCL &addAfter(T1 key, T2 value)
    {
        string t1 = key, t2 = value;
        DCLNode *current = &this->DCList;
        while (current != nullptr)
        {
            if (current->data == t1)
                break;
            else
                current = current->next;
        }
        if (current != nullptr)
            push_after(*current, t2);
        else
            cout << "\nno element in list :/\n";
        return *this;
    }

    DCL &output()
    {
        if (this->DCList.next == nullptr && this->DCList.data == "")
            cout << "\nlist is empty\n";
        else
        {
            cout << "\n Outputing data...\n\n";
            DCLNode current = this->DCList;
            while (current.next != nullptr)
            {
                cout << current.data << " ";
                current = *current.next;
            }
            cout << current.data << "\n\n";
        }
        return *this;
    }

    DCL &save()
    {
        fstream file("DCL.txt", ios::out);
        DCLNode *current = &this->DCList;
        while (current->next != nullptr)
        {
            file << current->data << endl;
            current = current->next;
        }
        cout << "\nsuccessfully saved\n";
        return *this;
    }

    DCL &restore()
    {
        fstream file("DCL.txt", ios::in);
        clearList();
        string line;
        getline(file, line);
        this->DCList.data = line;
        DCLNode *current = &this->DCList;
        while (getline(file, line))
        {
            DCLNode *node1 = new DCLNode{
                line,
                current,
                nullptr,
            };
            current->next = node1;
            current = node1;
        }
        cout << "\nsuccessfully restored\n";
        return *this;
    }

    DCL &clearList()
    {
        DCLNode *current = DCList.next;
        while (current)
        {
            DCLNode *next = current->next;
            delete current;
            current = next;
        }
        this->DCList.data = "";
        this->DCList.next = nullptr;
        cout << "\nsuccessfully cleared\n";
        return *this;
    }
    /////////////////////////////////////////////////////////////////////////
};

int main()
{

    DCL list("data1");
    list + "str1" + "str2" + "str3" + "str4" + "str5";
    list.output().addAfter("str2", "### inserted line 1 ###").output();
    list - 2;
    list.output().save().clearList().output().restore().output().clearList();

    return 0;
}
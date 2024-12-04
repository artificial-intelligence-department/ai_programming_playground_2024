#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class DoublyLinkedListNode
{
    public:
    char* val;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(char value[])
    {
        val=value;
        next=nullptr;
        prev=nullptr;
    }
};

class DoublyLinkedList
{
    DoublyLinkedListNode* head;
    public:
    DoublyLinkedList() {head = nullptr;}
    void print()
    {
        if(head==nullptr)
        {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        DoublyLinkedListNode* current=head;
        while(current!=NULL)
        {
            std::cout << current->val << " ";
            current=current->next;
        }
        std::cout << std::endl;
    }
    void insert_at_end(char value[])
    {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(value);
        if(head==nullptr)
        {
            head=node;
            return;
        }
        else
        {
            DoublyLinkedListNode* current=head;
            while(current->next!=nullptr)
            {
                current=current->next;
            }
            current->next=node;
            node->prev=current;
        }
    }
    void insert(char value[], int pos)
    {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(value);
        if(pos<=1)
        {
            std::cout << "Position is out of bounds." << std::endl;
            delete node;
            return;
        }
        if(pos==1)
        {
            node->next=head;
            if(head!=NULL)
            {
                head->prev=node;
            }
            head=node;
        }
        else
        {
            DoublyLinkedListNode* current=head;
            for(int i=1; i<pos-1 && current!=NULL; i++)
            {
                current=current->next;
            }
            if(current==NULL)
            {
                std::cout << "Position is out of bounds." << std::endl;
                delete node;
            }
            else
            {
                node->prev=current;
                node->next=current->next;
                current->next=node;
                if(node->next!=NULL)
                {
                    node->next->prev=node;
                }
            }
        }
    }
    void deletion(int pos)
    {
        if(head==nullptr)
        {
            std::cout << "The list is empty." << std::endl;
            return;
        }
        else if(pos==1)
        {
            DoublyLinkedListNode* current=head;
            head=head->next;
            if(head!=nullptr)
            {
                head->prev=nullptr;
            }
            delete current;
        }
        else
        {
            DoublyLinkedListNode* current=head;
            for(int i=1; i<pos && current!=nullptr; i++)
            {
                current=current->next;
            }
            if(current==nullptr)
            {
                std::cout << "Position is out of bounds." << std::endl;
                return;
            }
            if(current->next!=nullptr)
            {
                current->next->prev=current->prev;
            }
            if(current->prev!=nullptr)
            {
                current->prev->next=current->next;
            }
            delete current;
        }
    }
    void clear_list()
    {
        DoublyLinkedListNode* current;
        while(head!=nullptr)
        {
            current=head;
            head=head->next;
            delete current;
        }
    }
    void writetofile(const std::string &filename)
    {
        std::ofstream file(filename);
        if(!file)
        {
            std::cerr << "Couldn't open file." << std::endl;
            return;
        }
        DoublyLinkedListNode* current=head;
        while(current)
        {
            file << current->val << " ";
            current=current->next;
        }
        file.close();
    }
    void readfromfile(const std::string &filename)
    {
        std::ifstream file(filename);
        if(!file)
        {
            std::cerr << "Couldn't open file." << std::endl;
            return;
        }
        clear_list();
        std::string value;
        int i = 1;
        while (file >> value)
        {
            char* characters=new char[value.size()+1];
            std::strcpy(characters, value.c_str());
            insert(characters, i);
            i++;
        }
        file.close();
    }
    ~DoublyLinkedList()
    {
        clear_list();
    }
};


int main()
{
    DoublyLinkedList list1;
    list1.insert_at_end("aaaaaaaaaaa");
    list1.insert_at_end("bbbbbbbbbb");
    list1.deletion(2);
    list1.insert_at_end("dsafgijhshkj");
    list1.print();
    std::string filename="the_list.txt";
    list1.writetofile(filename);
    list1.clear_list();
    list1.readfromfile(filename);
    list1.print();
}
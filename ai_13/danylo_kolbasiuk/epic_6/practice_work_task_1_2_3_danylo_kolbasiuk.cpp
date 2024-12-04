#include <iostream>

class DoublyLinkedListNode
{
    public:
    int val;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode(int value)
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
    void insert(int value, int pos)
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
    void print()
    {
        DoublyLinkedListNode* current=head;
        while(current!=NULL)
        {
            std::cout << current->val << " ";
            current=current->next;
        }
        std::cout << std::endl;
    }
    DoublyLinkedList reverse()
    {
        DoublyLinkedList reversal;
        DoublyLinkedListNode* current=head;
        while(current!=nullptr)
        {
            reversal.insert(current->val, 1);
            current=current->next;
        }
        return reversal;
    }
    bool compare(const DoublyLinkedList &list2)
    {
        DoublyLinkedListNode* one=head;
        DoublyLinkedListNode* two=list2.head;
        while(one!=nullptr && two!=nullptr)
        {
            if(one->val!=two->val)
            {
                return false;
            }
            else
            {
                one=one->next;
                two=two->next;
            }
        }
        if(one==nullptr && two==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    DoublyLinkedList add(const DoublyLinkedList &list2)
    {
        
        DoublyLinkedListNode* current1=head;
        DoublyLinkedListNode* current2=list2.head;
        int k=0;
        DoublyLinkedList result;
        while(current1!=nullptr || current2!=nullptr || k!=0)
        {
            int sum=k;
            if(current1!=nullptr)
            {
                sum+=current1->val;
                current1=current1->next;
            }
            if(current2!=nullptr)
            {
                sum+=current2->val;
                current2=current2->next;
            }
            result.insert(sum%10, 1);
            k=sum/10;
        }
        return result.reverse();
    }    
};


int main()
{
    DoublyLinkedList list1;
    DoublyLinkedList list2;
    
    list1.insert(1, 1);
    list1.insert(2, 2);
    list1.insert(3, 3);
    list1.insert(7, 4);
    list1.print();
    list2=list1.reverse();
    list2.print();
    if(list1.compare(list2))
    {
        std::cout << "lists are equal!" << std::endl;
    }
    else
    {
        std::cout << "lists are not equal..." << std::endl;    
    }
    DoublyLinkedList list3=list1.add(list1);
    list3.print();
}
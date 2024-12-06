#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
 
};

class doubleLinkedList
{
    private:
    Node* head;

    public:
    doubleLinkedList() : head(nullptr){}

    void EnterToTheEnd(int data){
        Node* newNode = new Node();
        (*newNode).data = data;
        (*newNode).next = nullptr;
        if (head == nullptr){
            (*newNode).prev = nullptr;
            head = newNode;
            return;
        }

        Node* temp = head;
        while((*temp).next != nullptr){
            temp = (*temp).next;
        }
        (*temp).next = newNode;
        (*newNode).prev = temp;
    }

    void deleteBegin(){
        if(head == nullptr){
            cout<<"Лист наразі пустий"<<endl;
            return;
        }
        Node* temp = head;
        head = (*head).next;
        if(head != nullptr){
            (*head).prev = nullptr;
        }
        delete temp;
    }

    void display(){
        Node* temp = head; 
        while (temp != nullptr){
            cout<<(*temp).data<<" ";
            temp = (*temp).next;
        }
        cout<<endl;
    }
    Node* getHead() const{
    return head;
}
void delList(){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = (*temp).next;
        delete temp;
        temp = next; 
    }
    head = nullptr;
}
void restore(const string& filename){
    ifstream file(filename);
    if(!file){
        cout<<"Файл не вдалось відкрити"<<endl;
    }
    int data;
    while(file >> data){
        EnterToTheEnd(data);
    }
    file.close();
}
};

void copytofile(const string& filename, Node* head){
    ofstream file(filename);
    if(!file){
        cout<<"Не вдалось відкрити файл";
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        file << (*temp).data<<" ";
        temp = (*temp).next;
    }
    file.close();
}

void emptyList(const string& filename, Node* head){
    ofstream file(filename);
    if(!file){
        cout<<"Не вдалось відкрити файл";
        return;
    }
    if(head == nullptr){
        cout<<"Список порожній"<<endl;
    }
    else{Node* temp = head;
    while(temp != nullptr){
        file << (*temp).data<<" ";
        temp = (*temp).next;
    }
  }
    file.close();
}

int main(){
    doubleLinkedList list;
    list.EnterToTheEnd(10);
    list.EnterToTheEnd(20);
    list.EnterToTheEnd(20);
    cout<<"Початковий лист: "<<endl;
    list.display();

    list.deleteBegin();
    cout<<"Після видалення першого елементу: "<<endl;
    list.display();
    
    list.EnterToTheEnd(40);
    cout<<"Після добавлення елементу в кінець: "<<endl;;
    list.display();

string name;
cin>>name;

copytofile(name, list.getHead());

list.delList();
cout<<"Список видалено "<<endl;

string secondname;
cin>>secondname;
emptyList(secondname, list.getHead());

list.restore(name);
cout<<"Відновленний список: "<<endl; 
list.display();

list.delList();
cout<<"Список знову видалено( ";

list.display();
return 0;

}

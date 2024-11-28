#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List{
    private:
    struct Node{
        int data;
        Node* previous;
        Node* next;
    };

    Node* head;
    Node* tail;
    size_t size;

    public:
        List()
            : head(nullptr), tail(nullptr), size(0)
        {}

        void Show() const{
            if (size == 0){
                cout<<"List is empty"<<endl;
                return;
            }
            Node *current = head;
            while(current!=nullptr){
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
        }

        void Clear(){
            while (head!=nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        void PushBack(const int& value){
            if (size==0){
                head = new Node {value, nullptr, nullptr};
                tail=head;
            }
            else{
                tail->next = new Node {value, tail, nullptr};
                tail=tail->next;
            }
            size++;
        }

        void PopFront(){
            if(head == nullptr){
                return;
            }
            Node* temp = head;
            head = head->next;

            if(head!=nullptr){
                head->previous=nullptr;
            }
            delete temp;
        }

        void WriteToFile(const string& filename){
            ofstream outFile(filename);

            if(!outFile){
                cerr<<"error opening file "<<filename<<endl;
                return;
            }
            Node* current = head;
            while (current != nullptr){
                outFile<<current->data<<" ";
                current = current->next;
            }
            outFile.close();
        }

        void ReadFromFile(const string& filename){
            ifstream fromFile(filename);
            if(!fromFile){
                cerr<<"error opening file "<<filename<<endl;
                return exit(1);
            }
            int value;
            while(fromFile>>value){
                PushBack(value);
            }
            fromFile.close();
        }

};

int main(){
    List list;
    list.Show();
    for (int i=0; i<10; i++){
        list.PushBack(i);
    }
    list.Show();
    list.PopFront();
    list.Show();
    list.PushBack(7);
    list.Show();
    list.WriteToFile("string.txt");
    list.Clear();
    list.Show();
    list.ReadFromFile("string.txt");
    list.Show();
    list.Clear();
    return 0;
}
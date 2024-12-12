#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List {
    private:
        struct Node {
            int data;
            Node* previous;
            Node* next;
             };

        Node* head;
        Node* tail;
        size_t size;

    public:
        List() : head(nullptr), tail(nullptr), size(0) {}

        void Show() const {
            if (size == 0) {
                cout << "List is empty" << endl;
                return;
            }
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void Clear() {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        void PushBack(const int& value) {
            if (size == 0) {
                head = new Node {value, nullptr, nullptr};
                tail = head;
            } else {
                tail->next = new Node {value, tail, nullptr};
                tail = tail->next;
            }
            size++;
        }

        void DeleteFirst() {
            if (head == nullptr) {
                return;
            }

            Node* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->previous = nullptr;
            }

            delete temp;
        }

        void WriteToFile(const string& filename){
            ofstream outFile(filename);
            if(!outFile){
                cerr<<"error opening "<<filename<<endl;
                return;
            }

            Node* current = head;
            while(current!=nullptr){
                outFile<<current->data<<" ";
                current = current->next;
            }
            outFile.close();
        }

        Node* ReadFromFile (const string& filename){
            ifstream inFile(filename);
            if(!inFile){
                cerr<<"error opening "<<filename<<endl;
                return nullptr;
            }
            int value;
            while(inFile>>value){
                PushBack(value);
            }
            inFile.close();
            return head;
        }
};

int main(){
    List list;
    list.Show();
    for(int i=0; i<7; i++){
        list.PushBack(i);
    }
    list.Show();
    list.PushBack(1);
    list.Show();
    list.DeleteFirst();
    list.Show();
    list.WriteToFile("list.txt");
    list.Clear();
    list.Show();
    list.ReadFromFile("list.txt");
    list.Show();
    list.Clear();
    return 0;
}
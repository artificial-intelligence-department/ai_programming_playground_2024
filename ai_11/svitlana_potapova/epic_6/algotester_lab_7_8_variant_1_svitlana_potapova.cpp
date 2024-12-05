#include <iostream>
using namespace std;

template <typename T>
class Node{
public: 
    T data;
    Node* prev;
    Node* next;  

    Node(T& value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }  
};

template <typename T>
class DoublyLinkedList{
private:
    Node<T>* head;       
    Node<T>* tail;      
    int list_size; 

public:
    DoublyLinkedList(){
        list_size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insert(int index, int n, T* values);
    void erase(int index, int n);
    int size();
    T get(int index);
    void set(int index, T value);

    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {  
        Node<T>* current = list.head;
    
        while(current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};

template<typename T>
void DoublyLinkedList<T>::insert(int index, int n, T* values){
    Node<T>* current = head;
    Node<T>* prevNode = nullptr;

    for (int i = 0; i < index; i++) {
        prevNode = current;
        current = current->next;
    }

    for (int i = 0; i < n; ++i){
        Node<T>* newNode = new Node<T>(values[i]);

        if(!prevNode){
            newNode->next = head;
            if (head) head->prev = newNode;
            else tail = newNode;
            head = newNode;
        } else{
            newNode->next = current;
            newNode->prev = prevNode;
            
            prevNode->next = newNode;
            if(current) current->prev = newNode;
            else tail = newNode; 
        }
        prevNode = newNode;
    }
    list_size += n;
}

template<typename T>
void DoublyLinkedList<T>::erase(int index, int n){
    Node<T>* current = head;

    for(int i=0; i<index; i++) {
        current = current->next;
    }

    for(int i=0; i<n; i++){
        Node<T>* temp = current;

        if(current->prev){
            current->prev->next = current->next; 
        }
        else head = current->next;

        if(current->next){
            current->next->prev = current->prev;
        }
        else tail = current->prev;

        current = current->next;

        delete temp;
    }
    list_size -= n;
}

template<typename T>
int DoublyLinkedList<T>::size() {
    return list_size;
}

template<typename T>
T DoublyLinkedList<T>::get(int index){
    Node<T>* current = head;

    for(int i=0; i<index; i++) { 
        current = current->next;
    }

    return current->data;
} 

template<typename T>
void DoublyLinkedList<T>:: set(int index, T value){
    Node<T>* current = head;

    for(int i=0; i<index; i++){
        current = current->next;
    }

    current->data = value;
}

int main(){
    DoublyLinkedList<int> list;
    int Q;
    cin >> Q;

    for (int i=0; i<Q; i++){
        string option;
        cin >> option;

        if(option == "insert"){
            int index, N;
            cin >> index >> N;

            int *values = new int[N];
            for(int i=0; i<N; i++){
                cin >> values[i];
            }
            list.insert(index, N, values);

            delete[] values;
        } else if(option == "erase"){
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if(option == "size"){
            cout << list.size() << endl;
        } else if(option == "get"){
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if(option == "set"){
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        } else if(option == "print"){
            cout << list << endl;
        }

    }
}
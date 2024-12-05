#include <iostream>
using namespace std;


template<typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Двозв’язний список
template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size_;

    // Отримання вузла за індексом
    Node<T>* getNode(int index){
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size_(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void insert(int index, int N, T* elements) {
        if (index < 0 || index > size_) return;

        for (int i = 0; i < N; ++i) {
            Node<T>* newNode = new Node<T>(elements[i]);

            if (index == 0) {
                newNode->next = head;
                if (head) head->prev = newNode;
                head = newNode;
                if (!tail) tail = newNode;

            } else if (index == size_) { 
                newNode->prev = tail;
                if (tail) tail->next = newNode;
                tail = newNode;

            } else { 
                Node<T>* current = getNode(index);
                newNode->next = current;  // 1 2 3 4 5 | 1 2 7->3 4 5 (7 connected to 3)
                newNode->prev = current->prev; // 1 2 3 4 5 | 1 2<-7->3 4 5
                current->prev->next = newNode;
                current->prev = newNode;
            }
            ++index;
            ++size_;
        }
    }

    // Видалення n елементів з позиції index
    void erase(int index, int n) {
        if (index < 0 || index >= size_ || n <= 0) return;

        for (int i = 0; i < n && index < size_; ++i) {
            Node<T>* toDelete = getNode(index);

            if (toDelete->prev) toDelete->prev->next = toDelete->next; // 1->2->3 | 1 -> 3
            if (toDelete->next) toDelete->next->prev = toDelete->prev; // 1<-2<-3 | 1 <- 3
            if (toDelete == head) head = toDelete->next;
            if (toDelete == tail) tail = toDelete->prev;

            delete toDelete;
            --size_;
        }
    }

    int size(){
        return size_;
    }

    T get(int index){
        return getNode(index)->data;
    }

    void set(int index, const T& value) {
        getNode(index)->data = value;
    }

    friend ostream& operator<<(ostream& os, const DoublyLinkedList<T>& list) {
        Node<T>* current = list.head;
        while (current) { // while current has next Node
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;
    DoublyLinkedList<int> dll;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int* elements = new int[N];
            for (int i = 0; i < N; ++i) {
                cin >> elements[i];
            }
            dll.insert(index, N, elements);
            delete[] elements;

        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            dll.erase(index, n);

        } else if (command == "size") {
            cout << dll.size() << endl;

        } else if (command == "get") {
            int index;
            cin >> index;
            cout << dll.get(index) << endl;

        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            dll.set(index, value);

        } else if (command == "print") {
            cout << dll << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class List
{
public:

    List();
    ~List();

    void push_back(T data);
    void insert(int index, const std::vector<T>& values);
    void erase(int index, int count);
    T get(int index) const;
    void set(int index, T value);
    int size() const;
    void print() const;

    template <typename U>
    friend ostream& operator<<(ostream& os, const List<U>& list);
    
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };
    int Size;
    Node  *head;
    Node *tail;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::~List()
{
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::push_back(T data)
{
    Node* temp = new Node(data);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    Size++;
}

template <typename T>
void List<T>::insert(int index, const std::vector<T>& values)
{
    if (index < 0 || index > Size) return;

    Node* current = head;
    Node* prev = nullptr;

    for(int i = 0; i < index; i++)
    {
        prev = current;
        current = current->next;
    }

    for(const T& value : values)
    {
        Node* newNode = new Node(value);
        if(prev)
        {
            prev->next = newNode;
            newNode->prev = prev;
        }
        else
        {
            head = newNode;
        }
        newNode->next = current;
        if(current)
        {
            current->prev = newNode;
        }
        else{
            tail = newNode;
        }
        prev = newNode;
        Size++;
    }

}

template <typename T>
void List<T>::erase(int index, int count)
{
    if (index < 0 || index >= Size || count <= 0) return;

    Node* current = head;

    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    for(int i = 0; i < count; i++)
    {
        Node* toDelete = current;
        current = current->next;

        if(toDelete->prev !=nullptr)
        {
            toDelete->prev->next = toDelete->next;
        }
        else
        {
            head = toDelete->next;
        }

        if(toDelete->next != nullptr)
        {
            toDelete->next->prev = toDelete->prev;
        }
        else
        {
            tail = toDelete->prev;
        }

        delete toDelete;
        Size--;
    }
}

template <typename T>
T List<T>::get(int index) const {
    Node* current = head;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <typename T>
void List<T>::set(int index, T value) {
    if (index < 0 || index >= Size) throw out_of_range("Index out of range");

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}


template <typename T>
int List<T>::size() const {
    return Size;
}

template <typename T>
void List<T>::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
ostream& operator<<(ostream& os, const List<T>& list) {
    typename List<T>::Node* current = list.head;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

int main(){
     List<int> list;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            vector<int> elements(N);
            for (int j = 0; j < N; ++j) cin >> elements[j];
            list.insert(index, elements);
        } else if (command == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        } else if (command == "size") {
            cout << list.size() << endl;
        } else if (command == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;
        } else if (command == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        } else if (command == "print") {
            cout << list << endl;
        }
    }

    return 0;
}
   
    

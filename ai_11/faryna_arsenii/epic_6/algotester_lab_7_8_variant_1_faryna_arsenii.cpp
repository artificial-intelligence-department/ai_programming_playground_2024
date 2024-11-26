#include <iostream>

using namespace std;

template< typename T >
class Node {
public:
    T data;
    Node* next;

    Node(T& value) {
        data = value;
        next = nullptr;
    }
};

template< typename T >
class LinkedList {

public:
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    void insert(int index, int listSize, T values[]);
    void erase(int index, int count);
    T get(int index);
    void set(int index, T value);
    int getSize();
    void print();

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {  
        Node<T>* current = list.head;
    
        while(current) {
            os << current->data << " ";
            current = current->next;
        }
        os << std::endl;
        return os;
    }

private:
    Node<T>* head;
    int size;
};

template<class T>
void LinkedList<T>::insert(int index, int listSize, T values[]) {
    if (index < 0 || index > size || listSize <= 0) {
        return;
    }

    // Якщо вставка на початок списку
    if (index == 0) {
        for (int j = listSize - 1; j >= 0; j--) {  // Вставляємо елементи у зворотньому порядку
            Node<T>* newNode = new Node<T>(values[j]);
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
    else {
        Node<T>* current = head;

        // Знайдемо позицію перед вставкою
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        // Тепер вставляємо нові елементи
        for (int j = 0; j < listSize; j++) {
            Node<T>* newNode = new Node<T>(values[j]);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
            size++;
        }
    }
}

template<class T>
void LinkedList<T>::erase(int index, int count) {
    if (index < 0 || index >= size || count <= 0) {
        return;
    }

    // Якщо видаляємо елементи з початку
    if (index == 0) {
        Node<T>* current = head;
        for (int i = 0; i < count; i++) {
            if (current == nullptr) break;
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
            size--;
        }
        head = current; // Оновлюємо head на новий початок
    }
    else {
        Node<T>* current = head;

        // Знайдемо позицію перед елементом, з якого потрібно почати видалення
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        // Видалимо елементи
        for (int j = 0; j < count; j++) {
            if (current->next == nullptr) break; // Перевіряємо, чи є наступний елемент
            Node<T>* nodeToDelete = current->next;
            current->next = current->next->next; // Зв'язуємо поточний вузол з наступним після видаленого
            delete nodeToDelete;
            size--;
        }
    }
}

template<class T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index >= size) {
        return T();
    }

    Node<T>* current = head;

    // find node at index
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

template<class T>
void LinkedList<T>::set(int index, T value) {
    if (index < 0 || index >= size) {
        return;
    }

    Node<T>* current = head;

    // find node at index
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    current->data = value;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* current = head;
    
    while(current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {

    LinkedList<int> list;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string choice;
        cin >> choice;

        if (choice == "insert") {
            int index, N;
            cin >> index >> N;

            int* values = new int[N];
            for (int k = 0; k < N; k++) {
                cin >> values[k];
            }
            list.insert(index, N, values);
            delete[] values;
        }
        else if (choice == "erase") {
            int index, n;
            cin >> index >> n;
            list.erase(index, n);
        }
        else if (choice == "size") {
            cout << list.getSize() << endl;
        }
        else if (choice == "get") {
            int index;
            cin >> index;
            cout << list.get(index) << endl;  
        }
        else if (choice == "set") {
            int index, value;
            cin >> index >> value;
            list.set(index, value);
        }
        else if (choice == "print") {
            list.print();
        }
    }

    return 0;
}
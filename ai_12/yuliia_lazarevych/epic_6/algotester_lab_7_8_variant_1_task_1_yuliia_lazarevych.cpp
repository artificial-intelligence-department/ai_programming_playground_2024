#include <iostream>
using namespace std;

template <typename T> //використовую шаблонний клас для роботи з будь-яким типом (в цьому випадку int)
class DoublyLinkedList {
private:
    struct Node { //власна структура для вузла двозв'язного списку
        T data;       //дані, що зберігаються в вузлі (тип T, який задається під час створення списку)
        Node* prev;   //вказівник на попередній вузол
        Node* next;   //вказівник на наступний вузол
        Node(T val) : data(val), prev(nullptr), next(nullptr) {} //конструктор для ініціалізації вузла
    };

    Node* head; //початок списку
    Node* tail; //кінець списку
    size_t listSize; //розмір списку

    //використовую допоміжну функцію для доступу до вузла за індексом (позначаю const, оскільки вона не змінює стан списку)
    Node* getNodeAt(int index) const {
        Node* current = head;
        while (index-- && current) { //проходимо по списку до індексу
            current = current->next;
        }
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {} //конструктор за замовчуванням

    ~DoublyLinkedList() { //деструктор для звільнення пам'яті
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete; //видалення всіх вузлів списку
        }
    }

    //вставка елементів на задану позицію в список
    void insert(int index, const T* elements, size_t n) {
        if (index < 0 || index > listSize) return; //перевірка на коректність індексу

        Node* prevNode = nullptr;
        if (index > 0) prevNode = getNodeAt(index - 1); //знаходимо попередній вузол, якщо індекс більше 0
        Node* nextNode = prevNode ? prevNode->next : head; //наступний вузол

        for (size_t i = 0; i < n; ++i) {
            Node* newNode = new Node(elements[i]); //створюємо новий вузол
            if (prevNode) prevNode->next = newNode; //зв'язуємо попередній вузол з новим
            newNode->prev = prevNode; //зв'язуємо новий вузол з попереднім

            if (nextNode) nextNode->prev = newNode; //зв'язуємо новий вузол з наступним
            newNode->next = nextNode; //зв'язуємо новий вузол з наступним

            prevNode = newNode;
            if (index == 0 && i == 0) head = newNode; //якщо індекс 0, то новий вузол стає головою списку
            if (index == listSize) tail = newNode; //якщо індекс на кінці, новий вузол стає хвостом списку
        }

        if (prevNode && !nextNode) tail = prevNode; //якщо наступного вузла немає, то змінюємо хвіст
        listSize += n; //оновлюємо розмір списку
    }

    //видалення елементів із списку, починаючи з певного індексу
    void erase(int index, int n) {
        if (index < 0 || index >= listSize || n <= 0) return; //перевірка коректності індексів

        Node* startNode = getNodeAt(index); //знаходимо вузол, з якого почнемо видаляти
        Node* endNode = startNode;
        for (int i = 0; i < n && endNode; ++i) endNode = endNode->next; //знаходимо вузол, де потрібно завершити видалення

        Node* prevNode = startNode->prev; //попередній вузол для початкового
        Node* nextNode = endNode; //наступний вузол для кінцевого

        if (prevNode) prevNode->next = nextNode; //зв'язуємо попередній вузол з наступним
        if (nextNode) nextNode->prev = prevNode; //зв'язуємо наступний вузол з попереднім

        if (!prevNode) head = nextNode; //якщо видаляється перший елемент, то змінюємо голову
        if (!nextNode) tail = prevNode; //якщо видаляється останній елемент, то змінюємо хвіст

        while (startNode != endNode) { //видаляємо вузли по черзі
            Node* toDelete = startNode;
            startNode = startNode->next;
            delete toDelete;
        }

        listSize -= n; //оновлюємо розмір списку
    }

    //функція для отримання розміру списку
    size_t size() const {
        return listSize;
    }

    //функція для отримання значення елемента за індексом
    T get(int index) const {
        Node* node = getNodeAt(index);
        return node ? node->data : T(); //повертаємо значення, якщо вузол існує
    }

    //функція для зміни значення елемента за індексом
    void set(int index, T value) {
        Node* node = getNodeAt(index);
        if (node) node->data = value; //змінюємо значення вузла
    }

    //перевантаження оператора << для виведення списку
    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data; //виводимо значення вузла
            if (current->next) os << " "; //додаємо пробіл між елементами
            current = current->next;
        }
        return os;
    }
};

int main() {
    DoublyLinkedList<int> list; //використовуємо шаблонний клас для int
    int Q;
    cin >> Q;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "insert") {
            int index, N;
            cin >> index >> N;
            int* elements = new int[N];
            for (int i = 0; i < N; ++i) cin >> elements[i];
            list.insert(index, elements, N);
            delete[] elements;
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

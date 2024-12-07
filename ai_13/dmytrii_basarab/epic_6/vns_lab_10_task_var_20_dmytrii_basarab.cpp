#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура вузла списку
struct Node {
    string key;
    Node* prev;
    Node* next;

};

// Функція для створення порожнього списку
Node* create_list() {
    return nullptr; // Порожній список
}

// Функція для друку списку
void print_list(Node* head) {
    if (head == nullptr) {
        cout << "Список порожній." << endl;
        return;
    }

    Node* current = head;
    while (current) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

// Функція для додавання елементів у список
void add_to_list(Node*& head, const string& key, bool to_start) {
    Node* newNode = new Node{key};
    if (head == nullptr) {
        head = newNode;
    } else if (to_start) {
        newNode->next = head;//вказує на той, на який вказувіав head
        head->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head;//ініціалізація tail і з хеду ми доходим до останнього елементу і тоді присвоюєм 
        //адресу останнього елементу tail 
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->prev = tail;
    }
}

// Функція для знищення елемента за ключем
void delete_by_key(Node*& head, const string& key) {
    if (head == nullptr) {
        cout << "Список порожній." << endl;
        return;
    }

    Node* current = head;
    while (current && current->key != key) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Елемент із ключем '" << key << "' не знайдено." << endl;
        return;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {//ми на першому елементі
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Елемент із ключем '" << key << "' видалено." << endl;
}

// Функція для запису списку у файл
void write_to_file(Node* head, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    Node* current = head;
    while (current) {
        file << current->key << endl;
        current = current->next;
    }

    file.close();
    cout << "Список записано у файл '" << filename << "'." << endl;
}

// Функція для відновлення списку з файлу
Node* read_from_file(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    string key;
    while (getline(file, key)) {
        add_to_list(head, key, false);
    }

    file.close();
    cout << "Список відновлено з файлу '" << filename << "'." << endl;
    return head;
}

// Функція для знищення списку
void delete_list(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;//ми зберегли елемент, темп прирівняли до 
        //того на який вказує хед і переставили хед на наступний
        //так ми не втратили отой елемент який тре видалити
    }
    cout << "Список знищено." << endl;
}

// Основна програма
int main() {
    Node* list = create_list();
    int K = 2; // Кількість елементів для додавання на початок і кінець
    string filename = "list.txt";

    // Додавання елементів
    add_to_list(list, "Alpha", false);
    add_to_list(list, "Beta", false);
    add_to_list(list, "Gamma", false);

    cout << "Список після додавання елементів:" << endl;
    print_list(list);

    // Видалення елемента
    delete_by_key(list, "Beta");
    cout << "Список після видалення елемента 'Beta':" << endl;
    print_list(list);

    // Додавання елементів на початок і кінець
    for (int i = 1; i <= K; i++) {
        add_to_list(list, "Start" + to_string(i), true); // На початок
        add_to_list(list, "End" + to_string(i), false);  // В кінець
    }

    cout << "Список після додавання елементів на початок і кінець:" << endl;
    print_list(list);

    // Запис списку у файл
    write_to_file(list, filename);

    // Знищення списку
    delete_list(list);
    print_list(list);

    // Відновлення списку з файлу
    list = read_from_file(filename);
    cout << "Список після відновлення з файлу:" << endl;
    print_list(list);


    delete_list(list);

    return 0;
}

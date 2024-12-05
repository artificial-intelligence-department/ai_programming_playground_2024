#include <iostream>
#include <fstream>
#include <string>

// Структура для вузла двонаправленого списку
struct Node {
    std::string data;
    Node* prev;
    Node* next;

    Node(const std::string& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Клас для роботи з двонаправленим списком
class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    // Деструктор для знищення списку
    ~List() {
        clear();
    }
    // Допоміжні функції
    int Size(){
        int i = 0;
        Node* temp = head;
        while(temp != nullptr){
            i++;
            temp = temp->next;
        }
        return i;
    }
    Node* getNode(int index){
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }
    /////////////////////


    void createList() {
        head = nullptr;
        tail = nullptr;
    }

    void addElement(const std::string& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertEl(const std::string& value, int& index){////////////////////////////////////////////////
        if (index < 0 || index > Size()) return;

        Node* newNode = new Node(value);
        if(index==0){
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        }else if(index == Size()){
            newNode->prev = tail;
            if (tail) tail->next = newNode;
            tail = newNode;        
        }else{
            Node* current = getNode(index);
            newNode->next = current;  // 1 2 3 4 5 | 1 2 7->3 4 5 (7 connected to 3)
            newNode->prev = current->prev; // 1 2 3 4 5 | 1 2<-7->3 4 5
            current->prev->next = newNode;
            current->prev = newNode;
            }
            ++index;    
    }

    // 3. Видалення елемента за номером (індексом)
    void deleteElement(int position) {
        if (!head || position < 0) return;

        Node* temp = getNode(position);

        if (temp) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;

            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;

            delete temp;
        }
    }

    // 4. Друк списку
    void printList() const {
        Node* temp = head;
        if(!temp){
            std::cout << "Список порожній\n";///////////////////////////////////////////////////////
        }
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Запис списку у файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Не вдалося відкрити файл для запису.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            file << temp->data << "\n";
            temp = temp->next;
        }
        file.close();
    }

    void clear() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = nullptr;
    }

    // Відновлення списку з файлу
    void loadFromFile(const std::string& filename) {
        clear();
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Не вдалося відкрити файл для читання.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            addElement(line);
        }
        file.close();
    }
    
};

int main() {
    int k; //кількість ел
    List list;
    int app_index[k], del_index, current_app_index;

    list.createList();
    list.addElement("First");
    list.addElement("Second");
    list.addElement("Third");
    std::cout << "Список з початку:\n";
    list.printList();


    std::cout << "Введіть кількість елементів які потрібно додати і їх індекси[0 - " << list.Size() <<"] ";
    std::cin >> k;
    for(int i = 0; i<k; i++){
        std::cin >> app_index[i];
    }
    std::cin.ignore();

    std::string add_el;
    for(int i = 0; i<k; i++){
        current_app_index = app_index[i]+i;
        std::cout << "Введіть значення(рядок) елементу за індексом " << current_app_index << " : ";
        std::getline(std::cin, add_el);
        list.insertEl(add_el, current_app_index); 
    }



    std::cout << "Список після додавання елементів:\n";
    list.printList();

    std::cout << "Введіть кількість елементів які потрібно видалити(макс. " << list.Size() << " ), а потім їх індекс: ";
    std::cin >> k;
    
    for(int i = 0; i<k; i++){
        std::cin >> del_index;
        list.deleteElement(del_index-i); 
    }
    
    std::cout << "Список після видалення елементів:\n";
    list.printList();

    std::cout << "\nСписок завантажуємо у файл\n\n";
    list.saveToFile("list.txt");
    list.clear();

    std::cout << "Список після очищення:\n";
    list.printList();

    list.loadFromFile("list.txt");
    std::cout << "Список після завантаження з файлу:\n";
    list.printList();

    return 0;
}

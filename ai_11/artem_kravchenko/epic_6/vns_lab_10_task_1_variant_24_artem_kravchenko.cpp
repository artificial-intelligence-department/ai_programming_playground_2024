#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct vuzol{
    char* key;
    vuzol* next;
    vuzol* prev;

    vuzol(const char* data){
        key = new char[strlen(data) + 1];
        strcpy(key, data);
        next = nullptr;
        prev = nullptr;
    }
    ~vuzol(){
        delete[] key;
    }
};
class d_list{
    private:
    vuzol* head;
    vuzol* tail;
    public:
    d_list() : head(nullptr), tail(nullptr){}

    void create(){
        head = nullptr;
        tail = nullptr;
    }

    void add(const char* data){
        vuzol* new_vuzol = new vuzol(data);
        if (!head)
        {
            head = tail = new_vuzol;
        }else{
            tail->next = new_vuzol;
            new_vuzol->prev = tail;
            tail = new_vuzol;
        }
        
    }

    void delete_el(const char* delete_key){
        vuzol* current = head;
        while (current)
        {
            if (strcmp(current->key, delete_key) == 0)
            {
                if (current->prev)
                {
                    current->prev->next = current->next;
                }else{
                    head = current->next;
                }
                if (current->next)
                {
                    current->next->prev = current->prev;
                }else{
                    tail = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        
    }

    void print() const{
        if (!head)
        {
            cout << "Список прожній"<< endl;
            return;
        }
        vuzol* current = head;
        while(current){
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    void save_file(const char* name_f) const{
        ofstream file (name_f);
        if (!file)
        {
            cerr << "Помилка відкриття файлу" << endl;
            return;
        }
        vuzol* current = head;
        while (current)
        {
            file << current->key << endl;
            current = current->next;
        }
        file.close();
    }

    void load_file(const char* name_f) {
        ifstream file(name_f);
        if (!file)
        {
            cerr << "Помилка відкриття файлу" << endl;
            return;
        }
        delete_list();
        char list[256];
        while (file.getline(list, 256))
        {
            add(list);
        }
        file.close();
    }
    void delete_list(){
        vuzol* current = head;
        while (current)
        {
            vuzol* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
    ~d_list(){
        delete_list();
    }
};

void menu(){
    cout << "\nМеню:\n";
    cout << "1. Додати елемент\n";
    cout << "2. Видалити елемент\n";
    cout << "3. Вивести список\n";
    cout << "4. Зберегти список у файл\n";
    cout << "5. Завантажити список з файлу\n";
    cout << "6. Вийти\n";
    cout << "Ваш вибір: ";
}

int main(){
    d_list list;
    char input[256];
    int choice;

    do
    {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Введіть елемент: ";
            cin.getline(input, 256);
            list.add(input);
            break;
        case 2:
            cout << "Введіть елемент для видалення: ";
            cin.getline(input, 256);
            list.delete_el(input);
            break;
        case 3:
            list.print();
            break;
        case 4:
            cout << "Введіть ім'я файлу: ";
            cin.getline(input, 256);
            list.save_file(input);
            break;
        case 5:
            cout << "Введіть ім'я файлу: ";
            cin.getline(input, 256);
            list.load_file(input);
            break;
        case 6:
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
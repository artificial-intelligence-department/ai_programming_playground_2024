#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <string>
#include <fstream>

using namespace std;

const int Variant = 11;

float function_1() {
    float a, b;
    cin >> a >> b;

    int c, d, e;
    cin >> c >> d >> e;

    double f;
    cin >> f;

    double array[] = {(double)a, (double)b, (double)c, (double)d, (double)e, f};
    sort(array, array+6);

    double max_sum = array[3] + array[4] + array[5];
    double min_sum = array[0] + array[1] + array[2];

    float x = 1;
    if (max_sum > min_sum*2 && max_sum < min_sum*3) { 
        x = (double)(max_sum * min_sum);
    } else if (max_sum > min_sum*3 && max_sum < min_sum*4 && min_sum != 0) { 
        x = (double)(max_sum / min_sum);
    } else if (max_sum > min_sum*4) { 
        x = (double)(max_sum + min_sum);
    }
    float fin = x/Variant;
    cout << fin << endl;

    return fin;
}

float** function_2(float& x) {
    float** matrix = new float*[5];

    for (int i = 0; i < 5; i++) {
        matrix[i] = new float[5];
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // нове_значення=(поточне_значення+номер_варіанту+індекс_стовбця−індекс_стрічки)∗rand(1,100)
            matrix[i][j] = (matrix[i][j] + Variant + j - i) * (rand() % 101);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}

float* function_3(float** matrix) {
    float* array_sort1 = new float[5];
    /*    Звірити чи результати обох пошуків співпадають та повідомити про це в консоль.
    Записати ці знайдені елементи у створений масив.*/
    for (int i = 0; i < 5; i++) {
        float minimal = numeric_limits<float>::max();
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] < minimal) {
                minimal = matrix[j][i];
                array_sort1[i] = matrix[j][i];
            }
        }
    }

    float* array_sort2 = new float[5];
    for (int i = 0; i < 5; i++) {
        array_sort2[i] = min({matrix[0][i], matrix[1][i], matrix[2][i], matrix[3][i], matrix[4][i]});
    }

    bool identical = true;
    for (int i = 0; i < 5; i++) {
        if (array_sort1[i] != array_sort2[i]) {
            identical = false;
            break;
        }
    }
    if (identical) cout << "The two sorting methods return the same result\n";
    else cout << "The two sorting methods return different result\n";

    for (int i = 0; i < 5; i++) {
        delete matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;

    return array_sort1;
}

struct Node {
    string name_st;
    string surname_st;
    float money_st;
    Node* prev;
    Node* next;

    Node(string name, string surname, float money) : name_st(name), surname_st(surname), 
    money_st(money), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    private:
    Node* tail;
    Node* head;
    
    public:
    //Create Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(string name, string surname, float money) {
        Node* newNode = new Node(name, surname, money);
        if(!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printForward() {
        Node* current = head;
        size_t i = 1;
        while (current) {
            cout << "Student #" << i << endl;
            cout << "\tName: " << current->name_st << endl;
            cout << "\tSurname: " << current->surname_st << endl;
            cout << "\tMoney: " << current->money_st << endl;
            
            current = current -> next;
            i++;
        }
        cout << endl;
    }

    Node* GetHead() const {
        return head;
    }
    //Create Destructor
    ~DoublyLinkedList() {
        Node* current = head;
        while(current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

DoublyLinkedList function_4(float* array) {
    string name_array[] = {"Yurii", "Oleksa", "Oleh", "Lesia", "Ted", "Akira", "Michael"};
    string surname_array[] = {"Klymchuk", "Shevchenko", "Tsokh", "Mosbi", "Mosbi", "Kurosawa", "Shumaher"};

    sort(array, array+5);

    float* money_array = new float[7];
    //Asign the biggest and the smallest value
    money_array[0] = array[4];
    money_array[6] = array[0];
    for (size_t i = 0; i < 5; i++){
        if (i == 4) money_array[i+1] = array[i] + array[0];
        money_array[i+1] = array[i] + array[i+1];
    }

    DoublyLinkedList list;
    for (size_t i = 0; i < 7; i++) {
        list.append(name_array[rand() % 7], surname_array[rand() % 7], money_array[i]);
    }

    list.printForward();

    delete[] money_array;
    money_array = nullptr;

    return list;
}



//Create a function
void help_for_function_5() {
    cout << "I do nothing\n";
}

//Perevantaguemo function
void help_for_function_5(Node* current, ofstream& file) {
    size_t i = 1;
        while (current) {
            file << "Student #" << i << endl;
            file << "\tName: " << current->name_st << endl;
            file << "\tSurname: " << current->surname_st << endl;
            file << "\tMoney: " << current->money_st << endl;
    
            current = current -> next;
            i++;
        }
};

void function_5(DoublyLinkedList& list) {
    ofstream file("text.txt");
    if(!file.is_open()) cerr << "Error while opening file";

    Node* current = list.GetHead();

    help_for_function_5(current, file);
    
    file.close();
}

//I assume in task 6 you ment "function_6" instead of "function_5"
void function_6() {
    ifstream file("text.txt");
    if(!file.is_open()) cerr << "Error while opening file";

    string line;
    while(getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    float x;
    x = function_1();

    float** tower;
    tower = function_2(x);

    float* min_array;
    min_array = function_3(tower);

    DoublyLinkedList list = function_4(min_array);
    
    function_5(list);

    //Delete the list to allocate memory 
    // list.~DoublyLinkedList();

    function_6();
    return 0;
}
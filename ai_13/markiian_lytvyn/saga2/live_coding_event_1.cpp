#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int varriant = 70; // 4. в коді використана як мінімум одна цілочисельна константа
float function_1(){
    float a, b; // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    int c, d, e; // 1. в коді використана як мінімум одна цілочисельна змінна
    double f; // 2. в коді використана як мінімум одна дійсна змінна
    cin >> a >> c >> d >> e >> f;  //18. в коді використано оператори введення даних
    float arr1[6] = {a, b, c, d, e, f}; // 6. в коді використаний одновимірний масив
    sort(arr1[0], arr1[5]);
    float Sum_Min = arr1[0] + arr1[1] + arr1[2];
    float Sum_Max = arr1[3] + arr1[4] + arr1[5];
    float res;
    if (Sum_Max > (Sum_Min * 2)){ // 5. в коді використані умовні оператори та розгалуження
        if (Sum_Max > (Sum_Min * 3)){
            if (Sum_Max > (Sum_Min * 4)){
            res = Sum_Max + Sum_Min;
            }   
            else {
                res = Sum_Max / Sum_Min;
            }
        }
        else {
            res = Sum_Max * Sum_Min;
        }
    }
    float x = res/varriant; // 15. в коді використано математичні операції та математичні функції
    cout << x;
    return x;
}

float **function_2(float &x){
    float **arr2 = new float *[5];

    for (int i = 0; i < 5; i++){ // 7. в коді використаний двовимірний масив 
        for (int j = 0; j < 5; j++){
            arr2[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++){ 
        for (int j = 0; j < 5; j++){
            float new_x = (x + varriant + j - i) * (rand()%100+1);
            arr2[i][j] = new_x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << arr2[i][j];
        }
    }
    return arr2;
}

float *function_3(float **tower){ //14. в коді використано параметри та аргументи функції
    float *arr1 = new float[5];
    float *arr2 = new float[5];
    for (int j = 0; j < 5; j++){
        float min_el = tower[0][j];
        for (int i = 0; i < 5; i++){
            if (min_el > tower[j][i]){
                min_el = tower[j][i];
            }
        }
    arr1[j] = min_el;
    }

    for (int i = 0; i < 5; i++){
        float value[5] = {0, 0, 0, 0, 0};
        for (int j = 0; j < 5; j++){
            value[j] = tower[j][i];
        }
    sort(value, value + 5);
    arr2[i] = value[0];
    }
    bool result;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (arr1[j] = arr2[i]){
                bool result = true;
            }
            else {
                bool result = false;
            }
        }
    }
    if (result){
        cout << "Same" << endl;
    }
    else{
        cout << "Different" << endl;
    }
    return arr1;
}

struct Student{ //19. в коді використано свою структуру даних
    string first_name;
    string last_name;
    float money;
    Student* prev;
    Student* next;
    Student (string first_name, string last_name, float money){}
    Student* head = NULL;
    Student* tail = NULL;
    };
struct Node* head = NULL;
struct Node* tail = NULL;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

Node newnode(Node *current, int newData){
    Node *newNode;
    newNode = new Node;
    newNode -> data = newData;
    newNode -> next = NULL;
    newNode -> prev = current;
    current -> next = newNode;
    struct Students* ptr;
    if (head != NULL){
        head = tail = newNode;
    }
    else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}
void print(Student* head){
    cout << "Student's list: " << endl;
    Student* current = head;
    while (current) { // 9. в коді використаний while цикл
        cout << current->first_name << " " << current -> last_name << " " << current-> money << endl;
    current = current->next;
    }
}

Student *function_4(float *arr4){
    string first_name1[] = {"Markiian", "Danylo", "Roman", "Artem", "Andriy", "Zakhar", "Vasyl"};
    string last_name1[] = {"Lytvyn", "Kolbasyuk", "Boyko", "Kobzar", "Fediv", "Junyk", "Malyar"}; 
    Student *next = nullptr;
    Student *prev = nullptr;
    Student *head = nullptr;
    for (int i = 0; i < 7; i++){ // 10. в коді використаний for цикл
        float money;
        string first_name = first_name1[i];
        string last_name = last_name1[i];
        if (i == 0){
            money = arr4[4];
        }
        else if (i >= 1 && i <= 5){
            money = arr4[i-1];
        }
        else if (i == 6){
            money = arr4[0];
        }
    }
    print(head);
    return head;
}

void help_for_function_5(Student* tail, ofstream& file_in){ // 13. в коді використано рекурсивну функцію 
    if (!tail){
        cerr << "Error";
        return;
    }
    help_for_function_5(tail->next, file_in);
    file_in << tail -> first_name << tail -> last_name << tail -> money << endl; // 16. в коді використано функції роботи з файлами, для того, щоб записати у файл
}

void function_5(Student* tail){ 
    ofstream file_in("student_list.txt");
    if (!file_in){
        cerr << "Error while opening";
        return;
    }
    help_for_function_5(tail, file_in);
    file_in.close();
}
void function_6(){
    ifstream file_out("student_list.txt");
    if (!file_out){
        cerr << "Error while opening";
        return;
    }
    string line1;
    while (getline(file_out, line1)){ //17. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
        cout << line1 << endl; //18. в коді використано оператори виведення даних
    }
    file_out.close();
}

int main(){
    float x = function_1();
    float** tower = function_2(x); //20. в коді використано вказівники

    float *arr4 = function_3(tower);
    Student* list = function_4(arr4);
    function_5(list);
    function_6();
}
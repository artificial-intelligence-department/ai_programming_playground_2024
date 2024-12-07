//1 год 50 хв
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
const int VARIANT = 7; //цілочисельна константа для позначення варіанту

double function_1(){
    float a, b; //дійсна змінна
    int c, d, e; // цілочисельна зміннa
    double f; //дійсна змінна з подвійною точністю

    cout << "Ведіть різні значення для аргументів 6 шт:";
    cin >> a >> b; //оператор введення даних
    cin >> c >> d >> e;
    cin >> f;

    double numbers[6] = {static_cast<double>(a), static_cast<double>(b), static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f};//одновимірний масив
    sort (numbers, numbers +6);
            
    double result = 0;
    double sum_min = numbers[0]+ numbers[1]+ numbers[2];
    double sum_max = numbers[3] + numbers[4] + numbers[5];

    if (sum_max > (sum_min*4)){ // умовні оператори та розгалуження для знаходження суми за певними критеріями
        result = sum_min + sum_max;}
    else if (sum_max > (sum_min*3)){ //математичні операції множення
        result = sum_min / sum_max;}
    else if (sum_max > (sum_min*2)){
        result = sum_min * sum_max;}
    else 
        cout << "Error" << endl;
               
    
    result /= VARIANT;
    return result;
}

int** function_2(double& x){
    int** matrix = new int*[5]; // створення двовимірного масиву для збереження значень
    for (int i = 0; i < 5; i++){ // цикл for для руху по елементах масиву
        matrix[i] = new int [5];
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = x;
        }
    }  

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = (matrix[i][j] + VARIANT + i + j) * (rand() % 100);
        }
    }   
    
    return matrix; 
}

void printMatrix(int** matrix){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << " "; // оператор виведенння даних
        }
    cout << endl;
    }    
}
int* function_3 (int **tower){
     //перший спосіб
    int* result = new int[5]; // використано одновимірний масив для збереження результатів
    for (int j = 0; j < 5; j++)
    {
        int minElem = tower[0][j];
        for (int i = 1; i < 5; i++)
        {
            if (tower[i][j] < minElem)
            {
                minElem = tower[i][j];
            }
        }
        result[j] = minElem;
    }
    //другий спосіб
    int* result_2 = new int[5];

    for (int i = 0; i < 5; i++){
        int temp[5];
        for (int j = 0; j < 5; j++){
            temp[j] = tower[j][i]; 
        }

        int min = temp[0];
        for (int j = 0; j < 5; j++){
            if ( temp[j] < min){
                min = temp [j];
            }
        }
        result_2[i] = min;
    }

    bool isEqual = true;
    for (int i = 0; i < 5; i++){
        if (result_2[i] != result[i] ){
            isEqual = false;
            break;} // примусовий вихід з циклу адже одного false достатньо щоб умова не виконувалась
    }

    if (isEqual ){
        cout << "Results are equal" << endl;
    }
    else 
        cout << "Results are not equal" << endl;
    return result_2;
}

struct Node{ // структура для вузла двозв'язног списку
    string name;
    string surname;
    double balance;
    Node* prev;//вказівники на елементи списку
    Node* next;

    Node (string name, string surname, double balance): name(name), surname(surname), balance(balance), prev(nullptr), next(nullptr){}
    };

Node* function_4(int* result){
    string names[] = { "Vika", "Vasyl", "Pavlo", "Stepan", "Anatoliy", "Lesia", "Anna"};

    string surnames[] = {"Petriv", "Shevchenko", "Silver", "Gold", "Franko", "Ivanenko", "Pavlenko"};

    Node* head = new Node (names[0], surnames[0], *max_element(result, result + 5));
    Node* cur = head;

    for (int i = 1; i < 6; i++){

        Node* newNode = new Node (names[i], surnames[i], result[i-1] + result[i%5]); 
        cur -> next = newNode;
        newNode -> prev = cur;
        cur = newNode;
    }

    Node* last = new Node(names[6], surnames[6], *min_element(result, result + 5));
    cur -> next = last;
    last -> prev = cur;

    cout << endl << endl << "List:" << endl;
    cur = head; 
    while (cur) { // цикл while для виходу з якого потрібно щоб поточний елемент став нульовим вказівником
        cout << cur->name << " " << cur->surname << " Balance$: "<< cur -> balance << endl;
        cur = cur->next;
    }
    cout << endl;
    return head;
}

void help_for_function_5( Node* tail, ofstream& file){ // функція аргументами якої є вузол та файл
    if (tail == nullptr){
        return;
    }
    file << tail->name << " " << tail->surname << " Balance$: "<< tail -> balance << endl;
    help_for_function_5(tail -> prev, file); // рекурсія для виводу
}

void help_for_function_5( Node* head, ofstream& file, int a){ //первантеження функції для іншого виводу через цикл
    Node* cur = head;
    while (cur) {
        file << cur->name << " " << cur->surname << " Balance$: "<< cur -> balance << endl;
        cur = cur->next;
    }
}

void function_5( Node* ListOfStidents){
    ofstream file ("Students.txt"); //запис у файл
    if (!file.is_open()){
        cerr << " Fail!" << endl;
        return;
    }
    if (VARIANT % 2 == 0){
        Node* tail = ListOfStidents;
        while ( tail -> next != nullptr){
            tail = tail -> next; 
        }
        help_for_function_5(tail, file); 
    }
    else 
        help_for_function_5(ListOfStidents, file, 1);
}

void function_6(){
    ifstream file("Students.txt"); // читання з файлу
    if (!file.is_open()){
        cerr << " Fail!" << endl;
        return;
    }

    cout << "Info from file: " << endl;
    string info;
    while (getline(file, info)){
        cout << info << endl;
    }
}
int main()
{
    srand(time(0));

    double x = function_1();
    int** tower = function_2(x);
    printMatrix(tower);

    int* result = function_3 (tower);
    cout << "Min elements in col: " << endl;
     for (int i = 0; i < 5; i++){
        cout << result[i] << " ";
    }

    Node* ListOfStidents = function_4 (result);

    function_5(ListOfStidents);
    function_6();

    for (int i = 0; i < 5; i++){
        delete[] tower[i];
    }
    delete[] tower;
    delete[] result;

return 0;
}

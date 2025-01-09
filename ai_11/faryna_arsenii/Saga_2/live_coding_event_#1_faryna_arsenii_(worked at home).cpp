#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

const int VARIANT = 25; // номер варіанта
const int SIZE = 5; // матриця буде сталою розміром 5x5

struct Student
{
    string name;
    string surname;
    double accountBalance;

};

struct Node
{
    Student data;
    Node* next;
    Node* prev;
};

Node* create_new_Node(const Student& student){
    Node* newNode = new Node;
    newNode->data = student;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode; 
}

// прототипи функцій
int function_1();
void function_2(double& x, double** matrix);
void print_matrix(double** matrix);
void initialize_matrix_x(double& x, double** matrix);
double* function_3(double** tower);
vector<Student> function_4(double* result_array);
void function_5(const vector<Student>& students);
void help_for_function_5(const vector<Student>& students, ofstream& file, int index);
void help_for_function_5(const vector<Student>& students);
void read_from_file_and_print_file(const string& filename);

int function_1(){ // функція типу int, щоб число було цілим 

    float a, b;
    int c, d, e;
    double f;

    cout << "Введіть два дійсних числа a, b: ";
    cin >> a >> b;
    cout << "Введіть три цілі числа c, d, e: ";
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з подвійною точнісю: ";
    cin >> f;

    vector<double> numbers = { static_cast<double> (a), static_cast<double> (b), static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f };

    sort(numbers.begin(), numbers.end());

    double sum_of_largest_numbers = numbers[3] + numbers[4] + numbers[5];
    double sum_of_lowest_numbers = numbers[0] + numbers[1] + numbers[2];

    double result;

    if (sum_of_largest_numbers > (sum_of_lowest_numbers * 2)){
        result = sum_of_largest_numbers * sum_of_lowest_numbers;
    }
    else if (sum_of_largest_numbers > (sum_of_lowest_numbers * 3)){
        result = sum_of_largest_numbers / sum_of_lowest_numbers;
    }
    else if (sum_of_largest_numbers > (sum_of_lowest_numbers * 4)){
        result = sum_of_largest_numbers + sum_of_lowest_numbers;
    } 
    
    double x = result / VARIANT;

    return x;
}

void function_2(double& x, double** matrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matrix[i][j] = ((x + VARIANT + j + i) * (1 + rand() % 100));
        }
    }
}

void print_matrix(double** matrix){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void initialize_matrix_x(double& x, double** matrix){

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matrix[i][j] = x;
        }
    }

}

double* function_3(double** tower){
    
    double* result_array = new double[SIZE];

    // перший спосіб
    double array1[SIZE];
    for (int j = 0; j < SIZE; j++){
        double min = tower[0][j];
        for (int i = 0; i < SIZE; i++){
            if (tower[i][j] <= min){
                min = tower[i][j];
            }
        }
        array1[j] = min;
    }
    // другий спосіб
    double array2[SIZE];
    for (int j = 0; j < SIZE; j++){
        array2[j] = INT_MAX; 
    }

    for (int j = 0; j < SIZE; j++){
        for (int i = 0; i < SIZE; i++){
            if (tower[i][j] < array2[j]){
                array2[j] = tower[i][j];
            }
        }
    }

    bool is_arrays_equals = true;
    for (int i = 0; i < SIZE; i++){
        if (array1[i] != array2[i]){
            is_arrays_equals = false;
        }
        result_array[i] = array1[i];
    }

    if (is_arrays_equals){
        cout << "Результати співпадають!)" << endl;
    }
    else {
        cout << "Результати не співпадають!" << endl;
    }

    return result_array;

}

vector<Student> function_4(double* result_array){
    string names[] = { 
    "Юрій", 
    "Дмитрій", 
    "Анастасія", 
    "Арсеній", 
    "Софія", 
    "Ірина", 
    "Остап"};

    string surnames[] = {
    "Бубельник", 
    "Козарюк",
    "Гуменюк",
    "Фарина",
    "Мазур",
    "Балабанська",
    "Галадій" };

    vector<Student> students;
    double largest = result_array[0];
    double smallest = result_array[0];
    double sum = 0;

    for (int i = 0; i < SIZE ; i++){
        sum += result_array[i];
        if (result_array[i] > largest){
            largest = result_array[i];
        }
        if (result_array[i] < smallest){
            smallest = result_array[i];
        }
    }

    for (int i = 0; i < 7; i++){
        Student student;
        student.name = names[i];
        student.surname = surnames[i];

        if (i == 0){
            student.accountBalance = largest;
        } else if (i == 6){
            student.accountBalance = smallest;
        }
        else {
            student.accountBalance = sum + result_array[i % SIZE];
        }

        students.push_back(student);
    }

    return students;

}

void help_for_function_5(const vector<Student>& students){
    ofstream file("students_odd.txt");

    if (file.is_open()){
        for (const auto& student : students){
            file << "Ім'я: " << student.name
                << ", Прізвище: " << student.surname
                << ", Баланс: " << student.accountBalance << endl;
        }
        file.close();
        cout << "Дані збережено у файл 'students_odd.txt' успішно! " << endl;
    }
    else {
        cout << "Не вдалося відкрити файл 'students_odd.txt' для запису!" << endl;
    }
}

void help_for_function_5(const vector<Student>& students, ofstream& file, int index){

    if (index < 0){
        return;
    }

    file << "Ім'я: " << students[index].name
        << ", Прізвище: " << students[index].surname
        << ", Баланс: " << students[index].accountBalance 
        << endl;
    help_for_function_5(students, file, index - 1);

}

void function_5(const vector<Student>& students){

    ofstream file("students.txt");
    if (file.is_open()){
        help_for_function_5(students, file, students.size() - 1);
    
        file.close();
        cout << "Дані збережено у файл 'student.txt' успішно! " << endl;
    
    }
    else {
        cout << "Не вдалося відкрити файл ''student.txt' для запису! " << endl;
    }

}

void read_from_file_and_print_file(const string& filename){

    ifstream file(filename);
    if (!file.is_open()){
        cout << "Файл " << filename << "не знайдено або не вдалося відкрити!" << endl;
        return; // або exit(1)
    }

    cout << "Вміст файлу " << filename << "." << endl;
    string line;
    while (getline(file, line)){
        cout << line << endl;
    }
    file.close();

}

int main (){

    srand(time(nullptr));

    double x = function_1();
    cout << "Результат: " << x << endl;

    double** tower = new double*[SIZE];
    for (int i = 0; i < SIZE; i++){ 
        tower[i] = new double[SIZE];
    }

    initialize_matrix_x(x, tower);
    cout << "Початкова матриця, заповнена значеннями х: " << endl;
    print_matrix(tower);
    cout << endl;

    function_2(x, tower);
    cout << "Оновлена матриця: " << endl;
    print_matrix(tower);
    cout << endl;

    double* result_array = function_3(tower);
    cout << "Найменші елементи матриці з кожного стовпчика: " << endl;
    for (int i = 0; i < SIZE; i++){
        cout << result_array[i] << " ";
    }
    cout << endl;

    vector<Student> students = function_4(result_array); 
    function_5(students);

    read_from_file_and_print_file("students.txt");

    delete[] result_array;
    for (int i = 0; i < SIZE; i++){
        delete[] tower[i];
    }  
    delete[] tower;  

    return 0;
}
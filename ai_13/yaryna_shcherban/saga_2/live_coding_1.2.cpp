#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
// 4) цілочисельна константа
const int VARIANT = 84;


double function_1() {
// 3) дійсна з подвійною точністю змінна
    double a, b, f;
// 1) цілочисельна змінна
    int c, d, e;
// 18) оператори виведення та введення даних
    cout << " Enter a, b ( double ): ";
    cin >> a >> b;
    cout << " Enter c, d, e ( integer ): ";
    cin >> c >> d >> e;
    cout << " Enter f ( double ): ";
    cin >> f;
// 6) одновимірний масив
    double values[6] = { a, b, static_cast<double>(c), 
        static_cast<double>(d), static_cast<double>(e), f};
    sort(values, values + 6);

    double sum_min = values[0] + values[1] + values[2] ;
    double sum_max = values[3] + values[4] + values[5] ;
    double result;
// 5)  умовний оператор та розгалуження
    if ( sum_max > sum_min * 4) {
        result = sum_max + sum_min;
    } else if ( sum_max > sum_min * 3 ) {
        result = sum_max / sum_min;
    } else if ( sum_max > sum_min * 2 ) {
        result = sum_max * sum_min;
    } else {
        result = 0;
    }
// 15) математична операція
    double x = result / VARIANT;
    cout << " Result of first function : x = " << x << endl;
    return x;
}

// 14)  параметри та аргументи функції
void function_2(double &x, double matrix[5][5]) {
// 10)  for цикл
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = ( x + VARIANT + j - i ) * (rand() % 100 + 1);
        }
    }

    cout << " Matrix : " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}


void function_3(double matrix[5][5], double tower[5]) {

    for (int j = 0; j < 5; j++) {
        double min_element_1 = matrix[0][j];
        for (int i = 0; i < 5; i++) {
            if (matrix[i][j] < min_element_1) {
                min_element_1 = matrix[i][j];
            }
        }
// 20) використано вказівники
        double* column_start = &matrix[0][j];
        double* column_end = column_start + 5;
        double min_element_2 = *min_element(column_start, column_end);

        if ( min_element_1 != min_element_2) {
            cout << " Results are different " << endl;
        } else {
            cout << " Results are the same " << endl;
        }

        tower[j] = min_element_1;
    }
}

// 11) структура даних
struct Student {
    string firstName;
    string lastName;
    double balance;

    Student* prev;
    Student* next;
};

Student* createStudent(const string&firstName, 
            const string&lastName, double balance) {

    Student* newStudent = new Student;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->balance = balance;
    newStudent->prev = nullptr;
    newStudent->next = nullptr;

    return newStudent;
}

void addStudent(Student*& head, const string& firstName,
         const string&lastName, double balance) {

    Student* newStudent = createStudent(firstName, lastName, balance);
    if ( head == nullptr ) {
        head = newStudent;
    } else {
        Student* temp = head;
// 9) while цикл
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->prev = temp;
    }
}

void printStudents(Student* head) {
    cout << " List of students : " << endl;
    Student* current = head;
    while (current) {
        cout << " First name : " << current->firstName << ", Last name : " 
            << current->lastName << ", Balance : " << current->balance << endl;
        current = current->next;
    }
}

void deleteList(Student* head) {
    while(head) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

Student* function_4(double array[5]) {
    srand(static_cast<unsigned>(time(0)));
    Student* head = nullptr;

    string firstNames[ ] = {"Yaryna", "Vladyslav", "Natalia",
        "Roman", "Anhelina", "Zakharii", "Yaryna"};
    string lastNames[ ] = {"Panychevska", "Murashco", "kozak",
        "Boiko", "Bobrynok", "Shturyn", "Shcherban"};

    double max_value = array[0];
    double min_value = array[0];
    for (int i = 0; i < 5; i++) {
        if (array[i] > max_value ) {
            max_value = array[i];
        }
        if (array[i] < min_value ) {
            min_value = array[i];
        }
    }

    addStudent(head, firstNames[0], lastNames[0], max_value);
    double sum = 0;
    for (int i = 0; i < 6; ++i) {
        sum += array[i-1];
        addStudent(head, firstNames[i], lastNames[i], sum);
    }
    addStudent(head, firstNames[6], lastNames[6], min_value);

    printStudents(head);
    return head;
}

// 13) рекурсивна функцію 
void help_for_function_5(Student* head, ofstream& outFile) {
    if (head == nullptr) {
        return;
    }
    help_for_function_5(head->next, outFile);
// 16) функції роботи з файлами, для того, щоб записати у файл
    outFile << " First name : " << head->firstName << ", Last name : " 
            << head->lastName << ", Balance : " << head->balance << endl;
}

void function_5(Student* head) {
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << " Error opening file! " << endl;
        return;
    }
    help_for_function_5(head, outFile);
    outFile.close();
    cout << " Success in writing to file! " << endl;
}


void function_6() {
// 17) функції роботи з файлами, для того, щоб зчитати з файлу
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << " Error opening file! " << endl;
        return;
    }
    cout << " Success in reading file! " << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main(){
    
    double x = function_1();
// 7) двовимірний масив 
    double matrix[5][5];
    function_2( x, matrix );

    double tower[5];
    function_3(matrix, tower);
    cout << " Tower : ";
    for (int i = 0; i < 5; i++) {
        cout << tower[i] << " ";
    }
    cout << endl;

    Student* students = function_4(tower);
    function_5(students);

    function_6();

    deleteList(students);
    return 0;
}
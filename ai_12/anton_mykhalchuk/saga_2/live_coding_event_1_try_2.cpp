#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int var = 47;

double function_1() {
    float a, b;
    int c, d, e;
    double f;

    cout << "Enter 2 float numbers: ";
    cin >> a >> b;

    cout << "Enter 3 int numbers: ";
    cin >> c >> d >> e;

    cout << "Enter 1 double number: ";
    cin >> f;

    double arr[6] = {static_cast<double>(a), static_cast<double>(b),
    static_cast<double>(c), static_cast<double>(d), 
    static_cast<double>(e), f};

    bool swapped;
    for (int i = 0; i < 6 - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    double sumMin = 0, sumMax = 0;

    for (int i = 0; i < 3; i++) {
        sumMin += arr[i];
    }
    for (int i = 3; i < 6; i++) {
        sumMax += arr[i];
    }

    double out = 0;

    if (sumMax > sumMin * 4) {
        out = sumMax + sumMin;
    }
    else if (sumMax > sumMin * 3) {
        if (sumMin != 0) {
            out = sumMax / sumMin;
        }
        else if (sumMax != 0) {
            out = sumMin / sumMax;
        }
    }
    else if (sumMax > sumMin * 2) {
        out = sumMin*sumMax;
    }

    double x = out / var;

    return x;
}

double** function_2(double &x) {
    double** arr2 = new double*[5];
    for (int i = 0; i < 5; i++) {
        arr2[i] = new double[5];
        for (int j = 0; j < 5; j++) {
            arr2[i][j] = x; 
        }
    }

    srand(time(nullptr));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int randomValue = rand() % 99 + 1;
            arr2[i][j] += var + i + j + randomValue; 
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << setw(10) << arr2[i][j];
        }
        cout << endl;
    }

    return arr2;
}

// Рекурсивний спосіб знайти мінімальне значення.
double findMin(double* arr, int n) {
    if (n == 1) 
        return arr[0];
    return min(arr[n - 1], findMin(arr, n-1));
}

double findMax(double* arr, int n) {
    if (n == 1) 
        return arr[0];
    return max(arr[n - 1], findMax(arr, n-1));
}

double* function_3(double** tower) {
    double* findArr = new double[5];
    
    for (int col = 0; col < 5; ++col) {
        double minVal = tower[0][col];
        for (int row = 1; row < 5; ++row) {
            if (minVal > tower[row][col]) {
                minVal = tower[row][col];
            }
        }
        findArr[col] = minVal;
    }

    double* columToFunc = new double[5];
    double* findArrRecursive = new double[5];
    for (int col = 0; col < 5; ++col) {
        for (int row = 0; row < 5; ++row) {
            columToFunc[row] = tower[row][col];
        }
        findArrRecursive[col] = findMin(columToFunc, 5);
    }

    bool theSame = true;
    for (int col = 0; col < 5; ++col) {
        if (findArrRecursive[col] != findArr[col]) theSame = false;
    }

    if (theSame) {
        cout << "Recursive method and Linear search have given the same results!" << endl;
    }
    else {
        cout << "Recursive method and Linear search have given different results!" << endl;
    }
    

    return findArr;

}

struct Student {
    string firstName;
    string lastName;
    double money;
};

struct Node {
    Student student;
    Node* prev;
    Node* next;
};

Node* createNode(const string firstName, const string lastName, double money) {
    Node* newNode = new Node;
    newNode->student = {firstName, lastName, money};
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void appendNode(Node*& head, Node*& tail, const string& firstName, const string& lastName, double money) {
    Node* newNode = createNode(firstName, lastName, money);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << "Name: " << current->student.firstName
             << ", Surname: " << current->student.lastName
             << ", Amount of money: " << current->student.money << "hrn\n";
        current = current->next;
    }
}

void clearList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

Node* function_4(double* arr) {
    Node* head = nullptr;
    Node* tail = nullptr;
    appendNode(head, tail, "Ivan", "Petrenko", findMax(arr, 5));
    double sum = 0;
    string names[5] = {"Pylyp", "Stepan", "Syveryn", "Bohdan", "Olha"};
    string surnames[5] = {"Koval", "Vivcharenko", "Lantukh", "Cherven", "Miroshnychenko"};
    
    for (int i = 0; i < 5; ++i) {
        sum += arr[i];
        appendNode(head, tail, names[i], surnames[i], sum);
    }

    appendNode(head, tail, "Vladyslav", "Melnyk", findMin(arr, 5));

    printList(head);

    return head;
}

void help_for_function_5(Node* head, ofstream& file) {
    Node* current = head;
    while (current) {
        file << current->student.firstName << " "
             << current->student.lastName << " "
             << current->student.money << endl;
        current = current->next; 
    }
}

void help_for_function_5(Node* head, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        help_for_function_5(head, file);
    }
    else {
        cerr << "Can't open file for writting: " << filename << endl;
    }
}

void function_5(Node* studentList) {
    string filename = "students.txt";
    help_for_function_5(studentList, filename);

    ifstream file(filename);

    if (file.is_open()) {
        string line;
        cout << "File content \"" << filename << "\"" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cerr << "File \"" << filename << "\" is not existing or can't be opened.\n";
    }
}

int main() {

    cout << "Task 1" << endl;
    double x = function_1();
    cout << x << endl << endl;

    cout << "Task 2" << endl;
    double** tower = function_2(x);
    cout << endl << endl;

    cout << "Task 3" << endl;
    double* lst = function_3(tower);

    cout << "Task 4" << endl;
    Node* twoWaysList = function_4(lst);

    cout << "Task 5-6" << endl;
    function_5(twoWaysList);
    return 0;
}



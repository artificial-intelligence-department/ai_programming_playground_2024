#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <random>

using namespace std;

// структура
struct Student {
    string name;
    string surname;
    float balance;
    Student* next;
    Student* prev;
};

double function_1() {
    // цілочисельні, дійсні та з подвійною точністю змінні
    int a, b;
    float c, d, e;
    double f;
    
    // input and output
    cout << "2 ints: ";
    cin >> a >> b;
    cout << endl;
    cout << "3 floats: ";
    cin >> c >> d >> e;
    cout << endl;
    cout << "double: ";
    cin >> f;
    cout << endl;
    
    //одновимірний масив
    double arr[] = {static_cast<double>(a), static_cast<double>(b), static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr, arr + 6);

    double sumMin = 0;
    double sumMax = 0;
    cout << "3 smallest: ";
    // for loop
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
        sumMin += arr[i];
    }
    cout << endl << "3 largest: ";
    for(int i = 3; i < 6; i++) {
        cout << arr[i] << " ";
        sumMax += arr[i];
    }
    cout << endl;

    double x;
    // розгалуження
    if(sumMax > sumMin * static_cast<double>(4)) {
        x = sumMax + sumMin;
    } else if(sumMax > sumMin * static_cast<double>(3)) {
        x = sumMax / sumMin;
    } else if(sumMax > sumMin * static_cast<double>(2)) {
        x = sumMax * sumMin;
    }

    // цілочисельна констата
    const int variant = 58;
    x = x / static_cast<double>(variant);
    cout << "x: " << x << endl;

    int l = 0;
    // do while + continue
    do {
        l++;
        if(l == 2) continue;
        cout << "hi from do while loop :)" << endl;
    } while(l < 3);
    
    return x;
}

double** function_2(double &x) {
    // 2d array
    double** matrix = new double*[5];
    for(int i = 0; i < 5; i++) {
        matrix[i] = new double[5];
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(0, 100);
    const int variant = 58;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + static_cast<double>(variant) + static_cast<double>(i) - static_cast<double>(j))
             * static_cast<double>(distr(gen));
        }
    }
    
    cout << "matrix:" << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}
// math func of finding the min value
double findMin1(double arr[]) {
    double min = arr[0];
    for(int i = 0; i < 5; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
} 

// recursion
double findMin2(double arr[], int n) {
    if(n == 1) return arr[0];
    return min(arr[n-1], findMin2(arr, n-1));   
} 

double* function_3(double** matrix) {
    double* result = new double[5];

    for(int i = 0; i < 5; i++) {
        double arr[5];

        for(int j = 0; j < 5; j++) {
            arr[j] = matrix[j][i];
        }
        double min1 = findMin1(arr);
        double min2 = findMin2(arr, 5);

        if(min1 == min2) {
            cout << "match" << endl;
        } else {
            cout << "naaaaaaah" << endl;
        }

        result[i] = min1;
    }
    return result;
}
// params and args used
Student* function_4(double arr[]) {
    Student* head = nullptr;
    Student* tail = nullptr;
    int count = 1;
    double arrSum = 0;
    double min = arr[0];
    double max = arr[0];
    for(int i = 0; i < 5; i++) {
        arrSum += arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    // while loop
    while(true) {
        // break
        if(count >= 8) break;
        // pointer
        Student* s = new Student{"name" + to_string(count), "surname" + to_string(count), 0, nullptr, nullptr};
        if(count == 1) s->balance = max;
        else if (count < 7) s->balance = arrSum;
        else if (count == 7) s->balance = min;

        if(head == nullptr) {
            head = s;
            tail = s;
        } else {
            tail->next = s;
            s->prev = tail;
            tail = s;
        }
        count++;
    }

    tail = head;
    cout << "LL: " << endl;
    while (tail != nullptr) {
        cout << " name: " << tail->name << " surname: " << tail->surname << " balance: " << tail->balance << endl;
        tail = tail->next;
    }
    return head;
}

// overloaded function
void help_for_function_5(ofstream& inputFile, Student* head) {
    if(head == nullptr) return;

    help_for_function_5(inputFile, head->next);
    // write to file
    inputFile << head->name << " " << head->surname << " " << head->balance << "\n";
}

void help_for_function_5(ofstream& inputFile, Student* head, bool foo) {
    while(head != nullptr) {
        inputFile << head->name << " " << head->surname << " " << head->balance << "\n";
        head = head->next;
    }
}

void readAndPrintFile(ifstream& inputFile) {
    cout << "file: " << endl;
    // output the file
    while(!inputFile.fail() && !inputFile.eof()) {
        string buffer;
        getline(inputFile, buffer);
        cout << buffer << endl;
    }
}

void function_5(Student* head) {
    int const variat = 58;
    ofstream inputFile("students.txt");
    if(!inputFile) {
        cerr << "can't open the file" << endl;
        return;
    }
    if(variat % 2 == 0) {
        help_for_function_5(inputFile, head);
    } else {
        help_for_function_5(inputFile, head, false);
    }
    inputFile.close();

    ifstream readFile("students.txt");
    if(!readFile) {
        cerr << "can't open the file" << endl;
        return;
    }
    readAndPrintFile(readFile);
    readFile.close();
}

void freeMemory(Student* head) {
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

void freeMatrix(double** matrix) {
    for (int i = 0; i < 5; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    double x = function_1();
    double** tower = function_2(x);
    double* arr = function_3(tower);
    Student* head = function_4(arr);
    function_5(head);
    
    freeMemory(head);
    freeMatrix(tower);
    delete[] arr;
}

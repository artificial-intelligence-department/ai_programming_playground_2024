#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <float.h>

const int VARIANT = 78;

bool isEqual(double a, double b, double epsilon = 1e-9)
{
    return std::abs(a - b) < epsilon;
}

bool lessThan(double a, double b, double epsilon = 1e-9)
{
    return (b - a) > epsilon;
}

bool greaterThan(double a, double b, double epsilon = 1e-9)
{
    return (a - b) > epsilon;
}

double function_1()
{
    double a, b, f;
    int c, d, e;
    std::cout << "Enter 2 rational numbers: ";
    std::cin >> a >> b;
    std::cout << "Enter 3 integer numbers: ";
    std::cin >> c >> d >> e;
    std::cout << "Enter 1 floating point number (double precision): ";
    std::cin >> f;

    double *numbers = new double[6]{a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    std::sort(numbers, numbers + 6);
    double minSum = 0, maxSum = 0;
    for (size_t i = 0; i < 3; ++i)
    {
        minSum += numbers[i];
        maxSum += numbers[i + 3];
    }

    double result;
    if (greaterThan(maxSum, minSum * 4))
    {
        result = maxSum + minSum;
    }
    else if (greaterThan(maxSum, minSum * 3))
    {
        if (isEqual(minSum, 0))
        {
            std::cout << "Can't devide by zero. Assigned value 0 to result.";
            result = 0;
        }
        else
        {
            result = maxSum / minSum;
        }
    }
    else if (greaterThan(maxSum, minSum * 2))
    {
        result = maxSum * minSum;
    }
    else
    {
        std::cout << "Unknown option. Assigned value 1 to result.";
        result = 1;
    }

    double x = result / VARIANT;
    std::cout << std::endl << "function_1() result is " << x << std::endl;

    return x;
}

double **function_2(double &x)
{
    double **matrix = new double *[5];
    for (size_t i = 0; i < 5; ++i)
    {
        matrix[i] = new double[5];
        for (size_t j = 0; j < 5; ++j)
        {
            matrix[i][j] = x;
        }
    }

    srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 5; ++j)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }

    std::cout << std::endl << "function_2() matrix is: " << std::endl;
    for (size_t i = 0; i < 5; ++i)
    {
        for (size_t j = 0; j < 5; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return matrix;
}

double *function_3(double **matrix)
{
    double *minValues1 = new double[5];
    for (size_t j = 0; j < 5; ++j)
    {
        double minElement = matrix[0][j];
        for (size_t i = 1; i < 5; ++i)
        {
            if (lessThan(matrix[i][j], minElement))
            {
                minElement = matrix[i][j];
            }
        }
        minValues1[j] = minElement;
    }

    double *minValues2 = new double[5];
    double *temp = new double[5];
    for (size_t j = 0; j < 5; ++j)
    {
        for (size_t i = 0; i < 5; ++i)
        {
            temp[i] = matrix[i][j];
        }
        std::sort(temp, temp + 5);
        minValues2[j] = temp[0];

        if ( !(isEqual(minValues1[j], minValues2[j])) )
        {
            std::cout << "Found min values are not equal." << std::endl;
            break;
        }
    }

    delete[] minValues2;
    delete[] temp;

    return minValues1;
}

struct Student {
    std::string firstName;
    std::string lastName;
    double balance;

    Student* prev;
    Student* next;
};

Student* createStudent(const std::string&firstName, 
            const std::string&lastName, double balance) {

    Student* newStudent = new Student;
    newStudent->firstName = firstName;
    newStudent->lastName = lastName;
    newStudent->balance = balance;
    newStudent->prev = nullptr;
    newStudent->next = nullptr;

    return newStudent;
}

void addStudent(Student*& head, const std::string& firstName,
         const std::string&lastName, double balance) {

    Student* newStudent = createStudent(firstName, lastName, balance);
    if ( head == nullptr ) {
        head = newStudent;
    } else {
        Student* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->prev = temp;
    }
}

void printStudents(Student* head) {
    std::cout << " List of students : " << std::endl;
    Student* current = head;
    while (current) {
        std::cout << " First name : " << current->firstName << ", Last name : " 
            << current->lastName << ", Balance : " << current->balance << std::endl;
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

    std::string firstNames[ ] = {"name1", "name2", "name3", "name4", "name5", "name6", "name7"};
    std::string lastNames[ ] = {"surname1", "surname2", "surname3", "surname4", "surname5", "surname6", "surname7"};

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

void help_for_function_5(Student* head, std::ofstream& outFile) {
    if (head == nullptr) {
        return;
    }
    help_for_function_5(head->next, outFile);

    outFile << " First name : " << head->firstName << ", Last name : " 
            << head->lastName << ", Balance : " << head->balance << std::endl;
}

void function_5(Student* head) {
    std::ofstream outFile("students.txt");
    if (!outFile) {
        std::cerr << " Error opening file! " << std::endl;
        return;
    }
    help_for_function_5(head, outFile);
    outFile.close();
    std::cout << " Success in writing to file! " << std::endl;
}


void function_6() {
    std::ifstream inFile("students.txt");
    if (!inFile) {
        std::cerr << " Error opening file! " << std::endl;
        return;
    }
    std::cout << " Success in reading file! " << std::endl;
    std::string line;
    while (getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();
}

int main(){
    
    double x = function_1();
    double **tower = function_2(x);
    double *minNumbers = function_3(tower);
    Student* students = function_4(minNumbers);
    function_5(students);
    function_6();

    for (int i = 0; i < 5; ++i) {
        delete[] tower[i];
    }
    delete[] tower;
    delete[] minNumbers;

    deleteList(students);
    return 0;
}

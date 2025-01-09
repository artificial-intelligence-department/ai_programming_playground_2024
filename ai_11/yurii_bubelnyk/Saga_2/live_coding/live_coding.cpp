#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

// Варіант
const int VARIANT = 3;
const int STUDENT = 7;

struct Student
{
    string name;
    string surname;
    double money;

    Student(string name = "", string surname = "", double money = 0)
        : name(name), surname(surname), money(money)
    { }
};

class List
{
private:
    struct Node
    {
        Student student;
        Node* prev;
        Node* next;

        Node(const Student& student)
            : student(student), prev(nullptr), next(nullptr)
        { }
    };

    Node* head;
    Node* tail;
    void help_for_function_5(ofstream& file, List::Node* head);
    void help_for_function_5_reverse(ofstream& file, List::Node* tail);

public: 
    List();
    ~List();
    void add(const Student& student);
    void Show();
    void function_5(const string& filename);
    void function_6(const string& filename);
};

void List::help_for_function_5(ofstream& file, List::Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        file << "Name: " << current->student.name 
        << "Surname: " << current->student.surname
        << "Money: " << current->student.money << endl;
        current = current->next;
    }
}

void List::help_for_function_5_reverse(ofstream& file, List::Node* tail)
{
    if (tail == nullptr) return;
    file << "Name: " << tail->student.name 
        << "Surname: " << tail->student.surname
        << "Money: " << tail->student.money << endl;
    help_for_function_5_reverse(file, tail->prev);
}

List::List()
    : head(nullptr), tail(nullptr)
{ }

List::~List()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    
}

void List::add(const Student& student)
{
    Node* newNode = new Node(student);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void List::Show()
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << "Name: " << current->student.name;
        cout << "\tSurname: " << current->student.surname;
        cout << "\tMoney: " << current->student.money;
        cout << endl;
        current = current->next;
    }
    cout << endl;
}


void List::function_5(const string& filename)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cerr << "Error: (0_-) unable to open file for writing" << endl;
        return;
    }

    if (VARIANT % 2 == 0)
    {
        help_for_function_5(fout, head);
    }
    else
    {
        help_for_function_5_reverse(fout, tail);  
    }
    
    fout.close();
    cout << "Data written to " << filename << " successfully\n";
    
}
void List::function_6(const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Error: (0_-) unable to open file for reading" << endl;
        return;
    }
    cout << "\nData from : " << filename << endl << endl;
    string str;
    while (getline(fin, str))
    {
        cout << str << endl;
    }
    fin.close();
}
double function_1();
double **function_2(double &x);
double *function_3(double **tower);
List function_4(double *array);
string RandomeSurname();
string RandomeName();
void Delete(double **matrix);
void Delete(double *matrix);


int main()
{
    srand(time(NULL));
    const string filename = "live_coding.txt";

    double x = function_1();
    double **tower = function_2(x);
    double *array = function_3(tower);
    List student = function_4(array);
    student.Show();
    student.function_5(filename);
    student.function_6(filename);
    Delete(tower);
    Delete(array);
    return 0;
}

double function_1()
{
    double a, b, f;
    int c, d, e;

    cout << "Enter double a:\t";
    cin >> a;
    cout << "Enter double b:\t";
    cin >> b;
    cout << "Enter double f:\t";
    cin >> f;
    cout << "Enter int c:\t";
    cin >> c;
    cout << "Enter int d:\t";
    cin >> d;
    cout << "Enter int e:\t";
    cin >> e;

    double array[] {a, b, f, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e)};
    int size = sizeof(array[0]) / sizeof(double);

    // сортуємо масив бульбашкою
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 6 - 1; j > i; i--)
        {
            if (array[j] < array[j-1])
            {
                swap(array[j], array[j-1]);
            }
        }
    }

    // Записуємо 3 найбільші та 3 найменші значення
    double max_sum = array[3] + array[4] + array[5];
    double min_sum = array[0] + array[1] + array[2];
    double result = 0;

    if (max_sum > min_sum * 4)
    {
        result = max_sum + min_sum;
    }
    else if (max_sum > min_sum * 3)
    {
        result = max_sum / min_sum;
    }
    else if (max_sum > min_sum * 2)
    {
        result = max_sum * min_sum;
    }    

    return result / VARIANT;
}

double **function_2(double &x)
{
    double **matrix = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (x + VARIANT + j - i) * (rand() % 100 + 1);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    return matrix;
}

double *function_3(double **tower)
{
    double *array1 = new double[5];
    double *array2 = new double[5];

    // перший алгоритм
    for (int i = 0; i < 5; i++)
    {
        double min = tower[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (min > tower[j][i])
            {
                min = tower[j][i];
            }
        }
        array1[i] = min;
    }

    // другий алгоритм
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5 - 1; i++)
        {
            for (int j = 5 - 1; j > i; j--)
            {
                if (tower[j][k] < tower[j-1][k])
                {
                    swap(tower[j][k], tower[j - 1][k]);
                }
                
            }
            
        }
        array2[k] = tower[0][k];
    }
    
    // перевірка на співпадіння
    bool correct = true;
    for (int i = 0; i < 5; i++)
    {
        if (array1[i] != array2[i])
        {
            correct = false;
            break;
        }     
    }
    
    if (!correct)
    {
        cout << "Not similar!!!" << endl;
    }

    delete[] array2;
    return array1;
}

List function_4(double *array)
{
    int size = 5; // розмір масиву array
    List student;

    double min = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }   
    } 
    double max = array[0];
    for (int i = 0; i < size - 1; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }   
    } 

    student.add(Student(RandomeName(), RandomeSurname(), max));
    for (int i = 1; i < 6; i++)
    {
        student.add(Student(RandomeName(), RandomeSurname(), array[i-1] + array[i]));
    }
    student.add(Student(RandomeName(), RandomeSurname(), min));

    return student;
}

string RandomeSurname()
{
    string name[] {"Evelynn", "Roly", "Darleen", "Adelynn", "Kaysen", "Hal", "Talia"};
    return name[rand() % 6];
}

string RandomeName()
{
    string name[] {"Durward", "Eula", "Briony", "Alvina", "Luke", "Florrie", "Hollie"};
    return name[rand() % 6];
}

// Для видалення динамічого масиву  
void Delete(double **matrix)
{
    for (int i = 0; i < 5; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Delete(double *matrix)
{  
    delete[] matrix;
}


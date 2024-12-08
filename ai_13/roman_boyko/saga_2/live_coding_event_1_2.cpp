#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int variant = 64;
string filename = "students.txt";

struct Student
{
    string name;
    string surname;
    float money;
    Student(string fName = "", string lName = "", float money = 0.0) : name(fName), surname(lName), money(money) {};
};

struct Node
{
    Student data;
    Node *next;
    Node *prev;
    Node(Student st)
    {
        data = st;
        next = nullptr;
        prev = nullptr;
    }
};

float function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cout << "Enter values: ";
    cin >> a >> b >> c >> d >> e >> f;
    float matrix[6] = {a, b, static_cast<int>(c), static_cast<int>(d), static_cast<int>(e), static_cast<double>(f)};
    int size = 6;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (matrix[j] < matrix[j - 1])
            {
                swap(matrix[j], matrix[j - 1]);
            }
        }
    }
    float minSum = matrix[0] + matrix[1] + matrix[2];
    float maxSum = matrix[3] + matrix[4] + matrix[5];
    float res = 0;
    if (maxSum > minSum * 4)
    {
        res = maxSum + minSum;
    }
    else if (maxSum > minSum * 3)
    {
        res = maxSum / minSum;
    }
    else if (maxSum > minSum * 2)
    {
        res = maxSum * minSum;
    }
    float x = res / variant;
    cout << "x: " << x << endl;
    return x;
}

float **function_2(float &x)
{
    float **matrix = new float *[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new float[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + variant + j - i) * (rand() % 100);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

float *function_3(float **tower)
{
    float *arr1 = new float[5];
    float *arr2 = new float[5];
    for (int i = 0; i < 5; i++)
    {
        float minValue = tower[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (minValue > tower[j][i])
            {
                minValue = tower[j][i];
            }
        }
        arr1[i] = minValue;
    }

    for (int i = 0; i < 5; i++)
    {
        float values[5];
        for (int j = 0; j < 5; j++)
        {
            values[j] = tower[j][i];
        }
        sort(values, values + 5);
        arr2[i] = values[0];
    }

    bool isEqual = true;
    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] != arr2[i])
        {
            isEqual = false;
            break;
        }
    }
    if (isEqual)
    {
        cout << "Arrays are equal!" << endl;
    }
    else
    {
        cout << "Arrays are not equal!" << endl;
    }
    cout << "array 1: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narray 2: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }
    sort(arr1, arr1 + 5);
    cout << endl;
    return arr1;
}

Node *function_4(float *array)
{
    string firstNames[] = {"Roman", "Ivan", "Artem", "Nazar", "Markiian", "Bohdan", "Danylo"};
    string secondNames[] = {"Boyko", "Mikes", "Kobzar", "Nedosika", "Lytvyn", "Boder", "Kolbasiuk"};
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < 7; i++)
    {
        float money;
        string name = firstNames[i];
        string lastName = secondNames[i];
        if (i == 0)
        {
            money = array[4];
        }
        else if (i > 0 && i < 6)
        {
            money = array[i - 1];
        }
        else
        {
            money = array[0];
        }
        Student st(name, lastName, money);
        Node *newNode = new Node{st};
        if (!head)
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

    Node *cur = head;
    cout << "List of students:" << endl;
    while (cur)
    {
        cout << cur->data.name << " " << cur->data.surname << " has " << cur->data.money << " hryvnias" << endl;
        cur = cur->next;
    }
    return head;
}

void help_for_function_5(Node *tail, ofstream &fileStream);

void function_5(Node *students)
{
    ofstream fileStream(filename);
    if (!fileStream.is_open())
    {
        cout << "Error in accessing to the file!" << endl;
        return;
    }
    Node *cur = students;
    while (cur->next)
    {
        cur = cur->next;
    }
    help_for_function_5(cur, fileStream);
    fileStream.close();
    cout << "\nList is written succesfully!" << endl;
    ifstream fileOutStream(filename);
    if (!fileOutStream.is_open())
    {
        cout << "Error in accessing to the file!" << endl;
        return;
    }
    cout << "\nInformation from file: " << endl;
    string line;
    while (getline(fileOutStream, line))
    {
        cout << line << endl;
    }
    fileOutStream.close();
}

void help_for_function_5(Node *tail, ofstream &fileStream)
{
    if (!tail)
    {
        return;
    }
    fileStream << tail->data.name << " " << tail->data.surname << " has " << tail->data.money << " hryvnias" << endl;
    help_for_function_5(tail->prev, fileStream);
}

int main()
{
    srand(time(nullptr));
    float x = function_1();
    float **tower = function_2(x);
    float *array = function_3(tower);
    Node *students = function_4(array);
    function_5(students);
}
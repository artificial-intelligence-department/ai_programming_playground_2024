#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int VARIANT = 72;
const string FILE_NAME = "live_coding_home.txt";

double function_1()
{
    float a, b;
    int c, d, e;
    double f;
    cout << "Enter 2 floats, 3 ints and 1 double: ";
    cin >> a >> b >> c >> d >> e >> f;
    double arr[]{(double)a, (double)b, (double)c, (double)d, (double)e, f};
    sort(arr, arr + 6);
    double max_sum = 0, min_sum = 0;
    for (size_t i = 0; i < 3; i++)
    {
        min_sum += arr[i];
    }
    for (size_t i = 3; i < 6; i++)
    {
        max_sum += arr[i];
    }
    double result = 0;
    if (max_sum > min_sum * 4)
    {
        result = max_sum + min_sum;
    }
    else if (max_sum > min_sum * 3)
    {
        if (min_sum == 0)
        {
            cout << "Cant devide by zero, so i rotated the fraction\n";
            if (max_sum == 0)
            {
                cout << "Cant devide zero by zero, so the result is -1\n";
                result = -1;
            }
            else
            {
                result = 0;
            }
        }
        else
            result = max_sum / min_sum;
    }
    else if (max_sum > min_sum * 2)
    {
        result = max_sum * min_sum;
    }

    result /= VARIANT;
    cout << "The result of function_1 is " << result << endl;
    return result;
}

double **function_2(double &x)
{
    double **arr = new double *[5];
    for (size_t i = 0; i < 5; i++)
    {
        arr[i] = new double[5];
        for (size_t j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            arr[i][j] = (arr[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return arr;
}

double *function_3(double **arr)
{
    double *result1 = new double[5];
    double *result2 = new double[5];
    double min;
    for (size_t j = 0; j < 5; j++)
    {
        min = arr[0][j];
        for (size_t i = 0; i < 5; i++)
        {
            if (min > arr[i][j])
            {
                min = arr[i][j];
            }
        }
        result1[j] = min;
    }

    double *tmp = new double[5];

    for (size_t j = 0; j < 5; j++)
    {
        for (size_t i = 0; i < 5; i++)
        {
            tmp[i] = arr[i][j];
        }
        sort(tmp, tmp + 5);
        result2[j] = tmp[0];
        if (result2[j] != result1[j])
        {
            cout << "Results aren`t equal" << endl;
            break;
        }
    }

    delete[] result2;
    delete[] tmp;
    return result1;
}

struct Human
{
    string name;
    string surname;
    double balance;
    Human()
    {
        this->name = "";
        this->surname = "";
        this->balance = 0;
    }
    Human(string name, string surname, double balance)
    {
        this->name = name;
        this->surname = surname;
        this->balance = balance;
    }
};

struct Node
{
    Node *prev = nullptr;
    Node *next = nullptr;
    Human value;
    Node(Human value)
    {
        this->value = value;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    DoublyLinkedList(Human value)
    {
        head = new Node(value);
    }
    void pushFront(Human value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            return;
        }
        auto tmp = head;
        head = new Node(value);
        head->next = tmp;
        tmp->prev = head;
    }
    Human &operator[](unsigned int index)
    {
        auto tmp = head;
        unsigned int counter = 0;
        while (tmp->next != nullptr && counter != index)
        {
            counter++;
            tmp = tmp->next;
        }
        return tmp->value;
    }

    void print()
    {
        auto tmp = head;
        while (tmp->next != nullptr)
        {
            cout << "Name: " << tmp->value.name << " " << tmp->value.surname << " Balace: "
                 << tmp->value.balance << endl;
            tmp = tmp->next;
        }
        cout << "Name: " << tmp->value.name << " " << tmp->value.surname << " Balace: "
             << tmp->value.balance << endl;
    }
};

DoublyLinkedList function_4(double *arr)
{
    DoublyLinkedList list;
    list.pushFront(Human("name7", "surname7", 0));
    list.pushFront(Human("name6", "surname6", 0));
    list.pushFront(Human("name5", "surname5", 0));
    list.pushFront(Human("name4", "surname4", 0));
    list.pushFront(Human("name3", "surname3", 0));
    list.pushFront(Human("name2", "surname2", 0));
    list.pushFront(Human("name1", "surname1", 0));
    double max = arr[0];
    double min = arr[0];
    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
        list[i + 1].balance = arr[i] + (i == 4 ? 0 : arr[i + 1]);
    }
    list[0].balance = max;
    list[6].balance = min;
    list.print();
    return list;
}

void help_for_function_5(ofstream &file, DoublyLinkedList &list, int index)
{
    if (index == -1)
    {
        return;
    }
    file << list[index].name << " " << list[index].surname << " "
         << list[index].balance << endl;
    help_for_function_5(file, list, index - 1);
}

void help_for_function_5(ofstream &file, DoublyLinkedList &list)
{
    for (size_t i = 0; i < 7; i++)
    {
        file << list[i].name << " " << list[i].surname << " "
             << list[i].balance << endl;
    }
}

void function_5(DoublyLinkedList &list)
{
    ofstream fileOut(FILE_NAME);
    if (!fileOut.is_open())
    {
        cout << "Error: cant open the file!";
        return;
    }

    if (VARIANT % 2 == 0)
    {
        help_for_function_5(fileOut, list, 6);
    }
    else
    {
        help_for_function_5(fileOut, list);
    }

    fileOut.close();

    ifstream fileIn(FILE_NAME);
    if (!fileIn.is_open())
    {
        cout << "Error: cant open the file!";
        return;
    }
    string data;
    int count = 1;
    while (fileIn >> data)
    {
        cout << data << " ";
        if (count % 3 == 0)
        {
            cout << endl;
        }
        count++;
    }

    fileIn.close();
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *arr = function_3(tower);
    DoublyLinkedList list = function_4(arr);
    function_5(list);

    for (size_t i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete[] tower;
    return 0;
}
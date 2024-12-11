#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

const int var = 46.0;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
struct Student
{
    string name;
    string surname;
    double money;
    Student(string name, string surname, double money) : name(name), surname(surname), money(money) {};
};
struct Node
{
    Student data;
    Node *next;
    Node *prev;
    Node(const Student &data) : data(data), prev(nullptr), next(nullptr) {};
};
class List
{
    // private:
public:
    Node *tail;
    Node *head;
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~List()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;

            delete current;
            current = next;
        }
    }
    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                cout << current->data.name << " " << current->data.surname << "  Money:" << current->data.money << endl;
                current = current->next;
            }
        }
    }
    void pushBack(const Student &student)
    {
        Node *newNode = new Node(student);
        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void help_for_function5(ofstream &file, Node *current)
    {

        if (current == nullptr)
        {
            return;
        }
        file << current->data.name << current->data.surname << " money: " << current->data.money << endl;

        return help_for_function5(file, current->prev);
    };
    void help_for_function5(ofstream &file, Node *current, int num)
    {
        for (int i = 0; i < num; i++)
        {
            file << current->data.name << current->data.surname << " money: " << current->data.money << endl;
            current = current->next;
        }
    };
};
double function1()
{
    float a, b;
    double f;
    int c, d, e;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    int maxInt = 0;
    double arr[6] = {a, b, c, d, e, f};
    double min[3] = {};
    double max[3] = {};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        min[i] = arr[i];
    }
    for (int i = 0; i < 3; i++)
    {
        max[i] = arr[i + 3];
    }

    double sumMin = min[0] + min[1] + min[2];
    double sumMax = max[0] + max[1] + max[2];

    double mult;
    if (sumMax > sumMin * 2)
    {
        mult = sumMax * sumMin;
    }
    else if (sumMax > sumMin * 3)
    {
        mult = sumMax / sumMin;
    }
    else if (sumMax > sumMin * 4)
    {
        mult = sumMax + sumMin;
    }
    double x = mult / var;
    cout << x;

    return x;
}

double **function2(double &x)
{
    double **arr = new double *[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = new double[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (arr[i][j] + var + j - i) * getRandomNumber(1, 100);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return arr;
}

double *function3(double **tower)
{
    double *arr = new double[5];
    double *compareArray = new double[5];
    for (int i = 0; i < 5; i++)
    {
        double min = 9999999.9;

        for (int j = 0; j < 5; j++)
        {
            if (tower[i][j] <= min)
            {
                min = tower[i][j];
            }
        }
        arr[i] = min;
    }

    for (int i = 0; i < 5; i++)
    {

        for (int k = 0; k < 4; k++)
        {
            if (tower[i][k] < tower[i][k + 1])
            {
                swap(tower[i][k], tower[i][k + 1]);
            }
        }

        compareArray[i] = tower[i][4];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << compareArray[i] << " ";
    }
    int count = 0;

    for (int i = 0; i < count; i++)
    {
        if (arr[count] == compareArray[count])
        {
            continue;
        }
        else
        {
            cout << "THEY ARE NOT EQUAL" << endl;
            break;
        }
    };
    return arr;
};

List function4(double *arr)
{
    cout << endl;

    List list;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            list.pushBack(Student("Al", "Aq", arr[4]));
        }
        else if (i > 0 && i <= 5)
        {
            list.pushBack(Student("Al", "Aq", arr[i - 1] + arr[i]));
        }
        if (i == 6)
        {
            list.pushBack(Student("as", "sdf", arr[0]));
        }
    }
    list.printList();
    return list;
};

void function5(List list)
{
    ofstream file("test.txt");

    if (!file.is_open())
    {
        cout << "FAIL" << endl;
    }
    if (var + 1 % 2 == 0)
    {
        Node *current = list.tail;
        list.help_for_function5(file, current);
    }
    else
    {
        Node *current = list.head;
        list.help_for_function5(file, current, 7);
    }

    char line[100];
    ifstream file1("test.txt");
    if (!file1.is_open())
    {
        cout << "FAIL" << endl;
        return;
    }
    while (file1.getline(line, 100))
    {
        cout << line << endl;
    }

    file.close();
    file1.close();
};

int main()
{

    double x = function1();
    double **tower = function2(x);
    double *arr = function3(tower);

    function5(function4(arr));

    return 0;
}
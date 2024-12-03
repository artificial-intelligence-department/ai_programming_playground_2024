#include <iostream>
#include <fstream>

using namespace std;

const int VARIANT = 72;

double sumArray(double arr[], int n)
{
    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

double function_1()
{

    float a, b;
    int c, d, e;
    double f;
    cout << "Enter the 2 floats, 3 integers and 1 double values: ";
    cin >> a >> b >> c >> d >> e >> f;
    double numbers[6];
    numbers[0] = a;
    numbers[1] = b;
    numbers[2] = c;
    numbers[3] = d;
    numbers[4] = e;
    numbers[5] = f;

    double maxNumbers[3];
    double minNumbers[3];

    int k = 0, l = 0;
    for (int i = 0; i < 6; i++)
    {
        double maxNumber = INT_MIN;
        for (int j = 0; j < 6; j++)
        {
            if (numbers[j] > maxNumber)
            {
                maxNumber = numbers[j];
            }
        }
        if (k < 3)
        {
            maxNumbers[k++] = maxNumber;
        }
        else
        {
            minNumbers[l++] = maxNumber;
        }
        for (size_t m = 0; m < 6; m++)
        {
            if (numbers[m] == maxNumber)
            {
                numbers[m] = INT_MIN;
                break;
            }
        }
    }

    double result;

    double maxSum = sumArray(maxNumbers, 3);
    double minSum = sumArray(minNumbers, 3);
    if (maxSum > minSum * 2)
    {
        result = maxSum * minSum;
    }
    else if (maxSum > minSum * 3)
    {
        if (minSum != 0)
        {
            result = maxSum / minSum;
        }
        else if (maxSum != 0)
        {
            result = minSum / maxSum;
        }
        else
        {
            result = 1;
        }
    }
    else if (maxSum > minSum * 4)
    {
        result = maxSum + minSum;
    }

    result /= VARIANT;
    cout << "Calculations in function_1 results: " << result << endl;
    return result;
}

double **function_2(const double &x)
{
    double **matrix = new double *[5];
    for (size_t i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
        for (size_t j = 0; j < 5; j++)
        {
            matrix[i][j] = x;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            matrix[i][j] = (x + VARIANT + j - i) * (1 + (rand() % 100));
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return matrix;
}

double *function_3(double **matrix)
{
    double *arr = new double[5];
    for (size_t i = 0; i < 5; i++)
    {
        double min = matrix[i][0];
        for (size_t j = 0; j < 5; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
        arr[i] = min;
    }

    bool isSameResults = true;

    for (size_t a = 0; a < 5; a++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (matrix[a][j] > matrix[a][j + 1])
                {
                    swap(matrix[a][j], matrix[a][j + 1]);
                }
            }
        }
        if (arr[a] != matrix[a][0])
        {
            isSameResults = false;
        }
        arr[a] = matrix[a][0];
    }
    cout << (isSameResults ? "Results in function_3 are the same" : "Results in function_3 are different") << endl;
    return arr;
}

struct Student
{
    string name;
    string surname;
    double balance;
    Student(string name, string surname, double balance)
    {
        this->name = name;
        this->surname = surname;
        this->balance = balance;
    }
};

struct Node
{
    Student key;
    Node *prev;
    Node *next;

    Node(Student k) : key(k), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    DoublyLinkedList(Student key)
    {
        Node *newNode = new Node(key);
        head = tail = newNode;
    }

    void addElement(Student key, int position)
    {
        Node *newNode = new Node(key);
        if (position <= 0)
        {
            std::cerr << "Invalid position.\n";
            delete newNode;
            return;
        }

        if (position == 1)
        {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (!tail)
                tail = head;
        }
        else
        {
            Node *temp = head;
            int i = 1;
            while (temp && i < position - 1)
            {
                temp = temp->next;
                i++;
            }

            if (!temp)
            {
                std::cerr << "Position out of range.\n";
                delete newNode;
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;

            if (newNode->next == nullptr)
                tail = newNode;
        }
    }

    Student *getElement(int index)
    {
        Node *current = head;
        for (size_t i = 0; i < index; i++)
        {
            current = current->next;
        }
        return &current->key;
    }

    void printList() const
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->key.name << " " << temp->key.surname << " Balance: " << temp->key.balance << "$\n";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void clearList()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        clearList();
    }
};

DoublyLinkedList function_4(double *arr)
{
    DoublyLinkedList list;
    list.addElement(Student("Name1", "Surname1", 0), 1);
    list.addElement(Student("Name2", "Surname2", 0), 2);
    list.addElement(Student("Name3", "Surname3", 0), 3);
    list.addElement(Student("Name4", "Surname4", 0), 4);
    list.addElement(Student("Name5", "Surname5", 0), 5);
    list.addElement(Student("Name6", "Surname6", 0), 6);
    list.addElement(Student("Name7", "Surname7", 0), 7);

    double max = arr[0], min = arr[0];
    for (size_t i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
        list.getElement(i + 1)->balance = arr[i] + (i == 4 ? 0 : arr[i + 1]);
    }
    list.getElement(0)->balance = max;
    list.getElement(6)->balance = min;
    list.printList();
    return list;
}

void help_for_function_5(const std::string &filename, DoublyLinkedList &elements, int index)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Unable to open file.\n";
        return;
    }
        Student* temp = elements.getElement(index);
        file << temp->name << " " << temp->surname << " Balance: " << temp->balance << "$\n";
    
    file.close();
    help_for_function_5(filename,elements,index-1);
}

void function_5(DoublyLinkedList &elements)
{
    help_for_function_5("file_for_saga",elements,6);
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *arr = function_3(tower);
    DoublyLinkedList list = function_4(arr);

    for (size_t i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete[] tower;
    delete[] arr;

    return 0;
}
// variant 68

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#define VARIANT 68

struct Student
{
    std::string name;
    std::string surname;
    double money;
    Student()
    {
    }
    Student(std::string name, std::string surname, double money)
    {
        this->name = name;
        this->surname = surname;
        this->money = money;
    }
};

class Node
{
  public:
    Student data;
    Node *next;
    Node *prev;
    Node(Student stud)
    {
        this->data = stud;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

double function_1();
double **function_2(float &x);
void function_3(double **tower, double col_final[5]);
Node *function_4(double arr[5]);
void function_5(Node *head);
void function_6();

int main()
{
    float x = function_1();
    double **tower = function_2(x);
    double arr[5];
    function_3(tower, arr);
    // for (auto el : arr)
    // {
    //     std::cout << el << " ";
    // }
    // std::cout << '\n';
    Node *head = function_4(arr);
    function_5(head);
    function_6();
}

double function_1()
{
    float a, b;
    std::cout << "enter float nums a b: ";
    std::cin >> a >> b;
    int c, d, e;
    std::cout << "enter int nums c d e: ";
    std::cin >> c >> d >> e;
    double f;
    std::cout << "enter double f: ";
    std::cin >> f;
    double nums[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    std::sort(nums, nums + 6);
    double big_sum = nums[5] + nums[4] + nums[3];
    double small_sum = nums[0] + nums[1] + nums[2];
    if (big_sum > small_sum * 4)
    {
        return big_sum + small_sum;
    }
    else if (big_sum > small_sum * 3)
    {
        return big_sum / small_sum;
    }
    else if (big_sum > small_sum * 2)
    {
        return big_sum * small_sum;
    }
    return 0;
}

double **function_2(float &x)
{
    double **arr = new double *[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = new double[5];
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = (x + VARIANT + j - i) * (1 + rand() % 100);
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return arr;
}

void transpose(double **mat, double res[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            res[j][i] = mat[i][j];
        }
    }
}

void function_3(double **tower, double col_final[5])
{
    double col_1[5];
    double col_2[5];
    for (int i = 0; i < 5; i++)
    {
        double smallest = std::numeric_limits<double>::max();
        for (int j = 0; j < 5; j++)
        {
            if (tower[j][i] < smallest)
            {
                smallest = tower[j][i];
                col_1[i] = smallest;
            }
        }
    }
    double temp[5][5];
    transpose(tower, temp);
    for (int i = 0; i < 5; i++)
    {
        col_2[i] = *std::min_element(temp[i], temp[i] + 5);
    }
    for (int i = 0; i < 5; i++)
    {
        if (col_1[i] != col_2[i])
        {
            std::cerr << "invalid algorithm" << '\n';
            return;
        }
        col_final[i] = col_2[i];
    }
    std::cout << "algorithms are valid" << '\n';
}

void insert(Node *&head, Student stud)
{
    Node *newNode = new Node(stud);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data.name << " " << temp->data.surname << " " << temp->data.money << "\n";
        temp = temp->next;
    }
}

Node *function_4(double arr[5])
{
    Student s1("1n", "1s", arr[0]);
    Student s2("2n", "2s", arr[0]); // я не викупив шо таке послідовні суми чи як там було, тому отак буде
    Student s3("3n", "3s", arr[0] + arr[1]);
    Student s4("4n", "4s", arr[0] + arr[1] + arr[2]);
    Student s5("5n", "5s", arr[0] + arr[1] + arr[2] + arr[3]);
    Student s6("6n", "6s", arr[0] + arr[1] + arr[2] + arr[3] + arr[4]);
    Student s7("7n", "7s", arr[4]);
    Node *head = nullptr;
    insert(head, s1);
    insert(head, s2);
    insert(head, s3);
    insert(head, s4);
    insert(head, s5);
    insert(head, s6);
    insert(head, s7);
    printList(head);
    return head;
}

void help_for_function_5(bool isOdd) // непарний варіант
{
    std::cout << "what are you doing here?" << '\n';
}
std::string help_for_function_5(std::string s) // парний варіант
{
    if (s.length() == 0)
    {
        return "";
    }
    std::string last(1, s[s.length() - 1]);
    std::string reversed = help_for_function_5(s.substr(0, s.length() - 1));
    return last + reversed;
}

void function_5(Node *head)
{
    std::ofstream myFile("func5file.txt");
    if (!myFile.is_open())
    {
        std::cerr << "cant open file for writing" << '\n';
        return;
    }
    bool isOdd = 1;
    if (VARIANT % 2 == 0)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            myFile << help_for_function_5(temp->data.name) << " " << help_for_function_5(temp->data.surname) << " "
                   << help_for_function_5(std::to_string(temp->data.money)) << '\n';
            temp = temp->prev;
        }
        myFile << '\n';
    }
    else
    {
        help_for_function_5(isOdd);
    }
    myFile.close();
    if (myFile.is_open())
    {
        std::cerr << "cant close the file" << '\n';
        return;
    }
}

void function_6()
{
    std::ifstream myFile("func5file.txt");
    if (!myFile.is_open())
    {
        std::cerr << "cant open file" << '\n';
        return;
    }
    std::string myText;

    while (getline(myFile, myText))
    {
        std::cout << myText << '\n';
    }
    myFile.close();
    if (myFile.is_open())
    {
        std::cerr << "cant close the file" << '\n';
    }
}

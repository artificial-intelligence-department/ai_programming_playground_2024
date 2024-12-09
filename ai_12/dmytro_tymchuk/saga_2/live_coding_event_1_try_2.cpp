#include<iostream>
#include<algorithm>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;
const int VARIANT = 55;

struct Student
{
    string first_name;
    string last_name;
    double money;

    Student(): first_name(" "), last_name(" "), money(0.0){};
};

struct Node
{
    Student data;
    Node* next;
    Node* prev;
    Node(): next(nullptr), prev(nullptr){};
};

struct double_linked_list
{    
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    //Додавання елемента в кінець
    void push_back(string first_name, string last_name, double money)
    {
        size ++;
        Node* new_node = new Node;
        new_node->data.first_name = first_name;
        new_node->data.last_name = last_name;
        new_node->data.money = money;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    //Виведення списку
    void ptint_list()
    {
        if (head == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }

        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout<<"\nStudent #"<<i<<endl;
            cout<<"First name: "<<current->data.first_name<<endl;
            cout<<"Last name: "<<current->data.last_name<<endl;
            cout<<"Money: "<<current->data.money<<endl;

            i++;
            current = current->next;
        }
    }

    
    void help_for_function_5(ofstream &out)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            out<<"Student #"<<i<<endl;
            out<<"First name: "<<current->data.first_name<<endl;
            out<<"Last name: "<<current->data.last_name<<endl;
            out<<"Money: "<<current->data.money<<endl<<endl;

            i++;
            current = current->next;
        }
    }

    void help_for_function_5(ofstream &out, Node* current, int current_number)
    {
        if (current == nullptr)
        {
            return;
        }

        out<<"Student #"<<current_number<<endl;
        out<<"First name: "<<current->data.first_name<<endl;
        out<<"Last name: "<<current->data.last_name<<endl;
        out<<"Money: "<<current->data.money<<endl<<endl;

        return help_for_function_5(out, current->prev, current_number - 1);
    }
};


double function_1()
{
    float c1, c2;
    int c3, c4, c5;
    double c6;

    cin>>c1>>c2;
    cin>>c3>>c4>>c5;
    cin>>c6;

    double arr[6]{(double)c1, (double)c2, (double)c3, (double)c4, (double)c5, c6};
    sort(arr, arr + 6);

    double sum_max = 0, sum_min = 0;
    sum_max = arr[3] + arr[4] + arr[5];
    sum_min = arr[0] + arr[1] + arr[2];

    double x = 0;
    if (sum_max > sum_min * 4) x = sum_max + sum_min;
    else if (sum_max > sum_min * 3) x = sum_max / sum_min;
    else if (sum_max > sum_min * 2) x = sum_max * sum_min;

    x /= VARIANT;
    cout<<"x = "<< x <<endl;
    return x;
}

double** function_2 (double &x)
{
    srand(time(0));
    double** matrix = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5]{x, x, x, x, x};
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }
    
    cout<<"\nMatrix: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return matrix;
}

double* function_3(double** tower)
{
    double* min_elements_in_columns = new double[5]{};

    for (int i = 0; i < 5; i++)
    {
        double column[5]{};

        double min_in_column = tower[0][i];
        for (int j = 0; j < 5; j++)
        {
            if (min_in_column > tower[j][i]) min_in_column = tower[j][i];

            column[j] = tower[j][i];
        }
        
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5 - j - 1; k++)
            {
                if (column[k] > column[k + 1])
                {
                    int tmp = column[k];
                    column[k] = column[k + 1];
                    column[k + 1] = tmp;
                }
            }
        }
        
        if (column[0] == min_in_column) printf("\nMin elements in column %d are equal\n", i + 1);
        printf("Min element in column %d is: %.3lf\n", i + 1, min_in_column);

        min_elements_in_columns[i] = min_in_column;
    }
    
    return min_elements_in_columns;
}

double_linked_list function_4(double* min_elements_in_columns)
{
    double_linked_list students;
    sort(min_elements_in_columns, min_elements_in_columns + 5);

    double sum = 0.0;
    for (int i = 0; i < 5; i++)
    {
        sum += min_elements_in_columns[i];
    }
    
    students.push_back("First name 1", "Last name 1", min_elements_in_columns[4]);

    students.push_back("First name 2", "Last name 2", sum);
    students.push_back("First name 3", "Last name 3", sum);
    students.push_back("First name 4", "Last name 4", sum);
    students.push_back("First name 5", "Last name 5", sum);
    students.push_back("First name 6", "Last name 6", sum);

    students.push_back("First name 7", "Last name 7", min_elements_in_columns[0]);

    students.ptint_list();

    return students;
}

void function_5(double_linked_list students, string file_name)
{
    ofstream out(file_name);
    if (!out.is_open())
    {
        cout<<"File isn`t open"<<endl;
        return;
    }

    if (VARIANT % 2 == 1) students.help_for_function_5(out);
    else students.help_for_function_5(out, students.tail, students.size);

    out.close();
}

void function_6(string file_name)
{
    ifstream in(file_name);
    if (!in.is_open())
    {
        cout<<"File isn't open"<<endl;
        return;
    }

    cout<<"\nList of students from file: "<<endl;

    string line;
    while (getline(in, line))
    {
        cout<<line<<endl;
    }

    in.close();
}
int main()
{
    string file_name = "Students.txt";
    double x;
    x = function_1();

    double** tower = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        tower[i] = new double[5];
    }
    tower = function_2(x);

    double* min_elements_in_columns = new double[5]{};
    min_elements_in_columns = function_3(tower);

    double_linked_list students;
    students = function_4(min_elements_in_columns);

    function_5(students, file_name);

    function_6(file_name);
    return 0;
}
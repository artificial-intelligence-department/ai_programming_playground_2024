#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

const int variant = 24;
//використано свою структуру даних
struct Node
{
    string first_name;
    string last_name;
    double balance;
    Node* prev;
    Node* next;    
};

double function_1()
{
    float a,b;
    //дійсна змінна
    int c,d,e;
    //цілочисельна змінна
    double f;
    // дійсна з подвійною точністю змінна
    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;
    //одновимірний масив
    double arr[6]={(double) a,(double) b, (double) c, (double) d, (double)e, f};
    //for цикл
    for (int i = 0; i<6; i++)
    {
        bool changed = 0;
        for (int j =0; j<5; j++)
        {
            if (arr[j]> arr[j+1])
            {
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                changed=1;
            }
        }
        if (!changed)
        {
            break;
            //оператори break, щоб зупинити цикл
        }
    }
    double sum_min = arr[0] + arr[1] + arr[2];
    double sum_max = arr[3] + arr[4] + arr[5];
    double x;
    if (sum_max > sum_min*4)
    {
        x = sum_max+sum_min;
    } 
    else  if (sum_max>sum_min*3)
    {
        x = sum_max/sum_min;
    }
    else if (sum_max > sum_min * 2)
    {
        x = sum_max*sum_min;
    }
    x/=variant;
    cout << "Answer for first question is "<< x << endl;
    return x;
}

double** function_2(double* x)
{
    double** matrix =  new double* [5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double [5];
    } 
    //використаний двовимірний масив
    for (int  i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = *x;
        }
    }
    for (int  i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j]+i-j)*(rand()%100+1);
        }
    }
    cout << "Answer for second question is " << endl;
    for (int  i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j]<< " "; 
        }
        cout << endl;
    }
    return matrix;
}

double* function_3 (double** tower)
{
    double* arr = new double[5];
    
    double min_element_1[5];
    double min_element_2[5];

    for (int i = 0; i < 5; i++)
    {
        min_element_1[i]=tower[0][i];
        for (int j = 0; j<5; j++)
        {
            if (tower[j][i]<min_element_1[i])
            {
                min_element_1[i] = tower[j][i];
            } 
        }
    } 
    
    for (int col = 0; col < 5; col++)
    {
        double column[5];
        for (int row = 0; row < 5; row++)
        {
            column[row]= tower[row][col];
        }
        for (int i = 0; i<5; i++)
        {
            for (int j = i+1; j<5; j++)
            {
                if (column[i]> column[j])
                {
                    double temp = column[i];
                    column[i]=column[j];
                    column[j]=temp;
                }
            }
        }
        min_element_2[col]=column[0];
    } 
    bool are_equal=1;
    for (int i=0; i<5; i++)
    {
        if (min_element_1[i] !=min_element_2[i])
        {
            are_equal = 0;
            break;
        }
    }
    if (are_equal)
    {
        cout << "Answer for third question is YES" << endl;
    }
    
    for (int i=0; i<5; i++)
    {
        arr[i] = min_element_1[i];
    }
    return arr;
}
Node* createNode(string first_name, string last_name, double balance)
{
    Node* newnode = new Node;
    newnode->first_name =first_name;
    newnode->last_name =last_name;
    newnode->balance = balance;
    newnode->prev = nullptr;
    newnode->next = nullptr;
    return newnode;       
}

Node* function_4(double* arr)
{
    string first_names[] = {"Oleh","Ivan", "Maria-Anastasia", "Bohdan", "Yevheniy","Volodymyr","Anastasia"};
    string last_names[] = {"Stanko","Holeychuk", "Kupchak", "Saukh", "Yedynets","Lopatyn","Humeniuk"};
    Node* head = nullptr;
    Node* tail = nullptr;

    double max_balance=arr[0];
    double min_balance=arr[0];

    for (int i=0; i<5; i++)
    {
        if (arr[i]> max_balance)
        {
            max_balance=arr[i];
        }
        if (arr[i]< min_balance)
        {
            min_balance=arr[i];
        }        
    }
    for (int i = 0; i < 7; i++)
    {
        string first_name = first_names[i];
        string last_name = last_names[i];
        double balance;
        if (i == 0)
        {
            balance=max_balance;
        }
        else if (i==6)
        {
            balance = min_balance;
        }
        else
        {
            balance = arr[i-1]+ arr[i];
        }
        Node* newnode = createNode(first_name, last_name, balance);
        
        if (head == nullptr)
        {
            head = newnode;
            tail=newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    Node* temp = head;
    cout << "Answer for fourth question is " << endl;
    while (temp!= nullptr)
    {
        cout << temp->first_name << " " << temp->last_name << " " << temp->balance << endl;
        temp = temp -> next;        
    }
    return head;
}

void help_for_function_5(Node* node, ofstream& file)
{
    if (node == nullptr)
    {
        return;
    }
    // рекурсивна функція
    help_for_function_5(node->next, file);
    file << node->first_name << " " << node->last_name << " " << node->balance << endl;
}
//перевантаження функції
void help_for_function_5(Node* head, ofstream& file, bool)
{
    Node* curent = head; 
    do
    {
        file << head->first_name << " " << head->last_name << " " << head->balance << endl;        
    } while (curent != nullptr);
}
void function_5(Node* head)
{
    //функції роботи з файлами, для того, щоб записати у файл
    ofstream file("students.txt");
    if (!file.is_open())
    {
        cerr << "Error: could not open the file" << endl;
        return;
    }
    if (variant%2 == 0)
    {
        help_for_function_5(head, file);
    }
    else
    {
        help_for_function_5(head, file,true);
    }
    file.close();
    ifstream file2("students.txt");
    //функції роботи з файлами, для того, щоб зчитати з файлу
    if (!file2.is_open())
    {
        cerr << "Error: could not open the file" << endl;
        return;
    }
    cout << "Answer for sixth question is " << endl;
    string line;
    while (getline(file2,line))
    {
        cout << line << endl;
    }
    file.close();
    
}
int main()
{
    double x = function_1();
    double** tower = function_2(&x);
    //вказівник
    double* arr = function_3(tower);
    Node* head = function_4(arr);
    function_5(head);
}
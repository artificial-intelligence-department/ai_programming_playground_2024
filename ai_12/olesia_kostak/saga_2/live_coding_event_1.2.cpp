#include <iostream>
#include <cstdlib> //for random
#include <limits> //for max value
#include <cmath> //for fabs
#include <algorithm> //for sort 
#include <sstream>
#include <fstream>

const int VAR = 39; //using const int variable
const int SIZE = 5;
const char* filename = "file.txt";
float function_1();
float** function_2(float &x);
float* function_3(float** tower);
void print_arr(float* arr, int size, int start);


struct Student //using struct
{
    std::string name;
    std::string surname;
    float balance;
};

class LinkedList
{
private:
    struct Node
    {
        Student data;
        Node* previous;
        Node* next;

        Node (Student val)
        {
            data = val;
            next = nullptr;
            previous = nullptr;
        }
    };
    Node* head = nullptr; 
    Node* tail = nullptr;
    int size = 0;
    
public:
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }
    void insert(Student value)
    {
        Node* new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
            size++;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = new_node;
        new_node->previous = current;
        size++;
    }

    void print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data.name << " " << current->data.surname << " " << current->data.balance << " ";
            current = current->next;
            std::cout << std::endl;
        }
    }

    void help_for_function_5()
    {
        std::ofstream myfile(filename); //to write in a file
        if(myfile.is_open())
        {
            Node* current = head;
            while (current != nullptr)
            {
                myfile << " " << current->data.name << " " << current->data.surname << " " << current->data.balance << std::endl; 
                current = current->next;
            }
            myfile.close();
            std::cout << std::endl;
        }
    }
    //     FILE* fptr = fopen(filename, "w");
    //     if (fptr == nullptr)
    //     {
    //         perror("Error opening file");
    //         exit(1);
    //     }
    //     Node* current = head;
    //     while (current != nullptr)
    //     {
    //         fprintf(fptr, "%s %s %f\n", current->data.name, current->data.surname, current->data.balance);
    //         current = current->next;
    //     }
    //     fclose(fptr);
    //     std::cout << std::endl;
    // }
};

LinkedList function_4(float* arr); 
void fucntion_5(LinkedList lst);
void fucntion_5();

//do not forget to delete arrays!!!!!!!!!!!!!

int main()
{
    float x = function_1();
    std::cout << std::endl; //using output operator
    float** tower = function_2(x); //using pointers
    std::cout << std::endl;
    float* arr = function_3(tower);
    print_arr (arr, SIZE, 0);
    std::cout << std::endl;
    LinkedList lst = function_4(arr);
    std::cout << std::endl;
    fucntion_5(lst);
    fucntion_5();
    return 0;
}

float function_1()
{
    float a, b; //using float
    std::cin >> a >> b; //using input operator
    int c, d, e; //using integer
    std::cin >> c >> d >> e;
    double f; //using real variable with doble precision
    std::cin >> f;
    double arr[6] = {double(a), double(b), double(c), double(d), double(e), f};
    double min_values[3]; //using one-dimensional array
    double max_values[3];
    for (int i = 0; i < 6; i++) //buble sort
    {
        for (int j = 0; j < 6; j++) //using for loop
        {
            if (arr[j] < arr[j - 1]) //using operators
            {
                double temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    double sum_max = 0;
    double sum_min = 0;
    double x = 0;
    for(int i = 0; i < 3; i++)
    {
        min_values[i] = arr[i];
        sum_min += arr[i];
    }
    //instead of for loop we can also use while:

    // int step = 0; 
    // while (step < 3)
    // {
    //     min_values[step] = arr[step];
    //     sum_min += arr[step];
    //     step++;
    // }
    
    //using bread and do while
    
    // int step = 0;
    // do
    // {
    //     min_values[step] = arr[step];
    //     sum_min += arr[step];
    //     step++;
    //     if (step > 3) break;
    // } while (true);
    

    for(int i = 0; i < 3; i++)
    {
        max_values[i] = arr[i + 3];
        sum_max += arr[i + 3];
    }
    if (sum_max > sum_min*2)
        x = sum_max * sum_min; //using math operators
    else if (sum_max > sum_min*3)
        x = sum_max / sum_min;
    else if (sum_max > sum_min*4)
        x = sum_max + sum_min;

    x /= double(VAR);
    x = float(x);
    std::cout << x;

    return x;

}

float** function_2(float &x) //using arguments of a fucntion
{
    int SIZE = 5;
    float** matr = new float*[SIZE]; //using two-dimensional array
    for (int i = 0; i < SIZE; i++)
    {
        matr[i] = new float[SIZE];
        for(int j = 0; j < SIZE; j++)
        {
            matr[i][j] = x;
        }
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matr[i][j] = (matr[i][j] + float(VAR) + float(j) - float(i)) * float(rand() % 101);
    
    //printing
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << matr[i][j] << " ";
        }    
        std::cout << std::endl;
    }
    return matr;
}

float* function_3(float** tower)
{
    int SIZE = 5;
    float* arr_1 = new float[SIZE];
    // 1 way
    for (int i = 0; i < SIZE; i++)
    {
        float min_col = std::numeric_limits<float>::max();
        for (int j = 0; j < SIZE; j++)
        {
            if (tower[j][i] < min_col)
                min_col = tower[j][i];
        }
        arr_1[i] = min_col;
    }
    // 2 way
        
    float arr_2[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        float temp_arr[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            temp_arr[j] = tower[j][i]; 
        }
        std::sort(temp_arr, temp_arr + SIZE);
        arr_2[i] = temp_arr[0];
    }

    //Check if both methods calculate in the same way
    bool flag = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (fabs(arr_1[i] - arr_2[i]) > 0.0001)
            flag = false;
    }
    if (flag)
        std::cout << "Both methods give the same result" << std::endl;
    else std::cout << "Both methods give different results" << std::endl;

    return arr_1;
}

LinkedList function_4(float* arr)
{
    std::sort(arr, arr + SIZE);

    LinkedList lst;
    Student student;
    student.name = "Olesia";
    student.surname = "Kostak";
    student.balance = arr[SIZE - 1];
    lst.insert(student);

    std::string names[5] = {"Sofi", "Julia", "Mike", "Jim", "Kate"};
    std::string surnames[5] = {"Buhai", "Lazar", "Bandera", "Melnik", "Dontsov"};

    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
        student.name = names[i];
        student.surname = surnames[i];
        student.balance = sum;
        lst.insert(student);
    }

    student.name = "Not Olesia";
    student.surname = "Not Kostak";
    student.balance = arr[0];
    lst.insert(student);

    lst.print();
    return lst;

}

void fucntion_5(LinkedList lst)
{
    lst.help_for_function_5();
}

void fucntion_5() //fucntion overloading
{
    std::ifstream myfile(filename); 
    if (myfile.is_open()) 
    {
        std::string buffer;
        while (getline(myfile, buffer)) //using functions to work with files (geting information)
        {
            Student student;
            std::istringstream iss(buffer);
            iss >> student.name >> student.surname >> student.balance;
            std::cout << student.name << " " << student.surname << " " << student.balance << std::endl;
        }
        myfile.close();
    }
    else
    {
        perror ("Error opening file");
        exit(1);
    }

}

void print_arr(float* arr, int size, int start) //using recursion
{
    if (start == size)
    {
        std::cout << std::endl;
        return;
    }
    std::cout << arr[start] << " ";
    print_arr(arr, size, start + 1);
}
#include<iostream>
#include<algorithm>
#include<string>
const double taskN = 40; // Варіант


struct Node
{
    public:
        Student val;
        Node* next;
        Node(Student val, Node* next)
        {
            this->val = val;
            this->next = next;
        }
    Node() { }
};

double function_1()
{
    double a,b;
    float c, d, e;
    double f;
    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;
    double nums[] = {a , b , c , d ,e , f};
    int n = sizeof(nums) / sizeof(nums[0]); 
    std::sort(nums, nums + n);

    double greaterNumsSum = 0 , lessNumsSum = 0;
    lessNumsSum = greaterNumsSum + nums[0] + nums[1] + nums[2];
    greaterNumsSum = lessNumsSum + nums[3] + nums[4] + nums[5];
    double result;
    if(greaterNumsSum > (lessNumsSum * 4))
    {
        result = lessNumsSum = greaterNumsSum;
    } else if (greaterNumsSum > (lessNumsSum * 3))
    {
        result = greaterNumsSum / lessNumsSum;
    } else if(greaterNumsSum > (lessNumsSum * 2))
    {
        result = greaterNumsSum * lessNumsSum;
    }

    result /= taskN;
    std::cout << "Result: " << result; 
    return result;

    
}


void printMatrixConsole(double** matrix)
{
    std::cout << std::endl;
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}


double** function_2(double& val)
{
    //Memmory allocation (Dynamic)
    double** matrix = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
    }

    
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = val;
        }
    }

    //Separate code block ;)
    srand(time(nullptr));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + taskN + j + i ) * (rand() % 101 + 1); // Not including 101 precisely
        }
    }

    printMatrixConsole(matrix);

    return matrix;
}


//Find min (each row // HERE // )
double minEl(double* array)
{
    double minElement = array[0];
    for (size_t i = 1; i < 5; i++)
    {
        if(array[i] < minElement)
            minElement = array[i];
    }
    return minElement;
}



void printArray(double* arr)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << ' ';
    }
    
}


//Student Struct
struct Student
{
    std::string name , surname;
    double balance;
    Student(std::string name, std::string surname, double balance)
    {
        this->name = name;
        this->surname = surname;
        this->balance = balance;
    }
};

void function_4(double* resArray)
{
    Student s1("Nazar", "Kryvychko", 20.00);
    Student s2("Taras", "Ivannyk", 37.79);
    Student s3("Stepan", "Kobula", 11.24);
    Student s4("Georgiy", "Vyxo", 17.88);
    Student s5("Bogdan", "Sosnulo", 18.22);
    Student s6("Stepan", "Shuika", 100.23);
    Student s7("Sergiy", "Tokaruk", 78.11);
    
    Node* headLL = new Node(s1, new Node(s2,new Node(s3,new Node(s4,new Node(s5,new Node(s6, new Node(s7,nullptr)))))));
}

double* function_3(double** tower)
{
    double* oneDimenArray = new double[5];
    double resultMinEl1[5] , resultMinEl2[5];
    for (int i = 0; i < 5; i++)
    {
        double minElementRow = tower[0][i];
        for (int j = 1; j < 5; j++)
        {
            if (tower[j][i] < minElementRow)
                minElementRow = tower[j][i];
        }
        resultMinEl1[i] = minElementRow;
    }


    for (int i = 0; i < 5; i++)
    {
        double columnArray[5];
        for (int j = 0; j < 5; j++)
        {
            columnArray[j] = tower[j][i];
        }
        resultMinEl2[i] = minEl(columnArray);
        
    }

    std::cout << "Array 1: " << std::endl;
    printArray(resultMinEl1);
    std::cout << std::endl;
    std::cout << "Array 2: " << std::endl;
    printArray(resultMinEl2);

    for (int i = 0; i < 5; i++)
    {
        if(resultMinEl1[i] != resultMinEl2[i])
        {
            std::cerr << "I am so bad at coding! Result are not equal!!1!1!" << std::endl;
            return resultMinEl1;
        }
    }
    std::cout << "Everything is Good!" << std::endl;
    
    

    delete oneDimenArray;

    return resultMinEl1;
    
}




int main(void)
{
    //Test for function_1
    double resXF1 = function_1();

    //Test for function_2
    double** tower = function_2(resXF1);

    //Task function_3
    double* resultF3 = function_3(tower);
    




    for (size_t i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete tower;
     
    return 0;
}
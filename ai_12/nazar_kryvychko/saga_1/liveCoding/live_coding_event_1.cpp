#include<iostream>
#include<algorithm>
#include<string>
#include <unistd.h>
#include<fstream>
const int taskN = 40; // Варіант


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
    Student() { }
};

std::string studentToString(Student student)
{
    return "[" + student.name + ", " + student.surname + ", " + std::to_string(student.balance) + "]"; 
}

struct Node
{
    public:
        Student val;
        Node* next;
        Node* prev;
        Node(Student val, Node* next, Node* prev)
        {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
};

double function_1()
{
    int value; // Цілочисельна змінна
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
        result = lessNumsSum + greaterNumsSum;
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


//Help Functions
double findMax(double* array, const size_t& size)
{
    if(array == nullptr) return 0.0; // Edge case
    double max = array[0];
    for (int i = 0; i < size; i++)
    {
        if(array[i] > max) max = array[i];
    }
    return max;
    
}

double findMin(double* array, const size_t& size)
{
    if(array == nullptr) return 0.0; // Edge case
    double min = array[0];
    for (int i = 0; i < size; i++)
    {
        if(array[i] < min) min = array[i];
    }
    return min;
}

double sum(double* array, const size_t& size)
{
    double acum = 0.0;
    for (size_t i = 0; i < size; i++)
    {
        acum += array[i];
    }
    return acum;
}


void printLL_console(Node* head)
{
    while(head)
    {
        std::cout << studentToString(head->val) << ' ';
        head = head->next;
    }
}


Node* function_4(double* resArray, const size_t& size)
{
    Student s1("Nazar", "Kryvychko", 20.00);
    Student s2("Taras", "Ivannyk", 37.79);
    Student s3("Stepan", "Kobula", 11.24);
    Student s4("Georgiy", "Vyxo", 17.88);
    Student s5("Bogdan", "Sosnulo", 18.22);
    Student s6("Stepan", "Shuika", 100.23);
    Student s7("Sergiy", "Tokaruk", 78.11);
    

    //Linked List xD
    Node* headLL = new Node(s1,nullptr,nullptr);
    headLL->next = new Node(s2,nullptr,headLL);
    headLL->next->next = new Node(s3, nullptr, headLL->next);
    headLL->next->next->next = new Node(s4, nullptr, headLL->next->next);
    headLL->next->next->next->next = new Node(s5, nullptr, headLL->next->next->next);
    headLL->next->next->next->next->next = new Node(s6, nullptr, headLL->next->next->next->next);
    headLL->next->next->next->next->next->next = new Node(s7, nullptr, headLL->next->next->next->next->next);
    


    size_t index = 0;
    Node* moveNode = headLL;
    double sumOfResArray = sum(resArray,size);
    while(moveNode)
    {
        // first Student
        if(index == 0)
            moveNode->val.balance = findMax(resArray,size);

        //last Student
        else if (moveNode->next == nullptr)
            moveNode->val.balance = findMin(resArray,size);

        // Middle Students
        else 
            moveNode->val.balance = sumOfResArray;

        moveNode = moveNode->next;
        index++;
    }


    printLL_console(headLL);

    return headLL;
}

// Regular
std::string help_for_function_5(Node* studentLL)
{
    std::string reversedStudents = ""; 
    while(studentLL)
    {
        std::string appendString = studentToString(studentLL->val).append(" ");
        reversedStudents.insert(0, appendString);
        studentLL = studentLL->next;
    }
    return reversedStudents;
}

//Recursive
std::string help_for_function_5(Node* studentLL, std::string middleBuffer)
{
    if(!studentLL) return middleBuffer;
    middleBuffer.insert(0, studentToString((studentLL->val)).append(" "));
    return help_for_function_5(studentLL->next,middleBuffer);
}


void function_5(Node* studentLL)
{
    //Regular 
    std::string studentsFileContent = help_for_function_5(studentLL);

    //Recursive
    std::string middleBuffer = "";
    std::string studentsFileContentRecursive = help_for_function_5(studentLL,middleBuffer);


    std::ofstream fileOut("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_1\\liveCoding\\file.txt");
    fileOut << studentsFileContentRecursive;

    fileOut.close();
}



//Task 6
void function_5()
{
    std::ifstream fileIn("C:\\IT\\Politex\\Epic_1\\src\\ai_programming_playground_2024\\ai_12\\nazar_kryvychko\\saga_1\\liveCoding\\file.txt");

    if(!fileIn.is_open())
        std::cerr << "We are in trouble xD" << std::endl;
    

    std::string readBuffer , tmp;
    while(std::getline(fileIn, tmp))
    { 
        std::cout << "Reading the file..." << std::endl;
        readBuffer += tmp;
        sleep(1);
    }

    std::cout << "File content: " << readBuffer  << std::endl;

    fileIn.close();
}




double* function_3(double** tower)
{
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

    double* returnArr = new double[5];
    for (size_t i = 0; i < 5; i++)
    {
        returnArr[i] = resultMinEl1[i];
    }
    

    for (int i = 0; i < 5; i++)
    {
        if(resultMinEl1[i] != resultMinEl2[i])
        {
            std::cerr << "I am so bad at coding! Result are not equal!!1!1!" << std::endl;
            return returnArr;
        }
    }
    std::cout << std::endl;
    std::cout << "Everything is Good!" << std::endl;
    

    


    return returnArr;
    
}




int main(void)
{
    //Test for function_1
    double resXF1 = function_1();

    //Test for function_2
    double** tower = function_2(resXF1);

    //Task function_3
    double* resultF3 = function_3(tower);
    
    Node* LinkedList = function_4(resultF3, 5);

    function_5(LinkedList);


    function_5();

    for (size_t i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete tower;
    

    int counter = 0;
    bool flag = true;
    // Do while loop
    do
    {
        if(counter < 0)
        {
            break;
        }
        if(counter == 3) flag = false;

        if(!flag)
        {
            flag = true;
            counter++;
            continue;
        }
        counter++;
        std::cout << "I want to join SoftServe so much!!! xD" << std::endl;
        
    } while (counter <= 5);
    




    // I'm done xD ))))
    // Node* saveStep = nullptr;
    // while(LinkedList)
    // {
    //     LinkedList = LinkedList->next;
    //     saveStep = LinkedList;
    //     delete saveStep;
    // }
     
    return 0;
}
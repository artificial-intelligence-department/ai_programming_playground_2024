#include <iostream>
#include <algorithm>
const int var=67; // 4. в коді використана як мінімум одна цілочисельна константа
struct student // 19. в коді використано свою структуру даних
{
    std::string name;
    std::string surname;
    float money;
};
struct Node
{
    float val;
    Node* next;
    Node* prev;
    Node(float value)
    {
        val=value;
        next=nullptr;
        prev=nullptr;
    }
};
float function_1()
{
    float a,b; // 2. в коді використана як мінімум одна дійсна змінна
    int c,d,e; // 1. в коді використана як мінімум одна цілочисельна змінна
    double f; // 3.  в коді використана як мінімум одна дійсний з подвійною точністю змінна
    std::cin >> a >> b;
    std::cin >> c >> d >> e; // 18. в коді використано оператори виведення та введення даних
    std::cin >> f;
    float maxs=0;
    float mins=0;
    double arr[6]={a,b,c,d,e,f};
    std::sort(arr, arr+6);
    maxs=arr[3]+arr[4]+arr[5];
    mins=arr[0]+arr[1]+arr[2];
    float result=0;
    if (maxs>(mins*2)) // в коді використані умовні оператори та розгалуження
    {
        result=maxs*mins;
    }
    else if (maxs>(mins*3))
    {
        result=maxs/mins;
    }
    else if (maxs>(mins*4))
    {
        result=maxs+mins;
    }
    result=result/float(var);
    std::cout << result << std::endl;
    return result;
}

float** function_2(float &x)  
{
    float **array=new float* [5]; // 20. в коді використано вказівники 
    // 7. в коді використаний двовимірний масив 
    for(int i=0; i<5; i++)
    {
        array[i]=new float [5];
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            array[i][j]=x;
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            array[i][j]=(array[i][j]+var+j-i)*(rand()%100+1);
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return array;
}

float* function_3(float** tower)
{
    float* array1=new float [5];
    float* array2=new float [5]; // 6. в коді використаний одновимірний масив 
    
    for(int i=0; i<5; i++) // 10. в коді використаний for цикл 
    {
        float min1=tower[i][0];
        for(int j=0; j<5; j++)
        {
            if(min1>tower[i][j])
            {
                min1=tower[i][j];
            }
        }
        array1[i]=min1;
    }
    bool temp=true;
    for(int i=0; i<5; i++)
    {
        if(array1[i]!=array2[i])
        {
            temp=false;
        }
    }
    for(int i=0; i<5; i++)
    {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    for(int i=0; i<5; i++)
    {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;
    if(temp)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    return array1;
}

void function_4(float* array)
{
    Node* head;
    head=nullptr;
    student stud1, stud2, stud3, stud4, stud5, stud6, stud7;
    stud1.name="a";
    stud2.name="a";
    stud3.name="a";
    stud4.name="a";
    stud5.name="a";
    stud6.name="a";
    stud7.name="a";
    stud1.surname="b";
    stud2.surname="b";
    stud3.surname="b";
    stud4.surname="b";
    stud5.surname="b";
    stud6.surname="b";
    stud7.surname="b";
}

int main()
{
    float x=function_1();
    float** tower=function_2(x);
    float* array=function_3(tower);
    function_4(array);
}

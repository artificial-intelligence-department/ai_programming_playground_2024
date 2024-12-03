#include <iostream>
#include <algorithm>
const int var=67;
struct student
{
    std::string name;
    std::string surname;
    float money;
}
float function_1()
{
    float a,b;
    int c,d,e;
    double f;
    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;
    float maxs=0;
    float mins=0;
    double arr[6]={a,b,c,d,e,f};
    std::sort(arr, arr+6);
    maxs=arr[3]+arr[4]+arr[5];
    mins=arr[0]+arr[1]+arr[2];
    float result=0;
    if (maxs>(mins*2))
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
    float **array=new float* [5];
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
    float* array2=new float [5];
    
    for(int i=0; i<5; i++)
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

int main()
{
    float x=function_1();
    float** tower=function_2(x);
    function_3(tower);
}

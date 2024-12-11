#include <iostream>
#include <algorithm>
#include <climits>
#include <fstream>
const int var=67;
float function_1()
{
    float a,b;
    int c,d,e;
    double f;
    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;
    float array[6]={a, b, c, d, e, f}; 
    std::sort(array, array+6);
    float minsum=array[0]+array[1]+array[2];
    float maxsum=array[3]+array[4]+array[5];
    float result=0;
    if (maxsum>(minsum*4))
    {
        result=maxsum*minsum;
    }
    else if(maxsum>(minsum*3))
    {
        result=maxsum/minsum;
    }
    else if(maxsum>(minsum*2))
    {
        result=maxsum+minsum;
    }
    result=result/var;
    std::cout << result << std::endl;
    return result;
}

float** function_2(float &x)
{
    float** matrix=new float*[5];
    for(int i=0; i<5; i++)
    {
        matrix[i]=new float[5];
        for(int j=0; j<5; j++)
        {
            matrix[i][j]=x;
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            matrix[i][j]=(matrix[i][j]+var+j-i)*(std::rand() % 100 + 1);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return matrix;
}

float* function_3(float** &tower)
{
    float* array1=new float[5];
    float* array2=new float[5];
    float min;
    for(int i=0; i<5; i++)
    {
        min=INT_MAX;
        for(int j=0; j<5; j++)
        {
            if(tower[j][i]<min)
            {
                min=tower[j][i];
            }
        }
        array1[i]=min;
    }
    for(int i=0; i<5; i++)
    {
        float temp[5]={0,0,0,0,0};
        for(int j=0; j<5; j++)
        {
            temp[j]=tower[j][i];
        }
        std::sort(temp, temp+5);
        array2[i]=temp[0];
    }
    bool same=true;
    for(int i=0; i<5; i++)
    {
        if(array1[i]!=array2[i])
        {
            same=false;
        }
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    if(same)
    {
        std::cout << "The elements are the same!" << std::endl;
    }
    else
    {
        std::cout << "The elements are different!" << std::endl;
    }
    return array1;
}

struct Student
{
    std::string name;
    std::string surname;
    float money;
    Student* next;
    Student* prev;
    Student(std::string value1, std::string value2, float value3) 
    {
        name=value1;
        surname=value2;
        money=value3;
        next=nullptr;
        prev=nullptr;
    }
};

class List
{
    Student* head;
    public:
    List() {head=nullptr;}
    void insert(std::string val1, std::string val2, float val3, int pos)
    {
        Student* new_stud=new Student(val1, val2, val3);
        if(pos<0) 
        {
            std::cout << "Out of bounds!" << std::endl;
            delete new_stud;
            return;
        }
        if(pos==1)
        {
            new_stud->next=head;
            if(head!=NULL)
            {
                head->prev=new_stud;
            }
            head=new_stud;
        }
        else
        {
            Student* curr=head;
            for(int i=1; i<pos-1 && curr!=NULL; i++)
            {
                curr=curr->next;
            }
            if(curr==NULL)
            {
                std::cout << "Out of bounds!" << std::endl;
                delete new_stud;
                return;
            }
            else
            {
                new_stud->prev=curr;
                new_stud->next=curr->next;
                curr->next=new_stud;
                if(new_stud->next!=NULL)
                {
                    new_stud->next->prev=new_stud;
                }
            }
        }
    }
    void print()
    {
        Student* current=head;
        while(current!=NULL)
        {
            std::cout << current->name << " " << current->surname << " " << current->money << std::endl;
            current=current->next;
        }
    }
    void help_for_function_5(List &list, std::ofstream &oFile, int index)
    {
        if(index<=0)
        {
            return;
        }
        Student* curr=head;
        for(int i=1; i<index && curr!=NULL; i++)
        {
            curr=curr->next;
        }
        oFile << curr->name << " " << curr->surname << " " << curr->money << std::endl;
        help_for_function_5(list, oFile, index-1);
    }
    void help_for_function_5(List &list, std::ofstream &oFile)
    {
        Student* curr=head;
        while(curr)
        {
            oFile << curr->name << " " << curr->surname << " " << curr->money << std::endl;
            curr=curr->next;
        }
    }
};

List function_4(float* &array)
{
    float min=INT_MAX;
    float max=0;
    for(int i=0; i<5; i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
        if(array[i]<min)
        {
            min=array[i];
        }
    }
    float new_array[7];
    for(int i=1; i<6; i++)
    {
        new_array[i]=array[i]+array[i+1];
    }
    new_array[0]=max;
    new_array[6]=min;
    new_array[5]=array[4];
    List new_list;
    std::string names[7]={"A", "B", "C", "D", "E", "F", "G"};
    std::string surnames[7]={"a", "b", "c", "d", "e", "f", "g"};
    int i=0;
    while(i<7)
    {
        new_list.insert(names[i], surnames[i], new_array[i], i+1);
        i++;
    }
    new_list.print();
    return new_list;
}
void function_5(List &list, std::string &file_name)
{
    int index=7;
    std::ofstream oFile(file_name);
    if(!oFile)
    {
        std::cerr << "File failed to open!";
        return;
    }
    if(var % 2==0)
    {
        list.help_for_function_5(list, oFile, index);
    }
    else
    {
        list.help_for_function_5(list, oFile);
    }
}
void function_6(std::string &file_name)
{
    std::ifstream iFile(file_name);
    if(!iFile)
    {
        std::cerr << "File failed to open!";
        return;
    }
    std::string one;
    std::string two;
    float three;
    while(iFile >> one >> two >> three)
    {
        std::cout << one << " " << two << " " << three << std::endl;
    }
}
int main()
{
    float x=function_1();
    float** tower=function_2(x);
    float* array=function_3(tower);
    List list=function_4(array);
    std::string file_name="live.txt";
    function_5(list, file_name);
    function_6(file_name);
}
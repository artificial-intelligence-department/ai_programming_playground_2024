#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <string>
#include <fstream>
using namespace std;

const int var = 65;

float function_1() {
    float a, b;
    int c,d,e;
    double f;
    cin>>a>>b;
    cin>>c>>d>>e;
    cin>>f;
    float arr[6]={a,b,c,d,e,f};
    sort(arr,arr+6);
    float min_sum=arr[0]+arr[1]+arr[2];
    float max_sum=arr[3]+arr[4]+arr[5];
    float result =0;

    if(max_sum>(min_sum*4)) {
        result = max_sum*min_sum;
    } else if (max_sum>(min_sum*3)) {
        result = max_sum/min_sum;
    } else if (max_sum>(min_sum*2)) {
        result = max_sum + min_sum;
    }
    result = result/var;
    cout<<result<<endl;
    return result;
}

float** function_2(float &x) {
    float** matrix = new float*[5];
    for(int i=0;i<5;i++) {
        matrix [i] = new float[5];
        for(int j=0;j<5;j++) {
            matrix[i] [j] = (matrix [i][j] +var+j-i) *(rand()%100+1);
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return matrix;
}
 
 float* function_3(float** &tower) {
    float *arr1 = new float [5];
    float *arr2 = new float[5];

    for(int i=0; i<5;i++) {
        float min_val=INT_MAX;
        for(int j=0;j<5;j++) {
            if (tower[i][j]<min_val) {
                min_val = tower[j][i];
            }
        }
        arr1[i]=min_val;
    }
    for(int i=0;i<5;i++) {
        float temp[5]={0,0,0,0,0};
        for (int j=0;j<5;j++) {
            temp[j]=tower[j][i];
        }
        sort(temp,temp+5);
        arr2[i]=temp[0];
    }
    bool is_same=true;
    for(int i=0;i<5;i++) {
        if (arr1[i] != arr2[i]) {
            is_same = false;
        }
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    if (is_same) {
        cout << "The elements are the same"<<endl;
        cout<<"The elements are different"<<endl;
    }
    return arr1;
 }

 struct Student {
    string name,surname;
    float money;
    Student* next;
    Student* prev;
 };

 Student* function_4(float* &array) {
    float min = INT_MAX, max=0;
    for(int i=0;i<5;i++) {
    if (array[i]>max) max = array[i];
    if (array[i]>min) min = array[i];
    }
    
    float new_array[7];
    new_array[0]=max;
    for (int i=1;i<6;i++) {
        new_array[i]=array[i-1] + array[i];
    }
    new_array[6] = min;
    string names[7] = {"Name1","Name2","Name3","Name4","Name5","Name6","Name7"};
    string surnames[7] = {"Surname1","Surname2","Name3","Surname4","Surname5","Surname6","Surname7"};

    Student* head=nullptr;
    Student* prev=nullptr;

    for(int i=0;i<7;i++) {
        Student* new_student = new Student{names[i], surnames[i], new_array[i],nullptr,prev};
        if(prev) prev->next = new_student;
        else head = new_student;
        prev=new_student;
    }

    Student* current =head;
    while(current) {
        cout<<current->name<<" "<<current->surname<<" "<<current->money<<endl;
        current = current->next;
    }
    return head;
}    

void help_for_function_5(ofstream &oFile, Student* head) {
    Student* current=head;
    while(current) {
        oFile<<current->name<<" "<<current->surname<<" "<<current->money<<endl;
        current=current->next;
    }
}

void function_5 (Student* head, string &file_name) {
    ofstream oFile(file_name);
    if (!oFile) {
        cerr<<"File failed to open";
        return;
    }
    help_for_function_5(oFile,head);
}

 int main() {
    float x = function_1();
    float** tower = function_2(x);
    float* array = function_3(tower);
    Student* list= function_4(array);
    string file_name="file.txt";
    function_5(list,file_name);
    return 0;
 }
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>



struct student{

    char *name;
    char *surname;
    float money;

    student* next;
    student* previous;
};




const short option = 38;




double function_1(){

float a, b;
int c, d, e;
double f;


std::cout << "a = ";
std::cin >> a;

std::cout << "b = ";
std::cin >> b;

std::cout << "c = ";
std::cin >> c;

std::cout << "d = ";
std::cin >> d;

std::cout << "e = ";
std::cin >> e;

std::cout << "f = ";
std::cin >> f;


float list[] {a, b, static_cast<float>(c), static_cast<float>(d), static_cast<float>(e), static_cast<float>(f)};

std::sort(list, list + 6);


float smaller = list[0] + list[1] + list[2];
float bigger = list[3] + list[4] + list[5];
float result;

if(bigger > smaller * 4){
    result = bigger +smaller;
}
else if(bigger > smaller * 3){
    result = bigger / smaller;
}
else if(bigger > smaller * 2){
    result = bigger * smaller;
}

double x = result / option;

std::cout << "X = " << x << std::endl;


return x;
}


double** function_2(double &x){

    srand(time(nullptr));
    
    double **matrix = new double*[5];
    for(int i = 0; i < 5; ++i){
        matrix[i] = new double[5];
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = static_cast<double>(x);
        }
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            matrix[i][j] = (matrix[i][j] + option + j - i)*(rand() % 100 + 1);
        }
    }

    
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return matrix;
}


double* function_3(double **tower){

double *array = new double[5];





double smallest_number;

for(int j = 0; j < 5; ++j){
    smallest_number = tower[0][j];
    for(int i = 0; i < 5; ++i){
        if(tower[i][j] < smallest_number){
            smallest_number = tower[i][j];
        }
    }

    array[j] = smallest_number;
}

/*
for(int i = 0; i < 5; ++i){
    std::cout << "ARR " << i << ' ' << array[i];
}
*/

return array;

}


student *function_4(double *array){
srand(time(nullptr));
char names[7][10] = {"oleh", "maksym", "olya", "ihor", "yura", "ivan", "danylo"};
char surnames[7][15] = {"melnyk", "shevchenko", "kovalenko", "boyko", "koval", "rudenko", "moroz"};


student *head = nullptr;
student *current = head;
char *temp_name;
char* temp_surn;
double sum = 0;
for(int i = 0; i < 7; ++i){
    temp_name = new char[10];
    strcpy(temp_name, names[rand() % 7]);
    temp_surn = new char[15];
    strcpy(temp_surn, surnames[rand() % 7]);

    strcpy(current->name, temp_name);
    strcpy(current->name, temp_name);


    std::sort(array, array + 7);
    sum+= array[i];
    if(i == 0)
        current->money = array[0];
    if(i >=2 && i <=6)
        current->money = sum;
    if(i == 7)
        current->money = array[4];
    current = current->next;
    current->next->previous = current;

}

current->next = nullptr;

while(current != nullptr){
    std::cout << current->money;
    current = current->previous;
}

return head;
}



int main(){

double x = function_1();

double **tower {function_2(x)};




double *array = {function_3(tower)};

student *head = {function_4(array)};


    return 0;
}
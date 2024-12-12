#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

const int VARIANT =  42;

// Завдання №1
double function_1 (){
 double a, b, f;
 int c, d, e;   

std::cout << " Введіть два дійсних числа:";
std::cin >> a >> b;
std::cout << " Введіть три цілих числа:";
std::cin >> c >> d >> e ;
std::cout << " Введіть одне дійсне число з подвійною точністю:";
std::cin >> f;

double values [] = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };
std::sort (values, values + 6 );

double sum_min = values[0] + values[1] + values[2];
double sum_max = values[3] + values[4] + values[5];
double x = 0;

if  (sum_max > sum_min * 4){
    x = sum_max + sum_min;
} else if ( sum_max > sum_min * 3){
    x = sum_max / sum_min;
} else if ( sum_max > sum_min * 2){
    x = sum_max * sum_min;
}
x/= VARIANT;
std::cout << " Результат function_1: " << x << std::endl;
return x;
}
//Завдання №2 
void function_2 ( double &x, double matrix[5][5] ){
    for ( int i = 0; i < 5 ; ++i)
    for (int j = 0; j < 5; ++j)
    matrix[i][j] = x;

    for (int i = 0; i < 5 ; ++i)
    for (int j = 0; j< 5; ++j)
    matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand()% 100 +1);

    std::cout << " матриця :" << std::endl;
    for ( int i = 0; i < 5 ; ++i){
        for (int j = 0; j < 5; ++j){
            std::cout << std::setw(10) << matrix[i][j] << "";
        }
        std::cout << std::endl;
    }

}
// Завдання №3
void function_3(double matrix[5][5], double result[5]) {
     for  (int j = 0; j < 5; ++j){
        double min1 = matrix[0][j];
        double min2 = matrix[0][j];

    for (int i = 1; i < 5; ++i){
        if (matrix[i][j] < min1) min1 = matrix[i][j];
        min2 = std::min( min2, matrix[i][j]);
           }
           if (min1 != min2){
            std::cout << " Мінімальні значення не співпадають " << j << std::endl;
           }
     } result[j] = min1;
}
// Завдання №4
void function_4 (double result[5], std::list<std::string > &students){
    struct Student{
        std::string first_name;
        std::string last_name;
        double money;
    };
 Student student_list[7];
 std::string names[7] = { " Софія", " Юля", " Дарина ", " Таня ", " Настя ", " Вероніка "," Аліна "};
 std::string surnames[7] = { " Куць ", " Тимошенко ", " Крупач ", " Липко ", " Сьвір", " Худзік", " Зелінська"};
  
for ( int i = 0; i < 7; ++i ){
    student_list[i].first_name = names[i];
    student_list[i].last_name = surnames[i];
}
student_list[0].money = *std::max_element(result, result + 5);
student_list[6].money = *std::min_element(result, result + 5);
for (int i = 1; i < 6; ++i){
    student_list[i].money = result[i -1];
}
for(int i = 0; i < 7; ++i){
    std::string student_info = student_list[i].first_name + " " + student_list[i].last_name + " - " + std::to_string(student_list[i].money);
    students.push_back(student_info);
    std::cout << student_info << std::endl;
   }
}
//Завдання №5
void  help_for_function_5 (std::ofstream& file, const std::list< Student >& students, std::list<Student>::const_reverse_iterator it ){
    if (it == students.rend()) return;
    file << it->name << " " << it ->surname << " - " << it->money << std::endl;
    help_for_function_5( file, students, ++it);
}
void function_5 (std::list<Student>& students){
    std::ofstream file("students.txt");
    if(!file.is_open()){
        std::cerr << " Не вдалось відкрити файл для запису!!!" << std::endl;
        return;
    }
    help_for_function_5(file, students, students.rbegin());

    file.close();
}
// Завдання №6
void function_6(){
    std::ifstream file ("students.txt");
    if (!file.is_open()){
        std::cerr << " Файл не знвйдено !!! " << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line )){
        std::cout << line << std::endl;
    }
    file.close();
}
//  Головна функція 
int main(){
    srand(time(0));
    double x = function_1();
    double matrix[5][5];
    function_2(x, matrix);
    double result[5];
    function_3(matrix, result);
    std::list<std::string> students; 
    function_4(result, students);
    function_5(students);
    function_6();

    return 0;
}
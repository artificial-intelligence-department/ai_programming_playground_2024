#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

const int VARIANT = 29;

double function_1(){
    double a, b, f;
    int c, d, e;

    cout << "Enter 2 racional numbers(a, b): ";
    cin >> a >> b;

    cout << "Enter 3 integer numbers(c, d, e): ";
    cin >> c >> d >> e;

    cout << "Enter racional number (f): ";
    cin >> f;

    double values [] = { a, b, (double)c, (double)d, (double)e, f};
    sort (values, values + 6);
    double Maxim = values[5] + values[4] + values[3];
    double Minim = values[0] + values[1] + values[2];
    double result;

    if (Maxim > Minim * 4)
    {
        result = Maxim + Minim;
    } else if (Maxim > Minim * 3)
    {
        result = Maxim / Minim;
    }else if (Maxim > Minim * 2)
    {
       result = Maxim * Minim;
    }else
    {
        result = Maxim - Minim;
    }
    
    double x = result / VARIANT;
    cout << "Result of function_1: " << x << endl;
    return x;
}
void function_2(double matrix [5][5], double x){
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix [i][j] = x;
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix [i][j] = (matrix [i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
        
    }
    
    cout << "New matrix:" << endl;
    for (int i = 0; i < 5; i++){
       for (int j = 0; j < 5; j++)
       {
        cout << setw(10) << matrix [i][j];
       }
       cout << endl;
    }
}
double* function_3(double matrix[5][5]){
    double colum_mini[5];

    for (int j = 0; j < 5; j++)
    {
        double mini1 = matrix [0][j];
        for (int i = 0; i < 5; i++)
        {
            if (matrix [i][j] < mini1)
            {
                mini1 = matrix [i][j];
            }
            
        }

        double mini2 = *min_element(&matrix[0][j], &matrix[5][j]);

        if (mini1 != mini2)
        {
            cout << "Search results different for colum" << j << endl; 
        }
        
        colum_mini[j] = mini1;
    }

    return colum_mini;
}
struct Student
{
    string name;
    string surname;
    double cash;
};
Student* function_4(double *array){
    static Student students[7];
    string names[] = {"Pavlo", "Roman", "Ivan", "Oleksandr", "Natalya", "Oksana", "Victorya"};
    string surnames [] = {"Smith", "Jones", "Williams", "Brown", "White", "Black", "Evans"};

    for (int i = 0; i < 7; i++)
    {
        students [i].name = names [rand() % 7];
        students [i].surname = surnames [rand() % 7];
    }

    students[0].cash = *max_element(array, array + 5);
    for (int i = 0; i < 6; i++)
    {
        students[i].cash = array [i - 1];
    }
        students[6].cash = *min_element(array, array + 5);

        cout << "Student list" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << students[i].name << "" << students [i].surname << ":" << students[i].cash << endl;
    }
    
    return students;
}
void function_5(Student students[]){
    ofstream file ("students.txt");
    if (!file.is_open())
    {
        cerr << "Error during opening file" << endl;
        return;
    }
    for (int i = 6; i >= 0; i--)
    {
        file << students [i].name << "" << students [i].surname << ":" << students[i].cash << endl;
    }

    file.close();
    ifstream read_file ("students.txt");
    if (!read_file.is_open())
    {
        cerr << "File not found" << endl;
        return;
    }
    cout << "Encrypted file containment: " << endl;
    string line;
    while (getline(read_file, line)){
        cout << line << endl;
    }
    read_file.close();
    
}
int main (){
    double x = function_1();
    double matrix [5][5];
    function_2 (matrix, x);
    double* tower = function_3(matrix);
    Student* students = function_4(tower);
    function_5 (students);
    return 0;
}
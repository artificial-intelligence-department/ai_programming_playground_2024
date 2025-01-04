#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>  //randomaiser
#include <ctime>   // my local time
#include <iomanip> // для скорочення після ком
#include <list>   
#include <string> // strichku
#include <fstream> // student
using namespace std;


const int VARIANT_NUMBER = 17; 
struct Student
{
    string first_name;
    string last_name;
    double balance;
};


double function_1()
{
    double a, b, f;
    int c, d, e;

    cout << "Enter double numbers a, b: ";
    cin >> a >> b;
    cout << "Enter int numbers c, d, e: ";
    cin >> c >> d >> e;
    cout << "Enter double number f: ";
    cin >> f;

    vector<double> values = { a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f };
    sort(values.begin(), values.end());

    cout << "Massive of sorted numbers: ";
    for (double val : values) {
        cout << val << " ";
    }
    cout << endl;

    double smallest_sum = values[0] + values[1] + values[2];
    double largest_sum = values[3] + values[4] + values[5];
    cout << " Smallest elements: " << values[0] << " , " << values[1] << " , " << values[2] << endl;
    cout << " Largest elements : " << values[3] << " , " << values[4] << " , " << values[5] << endl;
    double result;


    if (largest_sum > smallest_sum * 2)
    {
        result = largest_sum * smallest_sum;
    }
    else if (largest_sum > smallest_sum * 3)
    {
        result = largest_sum / smallest_sum;
    }
    else if (largest_sum > smallest_sum * 4)
    {
        result = largest_sum + smallest_sum;
    }
    else {
        result = largest_sum - smallest_sum;
    }

    double x = result / VARIANT_NUMBER;

    cout << fixed << setprecision(2);
    cout << "Result after division: " << x << endl;

    return x;
}

vector<vector<double>> function_2(double& x)
{
    srand(static_cast<unsigned>(time(0)));

    vector<vector<double>> matrix(5, vector<double>(5, x));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            double random_factor = (rand() % 100 + 1);
            matrix[i][j] = (matrix[i][j] + VARIANT_NUMBER + j - i) * random_factor;
        }
    }

    cout << "New matrix:" << endl;
    for (const auto& row : matrix)
    {
        for (double val : row) {
            cout << fixed << setprecision(1) << val << "\t";
        }
        cout << endl;
    }

    return matrix;
}


vector<double> function_3(const vector<vector<double>>& tower)
{
    vector<double> min_elements(5);

    for (int j = 0; j < 5; ++j)
    {
        min_elements[j] = tower[0][j];
        for (int i = 1; i < 5; ++i)
        {
            min_elements[j] = min(min_elements[j], tower[i][j]);
        }
    }

    return min_elements;
}

list<Student> function_4(const vector<double>& elements)
{
    list<Student> students(7);

    vector<string> first_names = { "Adam", "Adam2", "Adam3", "Adam4", "Adam5", "Adam6", "Adam7" };
    vector<string> last_names = { "Patison", "Patison2", "Patison3", "Patison4", "Patison5", "Patison6", "Patison7" };

    auto it = students.begin();


    (*it).first_name = first_names[0];
    (*it).last_name = last_names[0];
    (*it).balance = *max_element(elements.begin(), elements.end());
    ++it;

    for (int i = 1; i <= 5; ++i, ++it)
    {
        (*it).first_name = first_names[i];
        (*it).last_name = last_names[i];
        (*it).balance = elements[i - 1];
    }

    (*it).first_name = first_names[6];
    (*it).last_name = last_names[6];
    (*it).balance = *min_element(elements.begin(), elements.end());

    for (const auto& student : students)
    {
        cout << student.first_name << " " << student.last_name << " : " << fixed << setprecision(2) << student.balance << endl;
    }

    return students;
}

void help_for_function_5(const list<Student>& students, ofstream& file)
{
    for (const auto& student : students)
    {
        file << student.first_name << " " << student.last_name << " : " << fixed << setprecision(2) << student.balance << endl;
    }
}

void help_for_function_5(list<Student>::const_reverse_iterator it, list<Student>::const_reverse_iterator end, ofstream& file)
{
    if (it != end) {
        file << it->first_name << " " << it->last_name << " : " << fixed << setprecision(2) << it->balance << endl;
        help_for_function_5(++it, end, file);
    }
}

void function_5(const list<Student>& students)
{
    ofstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error " << endl;
        return;
    }

    if (VARIANT_NUMBER % 2 == 0) {
        help_for_function_5(students.rbegin(), students.rend(), file);
    }
    else {
        help_for_function_5(students, file);
    }

    file.close();
}

int main()
{
    double x = function_1();

    vector<vector<double>> tower = function_2(x);

    vector<double> min_elements = function_3(tower);

    list<Student> student_list = function_4(min_elements);

    cout << "Min element from matrix: ";
    for (double val : min_elements) {
        cout << val << " ";
    }
    cout << endl;

    function_5(student_list);








    return 0;




}































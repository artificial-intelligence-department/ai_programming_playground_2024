#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <list>
#include <fstream>

using namespace std;
struct Student{
    string firstName;
    string lastName;
    double accountBalance;
};

double function1(){
    double a,b,f;
    int c,d,e;

    cout << "Ввeдіть два дійсних числа a ta b: ";
    cin >> a >> b;
    cout << "Ввeдіть три цілі числа c,d ta e: ";
    cin >> c >> d >> e;
    cout << "Ввeдіть дійсне число f: ";
    cin >> f;

    vector<double> values = {a,b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    sort(values.begin(), values.end());
    double summin = values[0] + values[1] + values[2];
    double summax = values[3] + values[4] + values[5];

    double result;

    if ( summax > summin *2) {
        result = summax * summin;
    }
    else if ( summax > summin * 3){
        result = summax / summin;
    }
    else if (summax > summin * 4){
        result = summax + summin; 
    }
    else {
        result = 0;
    }
    int var = 23;
    result /= var;
    cout << "Result: " << result << endl;
    return result;
}

vector<vector<double>> function2(double &x, vector<vector<double>> &tower) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            tower[i][j] = x;
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            tower[i][j] = (tower[i][j] + 23 + j - i) * (rand() % 100 + 1);
        }
    }

    cout << "Оновлена матриця:" << endl;
    for (const auto &row : tower) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return tower;
}

vector<double> function3(vector<vector<double>> &tower) {
    const int cols = 5;
    vector<double> column_minimum(cols);

    cout << " Search minimum element: " << endl;
    for (int j = 0; j < cols; j++) {
        double minValue1 = tower[0][j];
        double minValue2 = tower[0][j];
        for ( int i = 1; i < 5; i++){
            if (tower[i][j] < minValue1){
                minValue1 = tower[i][j];
            }
        }
        double min_value_2 = tower[0][j];
        for (int i = 1; i < 5; ++i) {
        if (tower[i][j] < min_value_2) {
        min_value_2 = tower[i][j];
    }
}

    if (minValue1 == minValue2){
        cout << "The same" << endl;
    }
    else {
        cout << "Not the same" << endl;
    }
        column_minimum[j] = minValue1;
    }
    return column_minimum;

}

list<Student> function4(const vector<double> &minimums) {
    list<Student> students;
    vector<string> firstNames = {"jon", "denys", "Taylor", "One", "Sam", "Bohdan", "Alex"};
    vector<string> lastName = {"jonson", "777", "Derden", "Ivan", "Anderson", "Sylich", "Lee"};

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 7; i++){
        Student student;
        student.firstName = firstNames[rand() & firstNames.size()];
        student.lastName = lastName[rand() & lastName.size()];
        student.accountBalance = 0.0;
        students.push_back(student);
    }
    auto it = students.begin();
    it->accountBalance = *max_element(minimums.begin(), minimums.end());
    ++it;
    for (int i = 1; i <=5; i++, ++it){
        it->accountBalance = minimums[i-1];
    }
    it->accountBalance = *min_element(minimums.begin(), minimums.end());

    cout << "List of studednts: " << endl;
    for (const auto &student : students){
        cout << "Ім'я: " << student.firstName << ", Прізвище: " << student.lastName
             << ", Баланс: " << student.accountBalance << endl;
    }
    return students;
}
void help_for_function_5(const list<Student> &students, ofstream &file) {
    for (const auto &student : students) {
        file << "Ім'я: " << student.firstName 
             << ", Прізвище: " << student.lastName 
             << ", Баланс: " << student.accountBalance << endl;
    }
}
void function5(const list<Student> &students){
    const string filename = "students.txt";

    ofstream file(filename);
    if (!file.is_open()){
        cerr << "Can't open file " << endl;
        return;
    }
    for (const auto &student : students){
        file << "Name: " << student.firstName
             << ", Surname: " << student.lastName
             << ", Balance: " << student.accountBalance << endl;
    }
    file.close();
    cout << "List of students" << endl;

    ifstream infile(filename);
    if (!file.is_open()){
        cerr << "Cant open file" << endl;
        return;
    }

    string line;
    while (getline(infile, line)){
        cout << line << endl;
    }
    file.close();
}
void function6(){
    ifstream file("students.txt");
    if(!file.is_open()){
        cout << "Файл не знайдено" << endl;
        return;
    }
    string line;
    cout << "file source: " << endl;
    while (getline(file,line)){
        cout << line << endl;
    }
    file.close();
}

int main(){
    double x = function1();
    vector<vector<double>> tower(5, vector<double>(5));
    function2(x, tower);
    vector<double> minimums = function3(tower);
    list<Student> students = function4(minimums);
    function5(students);
    function6();
    return 0;
}
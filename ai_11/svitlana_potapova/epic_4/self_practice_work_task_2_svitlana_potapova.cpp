#include <iostream>
using namespace std;

struct employee{
    int id;
    string name;
    int salary;

    friend ostream& operator<<(ostream& os, const employee emp){
      os << "Employee ID: " << emp.id << ", name: " << emp.name << ", salary: " << emp.salary;
      return os;
    }
    friend istream& operator>>(istream& is, employee& emp){
      cout << "Enter ID: ";
      is >> emp.id;
      cout << "Enter name: ";
      is >> emp.name;
      cout << "Enter salary: ";
      is >> emp.salary;
      return is;
    }
};

int main(){
    int N;
    cout << "Enter amount of employees: " << endl;
    cin >> N;

    employee* array = new employee[N];

    for(int i=0; i<N; i++){
        cout << "Enter data for employee №" << i+1 << endl;
        cin >> array[i];
    }

    int maxSalary = 0;
    for(int i=0; i<N; i++){
        if(array[i].salary > maxSalary){
            maxSalary = array[i].salary;
        }
        cout << array[i] << endl;
    }
    cout << "The highest salary is: " << maxSalary;
    delete[] array;
    return 0;
}
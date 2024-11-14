#include <iostream>
using namespace std;

struct employee{
    int id;
    string name;
    int salary;
};

void displayInfo(employee person){
    cout << "Employee ID: " << person.id << endl;
    cout << "Name: " << person.name << endl;
    cout << "Salary: " << person.salary <<endl;
}

int main(){
    int N;
    cout << "Enter amount of employees: " << endl;
    cin >> N;

    employee* array = new employee[N];

    for(int i=0; i<N; i++){
        cout << "Enter data for employee №" << i+1 << endl;
        employee temp;
        cin >> temp.id >> temp.name >> temp.salary;

        array[i] = temp;
    }

    int maxSalary = 0;
    for(int i=0; i<N; i++){
        if(array[i].salary > maxSalary){
            maxSalary = array[i].salary;
        }
        displayInfo(array[i]);
        cout << endl;
    }

    cout << "The highest salary is: " << maxSalary;

    delete[] array;
    return 0;

}

//Частина коду скопійована із лайвкодингу

#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;



struct Student {
public:
    string first_name;
    string last_name;
    float bank_money;
    Student* next;
    Student* prev;

    Student(string f_name, string l_name, float b_money) {
        first_name = f_name;
        last_name = l_name;
        bank_money = b_money;
        next = nullptr;
        prev = nullptr;
    }
};


struct StudentList {

    public:
    Student* head;
    Student* tail;
    int size;
    StudentList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }



    void create(int listSize, string f_name[], string l_name[], float b_money[]) {
        for(int i=0; i<listSize; i++){
            Student* newSt = new Student(f_name[i], l_name[i], b_money[i]);
            if(!head){
                head = newSt;
                head->next = tail;
            } else {
                Student* tmp = head;
                while(tmp->next){
                    tmp = tmp->next;
                }
                tmp->next = newSt;
                newSt->prev = tmp;
                tail=newSt;
            }
        }
    }

    void print(){
        Student* curr = head;
        while(curr){
            std::cout << "Ім'я : " << curr->first_name << 
            ";  Прізвище : " << curr->last_name <<
            ";  Рахунок : " << curr->bank_money << "\n";
            curr = curr->next;
        }
    }


};


void func_recursive(Student* node, ofstream &f){
    Student* current = node;
    if(current){
        cout << current->first_name << " " << current->last_name << " " << current->bank_money << "\n";
        f << current->first_name << " " << current->last_name << " " << current->bank_money << "\n";
        func_recursive(current->next, f);
    }

}

void func_recursive(Student* node, ofstream &f, int n){
    Student* current = node;
    for(int i=0; i<n; i++){
        cout << current->first_name << " " << current->last_name << " " << current->bank_money << "\n";
        f << current->first_name << " " << current->last_name << " " << current->bank_money << "\n";
        current = current->next;
    }
}



int main(){

// Task 1
    StudentList list;
    int n=7;
    ofstream f("Task1.txt");
    float bank_money[n] = {1, 2, 3, 4, 5, 6, 7};
    string first_name[n] = {"Anya", "Solomiia", "Stanley", "Asley", "Yaroslaw", "Alya", "Star"};
    string last_name[n] = {"Forger", "Chrowey", "Pines", "Corney", "Kob", "Sesar", "Butterfly"};
    list.create(n ,first_name, last_name, bank_money);
    func_recursive(list.head, f);
    f.close();
    cout << "\n";
    ifstream inf("Task1.txt");
    string line;
    while(getline(inf, line)){
        cout << line << "\n";
    }
    inf.close();

    
    cout << "\n";


    //Task 2
    ofstream oFile("Task2.txt");
    func_recursive(list.head, oFile, n);
    oFile.close();
    cout << "\n";
    ifstream iFile("Task2.txt");
    while(getline(iFile, line)){
        cout << line << "\n";
    }
    iFile.close();





    return 0;
}
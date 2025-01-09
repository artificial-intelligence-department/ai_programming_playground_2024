#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Student{
    int ID;
    string name;
    float mark;
    Student* next;
};

Student* function_1(int &size){
    int ID;
    string name; 
    float mark;

    Student* head = nullptr;
    Student* tail = nullptr;
    for(int i = 0; i < size; i++){
        Student* newStudent = new Student;
        cin >> ID;
        cin.ignore();
        getline(cin, name);
        cin >> mark;

        newStudent -> ID = ID;
        newStudent -> name = name;
        newStudent -> mark = mark;
        newStudent -> next = nullptr;

        if(head == nullptr){
            head = newStudent;
            tail = newStudent;
        }
        else{
            tail -> next = newStudent;
            tail = newStudent;
        }
    }

    Student* current = head;
    while(current != nullptr){
        cout << current -> ID << "\n";
        cout << current -> name << "\n"; 
        cout << current -> mark << "\n";
        cout << endl;
        current = current -> next;
    }
    
    return head;
}

void input_in_file(Student* head){
    ofstream file("training.txt");
    if(!file.is_open()){
        cerr << "File can`t be opened" << endl;
        exit(1);
    }

    Student* current = head;
    while(current != nullptr){
        file << "ID: " << current -> ID << endl;
        file << "Name: " << current -> name << endl;
        file << "Mark: " << current -> mark << endl;
        file << endl;
        current = current -> next;
    }
    file.close();
    //if(file.close()){
        cout << "Everything is written." << endl;
    //}
}
int main(){

    int size;
    cin >> size;

    Student* studentlist = function_1(size);
    input_in_file(studentlist);

    while(studentlist != nullptr){
        Student* temp = studentlist;
        studentlist = studentlist -> next;
        delete temp;
    }


    return 0;
}



// #include <iostream> 
// #include <string> 
// using namespace std; 
// struct Student { 
//     int ID; 
//     string name; 
//     float mark; 
//     Student* next; 
//     }; 

// Student* insertNode(Student* head, int prevID, int newID, string newName, float newMark){ 
//     Student* newStudent = new Student; 
//     newStudent->ID = newID; 
//     newStudent->name = newName; 
//     newStudent->mark = newMark; 
//     newStudent->next = nullptr; 
//     Student* current = head; 
//     while(current != nullptr && current->ID != prevID){ 
//         current = current->next; 
//         } 
//         if (current != nullptr){ 
//             newStudent->next = current->next; current->next = newStudent; 
//             } return head; 
// } 

// void printList(Student* head){ 
//     Student* current = head; 
//     while(current != nullptr){ 
//         cout << "ID: " << current->ID << "\n"; 
//         cout << "Name: " << current->name << "\n"; 
//         cout << "Mark: " << current->mark << "\n"; 
//         cout << endl; current = current->next; } 
// } 
        
       
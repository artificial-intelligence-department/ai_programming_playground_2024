#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
Знищити всі елементи, у яких є 2 хоча б з одного предмету, додати елемент у
початок файлу.
*/

/* Приклади:
Ivanov Petro Oleksiyovych 10-B 098-123-4567 9 2 10 9
Petriv Andrii Vasylovych 11-C 067-890-1234 7 6 12 7
Sydorenko Mariia Ivanivna 9-A 095-456-7890 10 9 10 8
Koval Oksana Mykolaivna 10-A 050-321-6547 8 8 9 2
*/

struct Student{
    string name;
    string clas;
    string phoneNumber;
    int grades[4];
};

Student createStudent() {
    Student student;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, student.name); 
    cout << "Enter class: ";
    cin >> student.clas;
    cout << "Enter phone number: ";
    cin >> student.phoneNumber;
    cout << "Enter grades: "; 
    while(true) {
        cin >> student.grades[0] >> student.grades[1] >> student.grades[2] >> student.grades[3];
        if(cin.fail()) {
            cin.clear();
            cin.ignore(23457, '\n');
            cout << "Try again: ";
        } else break;
    }
    return student;
}

void writeStudent(Student st) {
    ofstream outf("Students.txt", ios::binary | ios::app);
    if(outf.is_open()) {
        outf << st.name << "\n" << st.clas << "\n" << st.phoneNumber << "\n" <<
        st.grades[0] << " " << st.grades[1] << " " << st.grades[2] << " " << st.grades[3] << "\n";
    }
    else {
        cout << "Error: file is not opened;";
        exit(1);
    }
}

bool findBadStudent(int index) {
    ifstream file("Students.txt");
    if(file.is_open()) {
        string grades;
        int lineNumber = 0;
        while (lineNumber < 4*index-1 && getline(file, grades)) {
            lineNumber++;
        }
        getline(file, grades);
        string s = " 2 ";
        auto it = grades.find(s);
        if(it == string::npos) return false;
        else return true;
    } else {
        cout << "Error: file is not opened;";
        exit(1);
    }
}

void removeStudents(int length, bool arr[], int &count) {
    vector<string> lines;
    ifstream file("Students.txt");
    if(file.is_open()) {
        string line;
        for(int i = 0; i < length; i++) {
            if(!arr[i]) {
                for(int j = 0; j < 4; j++) {
                    getline(file, line);
                    lines.push_back(line);
                }
            }
            else {
                getline(file, line);
                getline(file, line);
                getline(file, line);
                getline(file, line);
                count++;
            }
        }
        file.close();
    } else {
        cout << "Error: file is not opened;";
        exit(1);
    }
    ofstream file2("Students.txt", ios::binary);
    if(file2.is_open()) {
        for(int i = 0; i < lines.size(); i++) {
            file2 << lines[i] << "\n";
        }
    } else {
        cout << "Error: file is not opened;";
        exit(1);
    }
}

void addStudent(int size) {
    cout << "Enter data about new student: \n";
    Student n = createStudent();
    fstream file("Students.txt", ios::in);
    vector<string> prev;
    string line;
    if(file.is_open()) {
        file.seekp(0, ios::beg);
        for(int i = 0; i < size*4; i++) {
            getline(file, line);
            prev.push_back(line);
        }
        file.close();
        ofstream file2("Students.txt", ios::binary);
        writeStudent(n);
        if(file2.is_open()) {
            file2.seekp(0, ios::end);
            for(int i = 0; i < prev.size(); i++) {
                file2 << prev[i] << "\n";
        }
        } else {
            cout << "Error: file is not opened;";
            exit(1);
        }
    } else {
        cout << "Error: file is not opened;";
        exit(1);
    }
}

void print() {
    cout << "This is how our file looks likes: \n";
    ifstream file("Students.txt");
    if(file.is_open()) {
        string str;
        while(getline(file, str)) {
            cout << str << "\n";
        }
    } else {
        cout << "Error: file is not opened;";
        exit(1);
    }
}

int main() {
    cout << "How many students you want to create? ";
    int num;
    cin >> num;
    ofstream file("Students.txt", ios::binary);
    file.close();
    for(int i = 0; i < num; i++) {
        cout << "Enter data about " << i + 1 << " student:\n";
        Student student = createStudent();
        writeStudent(student);
    }
    bool arr[100];
    for(int i = 0; i < num; i++) {
        arr[i] = findBadStudent(i+1);
    }
    int studentsRemoved = 0;
    removeStudents(num, arr, studentsRemoved);
    addStudent(num-studentsRemoved);
    print();
    return 0;
}
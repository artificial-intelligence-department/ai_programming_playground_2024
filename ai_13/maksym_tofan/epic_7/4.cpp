#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

struct Student {
    std::string firstName, lastName;
    double balance;
};


void function_2(int tower[5][5]) {

    for (int i = 0; i < 5; ++i) 
        for (int j = 0; j < 5)
        tower[i][j] = rand() % 100 + 1;


}       

void function_3(int tower[5][5], int result[5]) {

    for (int j = 0; j < 5; ++j) {
        result[j] = tower[0][j];
        for (int i = 1; i < 5; ++i)
        if (tower[i][j] < result[j]) result[j] = tower[i][j];

}  
}

void function_4(int result[5]) {

std::list<Student> students;
std::string name [7][2] = {{"ivan", "go"},{{"ivkan", "gno"},{"ivlan", "goo"},{"ivakn", "goh"},{"ivfan", "go"},{"igan", "gogggg"},}


for (int i = 0; i < 7; ++i) {
    Students s = {names[i][0],names[i][1], (i == 0 ? result[0] : (i ==6 ? result [4] :result[i]))}
    students.push_back(s);
} 

for (auto& s : students)
std::cout << s.firstName < "" < s.lastNAme < ": " << s.balance <<std::endl;


}


int main() {
srand(time(0));
int tower [5][5], result [5];


function_2(tower);
function_3(tower, result);
function_4(result);


}



}
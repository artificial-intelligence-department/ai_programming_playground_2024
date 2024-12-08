#include <iostream>
#include <string>
using namespace std;

int main(){
    string year;
    getline(cin, year);

    string half_date = "16.02.";
    string full_date = half_date + year;

    cout << full_date; 

    return 0;
}
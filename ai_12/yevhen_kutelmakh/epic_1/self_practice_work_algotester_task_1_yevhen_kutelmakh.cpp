//Цікава гра
//https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/20074
#include <iostream>
using namespace std;

int main() {
    //cout << "Enter size of board, n lines and m columns: ";
    int n, m;
    cin >> n >> m;
    int number = m * n;
    if(number % 2 == 0)
    cout << "Dragon";
    else 
    cout << "Imp";
    return 0;
}
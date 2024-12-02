#include <iostream>

using namespace std;
int main() {
    long double sd, su, v;
    cin >> sd >> su >> v;


    long double timeDown = sd / (v * 2); 
    long double timeUp = su / (v / 2);  


    if (timeDown < timeUp) {
        cout << "Down"; 
    } else if (timeUp < timeDown) {
        cout << "Up";  
    } else {
        cout << "Never mind";

    return 0;
}
}
// https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40154#mySolutions
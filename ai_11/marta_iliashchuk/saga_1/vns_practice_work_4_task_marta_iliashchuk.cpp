#include <iostream>
using namespace std;

int main() {
    cout<<"Table of Squares for the First Ten Positive Integers:\n";
    cout<<"Number\tSquare\n";

    for (int i = 1; i <= 10; ++i) {
        cout<<i<<"\t"<< (i * i)<<endl;
    }

    return 0;
}
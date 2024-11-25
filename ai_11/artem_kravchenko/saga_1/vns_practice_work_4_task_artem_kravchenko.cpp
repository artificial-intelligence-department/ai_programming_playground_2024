#include <iostream>
#include <iomanip>

using namespace std;

float value(float x){
    return x < 0 ? -x : x;
}

void print(float x, float end, float hx){
    if (x > end)
    {
        return;
    }
    cout << setw(10) << x <<  setw(10) << value(x) << endl;
    print (x + hx, end, hx);
}

int main(){
    float start = -4.0;
    float end = 4.0;
    float hx = 0.5;

    cout << "Таблиця функції y=|x|: " << endl;
    cout << setw(10) << "x" << setw(10) << "y" << endl;
    print(start, end, hx);
    return 0;
}
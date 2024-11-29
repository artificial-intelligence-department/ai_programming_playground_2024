#include <iostream>
using namespace std;

int main()
{
    double side_of_the_cube;
    double v_of_the_cubs;
    
    cout << "Введіть сторону куба: ";
    cin >> side_of_the_cube;
    
    v_of_the_cubs = side_of_the_cube * side_of_the_cube * side_of_the_cube;
    cout << "V куба :" <<  v_of_the_cubs << endl;
}
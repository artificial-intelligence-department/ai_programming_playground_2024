#include <iostream>
#include <cmath>

using namespace std;

int main (){
    
    int m, n, res;
    bool res1, res2;

    cin >> m;
    cin >> n;

    res = n++ * m;
    cout << "m:" << m << "\nn: "<< n <<"\nres= "<< res << endl;
    res1 = n++ < m;
    cout << "check1: m: " << m << "\nn: " << n << endl;
    cout << "res1: " << res1 << endl;
    res2 = m-- > m;
    cout << "check2:: m:" << m << "\nn: " << n << endl;
    cout << "res2: " << res2 << endl;
    //Пояснення:
    //операція префіксного декременту/інкременту спочатку зменшує/збільшує змінну і тоді //записує її
    //операція постфіксного декременту/інкременту спочатку записує змінну,а тоді //зменшує/збільшує
    

    return 0;
}
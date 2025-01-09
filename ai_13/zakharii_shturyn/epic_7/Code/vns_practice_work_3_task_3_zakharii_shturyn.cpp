#include <iostream>
using namespace std;

double cube_volume(double a, int power) {       // 14. параметр та аргумент функції, для виконання операції  
    while(power > 1) {
        if(a == 1) {
            return a;
        }
        return a * cube_volume(a, power - 1);   // 13. рекурсія для піднесення до степення
    }
    return a;
}

int cube_volume(int a, int power) {       // 12. перевантаження функції під тип int
    while(power > 1) {
        if(a == 1) {
            return a;
        }
        return a * cube_volume(a, power - 1);
    }
    return a;
}

int main() {

    cout << "Which type of data is your cude edge?" << endl;
    int opt;    // 18. введення даних та виведення результату
    do
    {
        cout << "0)exit\n1)int\n2)double\n\n";
        cin >> opt;
        switch (opt)
        {
        case 0:
            break;
        
        case 1:
            int a;
            cout << "Enter size of cube edge" << endl;
            cin >> a;
            cout << "Volume of cube is: " << cube_volume(a, 3) << endl << endl;
            break;
        
        case 2:
            double b;
            cout << "Enter size of cube edge" << endl;
            cin >> b;
            cout << "Volume of cube is: " << cube_volume(b, 3) << endl << endl;
            break;

        default:
            break;
        } 
    } while (opt != 0);     // 8. do while цикл, поки не захочемо вийти
    

    return 0;
}
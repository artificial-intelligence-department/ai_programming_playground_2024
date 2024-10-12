#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double da = 1000;
    double db = 0.0001;
    cout << "a = " << da << "  b = " << db << endl;

    double dsumToSquare = pow((da + db), 2);
    double daToSquare = pow(da, 2);
    double dsecondEquatin = daToSquare + (2 * da * db);
    double dbToSquare = pow(db, 2);
    double dresult = (dsumToSquare - dsecondEquatin /  dbToSquare);
    cout << "Через double: " << dresult << endl;

    float fa = 1000;
    float fb = 0.0001;
    cout << "a = " << fa << "  b = " << fb << endl;

    float fsumToSquare = pow((fa + fb), 2);
    float faToSquare = pow(fa, 2);
    float fsecondEquatin = faToSquare + (2 * fa * fb);
    float fbToSquare = pow(fb, 2);
    float fresult = (fsumToSquare - fsecondEquatin /  fbToSquare);
    cout << "Через float: " << fresult << endl;

    return 0;
}
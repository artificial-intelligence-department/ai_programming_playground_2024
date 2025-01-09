#include <iostream>
#include <cmath>
using namespace std;

/* У файлі два варіанта 3, тому пишу другий варіант №3
Варіант 4(3.2). Обчислення об'єму циліндра. Нижче приведений
вид екрану під час виконання програми, що рекомендується (дані,
які вводяться користувачем, виділені напівжирним шрифтом).
Обчислення об'єму циліндра.
Введіть початкові дані:
радіус підстави (см) > 5
висоту циліндра (см) > 10
Об'єм циліндра 1570.80 см. куб.
Для завершення натисніть клавішу <Enter>.
*/

int main() {
    double R, H;
    cout << "Calculating volume of cylinder.\n";
    cout << "Enter starting data:\n";
    cout << "Radius(cm) > ";
    cin >> R;
    cout << "Height(cm) > ";
    cin >> H;
    double volume = M_PI*R*R*H;
    cout << "Volume of cylinder is " << volume << " cm^3\n";
    cout << "To quit press <Enter>.";
    cin.ignore();
    cin.get();
    return 0;
}
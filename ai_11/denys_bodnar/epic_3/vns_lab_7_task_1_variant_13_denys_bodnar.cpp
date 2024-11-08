#include <iostream>
#include <string>

using namespace std;

string Ternary(int number) {
    string ternary = "";
    if (number == 0) return "0";
    
    while (number > 0) {
        ternary = to_string(number % 3) + ternary;
        number /= 3;
    }
    return ternary;
}

void convertToTernary(int count, int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0) {
    cout << "Перетворення чисел у трійкову систему: ";
    if (count > 0) cout << a << " -> " << Ternary(a) << "  ";
    if (count > 1) cout << b << " -> " << Ternary(b) << "  ";
    if (count > 2) cout << c << " -> " << Ternary(c) << "  ";
    if (count > 3) cout << d << " -> " << Ternary(d) << "  ";
    if (count > 4) cout << e << " -> " << Ternary(e) << "  ";
    if (count > 5) cout << f << " -> " << Ternary(f) << "  ";
    if (count > 6) cout << g << " -> " << Ternary(g) << "  ";
    cout << endl;
}

int main() {
    convertToTernary(3, 0, 2, 3);
    convertToTernary(4, 4, 5, 6, 7);
    convertToTernary(7, 8, 9, 10, 11, 12, 13, 14);
    return 0;
}

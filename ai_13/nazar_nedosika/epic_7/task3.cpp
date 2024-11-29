#include <iostream>
#include <iomanip>

using namespace std;

double calculate_income(double principal, double rate, int days) {
    double yearly_income = principal * rate / 100;
    double years = days / 365.0;
    return yearly_income * years;
}

int main() {
    cout << "Обчислення величини доходу по внеску." << endl;
    
    double principal, rate;
    int days;
    
    cout << "Введіть суму внеску (грн): ";
    cin >> principal;
    cout << "Введіть процентну ставку (% річних): ";
    cin >> rate;
    cout << "Введіть час зберігання (днів): ";
    cin >> days;

    double income = calculate_income(principal, rate, days);
    double total = principal + income;
    
    cout << fixed << setprecision(2);
    cout << "\nДохід: " << income << " грн." << endl;
    cout << "Сума, після закінчення терміну внеску: " << total << " грн." << endl;

    return 0;
}
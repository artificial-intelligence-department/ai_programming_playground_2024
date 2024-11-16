#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


tm stringToDate(const string &date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%d.%m.%y");
    return tm;
}


int dateDifference(const tm &date1, const tm &date2) {
    time_t time1 = mktime(const_cast<tm*>(&date1));
    time_t time2 = mktime(const_cast<tm*>(&date2));
    return difftime(time2, time1) / (60 * 60 * 24);
}


int days(initializer_list<string> dates) {
    vector<tm> dateObjects;
    for (const auto &date : dates) {
        dateObjects.push_back(stringToDate(date));
    }
    if (dateObjects.size() < 2) {
        cerr << "Помилка: має бути передано принаймні дві дати." << endl;
        return 0;
    }
    int totalDays = 0;
    for (size_t i = 0; i < dateObjects.size() - 1; ++i) {
        totalDays += dateDifference(dateObjects[i], dateObjects[i + 1]);
    }

    return totalDays;
}

int main() {
    cout << "Кількість днів між датами (3 параметри): " << days({"01.01.23", "10.05.24", "6.01.25"}) << endl;
    cout << "Кількість днів між датами (5 параметрів): " << days({"01.01.21", "02.02.22", "03.03.23", "04.04.24", "05.05.25"}) << endl;
    cout << "Кількість днів між датами (8 параметрів): " << days({"01.03.24", "06.03.24", "11.04.24", "15.04.24", "01.05.24", "15.05.24", "01.06.24", "15.06.24"}) << endl;

    return 0;
}

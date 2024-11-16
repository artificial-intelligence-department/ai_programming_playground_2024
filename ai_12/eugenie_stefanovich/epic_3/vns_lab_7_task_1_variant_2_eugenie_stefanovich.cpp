#include <iostream>


bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


const int daysInMonthNormal[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int daysInMonthLeap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int dateToDays(int day, int month, int year) {
    int days = 0;

  
    for (int i = 0; i < month - 1; i++) {
        days += (isLeapYear(year)) ? daysInMonthLeap[i] : daysInMonthNormal[i];
    }

   
    days += day;

    return days;
}


int daysBetween(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = dateToDays(day1, month1, year1);
    int days2 = dateToDays(day2, month2, year2);  

    
    int totalDays = 0;

    if (year1 < year2) {
        
        for (int year = year1; year < year2; ++year) {
            totalDays += (isLeapYear(year)) ? 366 : 365;
        }
       
        totalDays += days2;
        
        totalDays -= days1;
    } else if (year1 > year2) {
        
        for (int year = year2; year < year1; ++year) {
            totalDays += (isLeapYear(year)) ? 366 : 365;
        }
        totalDays += days1;
        totalDays -= days2;
    } else {
        
        totalDays = days2 - days1;
    }

    return totalDays;
}

int main() {
    
    std::cout << "Відстань  між двумя датами (3 параметра): " << daysBetween(1, 1, 2020, 5, 1, 2020) << " днів\n";
    std::cout << "Відстань  між двумя датами (5 параметрів): " << daysBetween(1, 1, 2020, 1, 5, 2020) << " днів\n";
    std::cout << "Відстань  між двумя датами (8 параметрів): " << daysBetween(1, 1, 2020, 1, 1, 2021) << " днів\n";

    return 0;
}

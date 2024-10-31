// 8 variant
#include <iostream>
using namespace std;


void YearConverter(int year) {
    const string years[] = {
        "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Boar"
    };

    int index = (year - 4) % 12;
    cout << years[index] << endl;
}

void YearConverter(int year1, int year2) {
    const string years[] = {
        "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Sheep", "Monkey", "Rooster", "Dog", "Boar"
    };

    int index1 = (year1 - 4) % 12;
    int index2 = (year2 - 4) % 12;
    cout << years[index1] << endl;
    cout << years[index2] << endl;
}

string MonthConverter(string month) {
    if (month == "January") return "Capricorn or Aquarius";
    if (month == "February") return "Aquarius or Pisces";
    if (month == "March") return "Pisces or Aries";
    if (month == "April") return "Aries or Taurus";
    if (month == "May") return "Taurus or Gemini";
    if (month == "June") return "Gemini or Cancer";
    if (month == "July") return "Cancer or Leo";
    if (month == "August") return "Leo or Virgo";
    if (month == "September") return "Virgo or Libra";
    if (month == "October") return "Libra or Scorpio";
    if (month == "November") return "Scorpio or Sagittarius";
    if (month == "December") return "Sagittarius or Capricorn";

    return "Unknown month";
}


int main() {

    int TestYears[4] = {1923,1957,1991,2024};
    YearConverter(TestYears[0]);
    YearConverter(TestYears[1], TestYears[3]);

    string TestMonth[4] = {"July", "August", "February", "May"};
    cout << MonthConverter(TestMonth[0]) << endl;
    cout << MonthConverter(TestMonth[3]) << endl;


    return 0;
}
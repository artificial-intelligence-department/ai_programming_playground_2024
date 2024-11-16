#include <iostream>
#include <string>
using namespace std;

string kalendar(int year) {
    string japaneseYear[] = {
        "Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox",
        "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"
    };
    int index = year % 12;
    return japaneseYear[index];
}

string kalendar(string month){
    if (month == "january") return "Capricorn / Aquarius";
    if (month == "february") return "Aquarius / Pisces";
    if (month == "march") return "Pisces / Aries";
    if (month == "april") return "Aries / Taurus";
    if (month == "may") return "Taurus / Gemini";
    if (month == "june") return "Gemini / Cancer";
    if (month == "july") return "Cancer / Leo";
    if (month == "august") return "Leo / Virgo";
    if (month == "september") return "Virgo / Libra";
    if (month == "october") return "Libra / Scorpio";
    if (month == "november") return "Scorpio / Sagittarius";
    if (month == "december") return "Sagittarius / Capricorn";
    return 0;
}

int main() {
    int year;
    string month;
    cin >> year;
    cin >> month;
    cout << kalendar(year)<<endl;
    cout << kalendar(month)<<endl;
    return 0;
}
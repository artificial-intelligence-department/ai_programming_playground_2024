#include <iostream>
using namespace std;

string func(int year){
    string jp_years[] = {
        "rat", "ox", "tiger", "rabbit", 
        "dragon", "snake", "horse",  "goat", "monkey", "rooster", "dog", "pig"};
    int i = (year - 4)%12;
    return jp_years[i];
}

string func(string month){
    if(month == "january") return "capricorn and aquarius";
    if(month == "february") return "aquarius and pisces";
    if(month == "march") return "pisces and aries";
    if(month == "april") return "aries and taurus";
    if(month == "may") return "taurus and gemini";
    if(month == "june") return "gemini and cancer";
    if(month == "july") return "cancer and leo";
    if(month == "august") return "leo and virgo";
    if(month == "september") return "virgo and libra";
    if(month == "october") return "libra and scorpio";
    if(month == "november") return "scorpio and sagittarius";
    if(month == "december") return "sagittarius and capricorn";
}


int main(){
    cout << "2007 is the year of the " << func(2007) << endl;
    string month = "january";
    cout << "The zodiac signs of january are " << func(month);

    return 0;
}

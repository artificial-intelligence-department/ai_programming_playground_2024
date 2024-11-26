#include <iostream>
#include <vector>
#include <format>
#include <string>
#include<sstream>

using namespace std;
double func(string drib) {
    double chus = 0, znam = 0;
    int i = 0;
    while (drib[i] != '/') {
        chus *= 10;
        chus += (drib[i] - '0');
        i++;
    }
    i++;
    for (; i < drib.length(); i++) {
        znam *= 10;
        znam += (drib[i] - '0');
    }
    return chus / znam;
}

string removeZeros(const string& str) {
    string result = str;

    unsigned int decimalPos = result.find('.');
    if (decimalPos != string::npos) {
        unsigned int lastNonZero = result.find_last_not_of('0');

       
        if (lastNonZero < decimalPos) {
            result.erase(decimalPos);
        }
        else {
            result.erase(lastNonZero + 1);
        }
    }
    return result;
}

void func(double drib){
    string dribS = to_string(drib);
    string resultDrib;
    int i = 0;
    dribS = removeZeros(dribS);
    while (dribS[i] != '.'){
        resultDrib.push_back(dribS[i]);
        i++;
    }   
    i++;
    int countAfterSign = 0;
    for (; i < dribS.size(); i++){
        resultDrib.push_back(dribS[i]);
        countAfterSign++;
    }
    resultDrib.push_back('/');
    resultDrib.push_back('1');
    for (size_t i = 0; i < countAfterSign; i++){
        resultDrib.push_back('0');
    }

    cout << resultDrib;
}

int main() {
    string input;
    double input_1;
    cin >> input;
    cout << func(input);
    cin >> input_1;
    func(input_1);
    return 0;
}
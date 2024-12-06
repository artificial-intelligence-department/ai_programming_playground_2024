#include <iostream>
#include <string>

using namespace std;

bool isValidLuhn(const string& cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return sum % 10 == 0;
}

bool hasValidPrefix(const string& cardNumber) {
    if (cardNumber.length() < 2) {
        return false;
    }
    int prefix = stoi(cardNumber.substr(0, 2));
    return prefix >= 51 && prefix <= 55;
}

int main() {
    string cardNumber;
    cin >> cardNumber;

    if (isValidLuhn(cardNumber) && hasValidPrefix(cardNumber)) {
        cout << "VALID" << endl;
    } else {
        cout << "BAD" << endl;
    }

    return 0;
}
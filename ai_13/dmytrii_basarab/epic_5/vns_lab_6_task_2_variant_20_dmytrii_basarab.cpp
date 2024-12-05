#include <iostream>
#include <cstring> // Дляgets

using namespace std;

int main() {



    char s[256] = {0};

    cout << "Введіть рядок: ";
    gets(s); // Ввід рядка


    int maxLength = 0;
    int currentLength = 0;


    for (int i = 0;i < 256;i++) {

        if (s[i] != ' ' && s[i] != '.' && s[i] != ',' && s[i] != '\0') {

                currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;

            }            

                currentLength = 0; 
        }

    }


    cout << "Довжина найдовшого слова: " << maxLength << endl;

    return 0;
}

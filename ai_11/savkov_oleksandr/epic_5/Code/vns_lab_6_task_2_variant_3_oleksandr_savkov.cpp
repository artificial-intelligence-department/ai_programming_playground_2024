#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>  

using namespace std;

int main() {
    char solich[256];
    cout << "Введіть рядок, максимум 255 символів" << endl;
    gets(solich);
    char *ones = strtok(solich, " ");

    vector<string> oneEl;

    while (ones != NULL) {
        string tempEd = ones;

       int i = 0;
        for (char ch : tempEd) {
            if (isdigit(ch)) { 
                i++;
            }
        }

       if (i == 1) {
            oneEl.push_back(tempEd);
        }

        ones = strtok(NULL, " ");
    }

    for (int i = 0; i < oneEl.size(); i++) {
        cout << oneEl[i] << endl;
    }

    return 0;
}

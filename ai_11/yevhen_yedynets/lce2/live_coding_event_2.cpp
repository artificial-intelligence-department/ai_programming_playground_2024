#include <iostream>

using namespace std;

bool palindrome(int &distance){
    int n, num, digit, rev = 0;
    num = distance;
    n = num;

    do{
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
        }
    while (num != 0);

    if (n == rev and n > 0){
        return 1;
    }
    else{
        return 0;
    }
}

void user_identifier(string &name){
    char * tab2 = new char [name.length()+1];
    strcpy (tab2, name.c_str());

    int temp;
    for (int i = 0; i < sizeof(tab2) / sizeof(tab2[0]); i++){
        for (int j = i + 1; j < sizeof(tab2) / sizeof(tab2[0]); i++){
            if (tab2[j] < tab2[i]){
                temp = tab2[i];
                tab2[i] = tab2[j];
                tab2[j] = temp;
            }
    }

    for (int i = 0; i < sizeof(tab2) / sizeof(tab2[0]); i++){
        tab2[i] *= 0.4;
    }

}

int main(){
    double bonus = 0;
    int distance;
    string name;

    cout << "Your name: " << endl;
    cin >> name;

    cout << "Distance: " << endl; 
    cin >> distance;

    if (palindrome(distance)){
        bonus += 200;
    }

    user_identifier(name);

    return 0;
}
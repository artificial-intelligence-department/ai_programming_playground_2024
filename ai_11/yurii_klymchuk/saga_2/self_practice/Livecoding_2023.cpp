#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
//Змінна для переводу з ярдів у метри
const float yards_to_meters = (3*12*2.54)/100;

int main() {
    //Записуємо прізвище
    char surname[64];
    cin >> surname;

    //Обраховуємо кількість голосних
    int length_of_name = strlen(surname);
    int golosni = 0;
    for(int i = 0; i < length_of_name; i++){
        if(tolower(surname[i]) == 'a' || tolower(surname[i])== 'e' || tolower(surname[i]) == 'i' ||
        tolower(surname[i]) == 'o' || tolower(surname[i])== 'u' || tolower(surname[i]) == 'y') golosni++;
    }
    
    //записуємо розмір поля і переводимо у метри
    float field_size;
    cin >> field_size;

    field_size *= yards_to_meters;
    
    float width_of_letter = golosni*0.8;

    float middle_start = field_size/2 - 1.5;
    float middle_end = middle_start + 3;
    int index = 0; 
    for (int i = middle_start; i > 0; i -= width_of_letter) { index++; }

    while(index > length_of_name) { index -= length_of_name; }

    cout << "\nMiddle letters from left to right are: ";
    do{
        if (index > length_of_name) { index - length_of_name; }
        cout << surname[index] << " ";
        index++;
        middle_start += width_of_letter;
    }while (middle_start < middle_end);
    return 0;
}
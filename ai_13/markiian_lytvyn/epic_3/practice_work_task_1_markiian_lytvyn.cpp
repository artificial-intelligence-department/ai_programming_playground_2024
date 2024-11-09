#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> list = {    "Тисяча і одна ніч",
                            "Пригоди Геклбері Фіна",
                            "Гаррі Поттер та напівкровний принц",
                            "Аліса в країні див",
                            "Мобідік",
                            "Дон Кіхот",
                            "Одісея",
                            "Гаррі Поттер та дари смерті",
                            "В пошуках Аляски",
                            "Ромео та Джульєтта"};
vector<bool> available = { true, false, false, true, true, true, false, false, true, true };

void listB() {
    cout << "Список книг:\n";
    for (size_t i = 0; i < list.size(); ++i) {
        cout << i + 1 << ". " << list[i] << " - " << (available[i] ? "В наявності" : "Немає в наявності") << endl << endl;}}
void borrowB() {
    cout << "В наявності:\n";
    for (size_t i = 0; i < list.size(); ++i) {
        if (available[i]) {
            cout << i + 1 << ". " << list[i] << endl;}}
    int number;
    cout << "Введіть індекс книги, яку ви хочете обрати: ";
    cin >> number;
    if (number > list.size() || number < 1) {
        cout << "Неправильний індекс." << endl;} 
    else if (!available[number - 1]) {  
        cout << "Цієї книги немає в наявності." << endl;} 
    else {
        available[number - 1] = false;
        cout << "До зустрічі!" << endl << endl;}}
void returnB() {
    int number;
    cout << "Введіть індекс книги, яку ви хочете повернути: ";
    cin >> number;

    if (number < 1 || number > list.size()) {
        cout << "Неправильний індекс." << endl;} 

    else if (available[number - 1]) {
        cout << "Ця книга вже в бібліотеці!" << endl;} 
        
    else {
        available[number - 1] = true;
        cout << "До зустрічі!" << endl << endl;}}
int main() {

    int option;
    char choice;

    do {
        cout << "\n Меню:\n 1. Список книг\n 2. Взяти книгу\n 3. Повернути книгу\n 4. Вийти\n Виберіть варіант: ";
        cin >> option;

        switch (option) {
            case 1:
            Menu:
                listB();
                break;

            case 2:
                borrowB();
                break;

            case 3:
                returnB();
                break;

            case 4:
                cout << "До зустрічі!" << endl;
                return 0;

            default:
                cout << "Неправильний вибір." << endl;
                goto Menu;}

        cout << "Продовжити? (1/0): ";
        cin >> choice;} 
    while (choice == '1');
    return 0;}
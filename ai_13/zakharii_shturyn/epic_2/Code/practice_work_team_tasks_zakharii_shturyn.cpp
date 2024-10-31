#include <iostream>
using namespace std;

int check(string Weather, string arr[]) {
    for(int i = 0; i < 5; i++) {
        if(arr[i] == Weather) {
            return i;
        }
    }
    return -1;
}

string coat(string Weather) {
    if(Weather == "snowy" || Weather == "rainy") {
        return "Варто надіти куртку!";
    } else{
        return "Куртка сьогодні Вам не знадобиться!";
    }
}

string activity(string Weather) {
    if(Weather == "sunny"){
        return "Чудовий день для пікніка!";
    } else if(Weather == "rainy"){
        return "Ідеальна погода, щоб читати книгу всередині!";
    } else if(Weather == "cloudy"){
        return "Може, відвідати музей?";
    } else if(Weather == "snowy"){
        return "Як щодо того, щоб зліпити сніговика?";
    } else if(Weather == "windy"){
        return "Запустіть повітряного змія, якщо він у вас є!";
    }
    return 0;
}

string shoes(int index) {
    switch(index) {
        case 0:
            return "Взуй улюблені кросівки!";
            break;
        case 1:
            return "Дощові чоботи - гарна ідея!";
            break;
        case 2:
            return "Сьогодні підходить будь-яке взуття.";
            break;
        case 3:
            return "Снігові черевики зігріють ваші ноги!";
            break;
        case 4:
            return "Одягніть щось міцне!";
            break;
        default:
            break;
    }
    return 0;
}

int main() {

    int index = -1;
    string Weather;
    cout << "Enter weather: ";
    cin >> Weather;
    string arr[5] = {"sunny", "rainy", "cloudy", "snowy", "windy"};


    index = check(Weather, arr);
        if(index > -1) {
        cout << coat(Weather) << endl;
        cout << activity(Weather) << endl;
        cout << shoes(index) << endl;
    } else {
        cout << "Invalid data.Try again" << endl;
    }


    return 0;
}
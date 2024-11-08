#include <iostream>
#include <string>

using namespace std;

int main() {
    string weather;
    cout << "Введіть поточні погодні умови (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

    // Рішення щодо куртки
    string jacketAdvice;
    if (weather == "snowy" || weather == "rainy") {
        jacketAdvice = "Візьміть куртку!";
    } else {
        jacketAdvice = "Куртка не потрібна.";
    }

    // Рекомендація щодо активності
    string activityAdvice;
    if (weather == "sunny") {
        activityAdvice = "Чудовий день для пікніка!";
    } else if (weather == "rainy") {
        activityAdvice = "Ідеальна погода, щоб читати книгу всередині!";
    } else if (weather == "cloudy") {
        activityAdvice = "Може, відвідати музей?";
    } else if (weather == "snowy") {
        activityAdvice = "Як щодо того, щоб зліпити сніговика?";
    } else if (weather == "windy") {
        activityAdvice = "Запустіть повітряного змія, якщо він у вас є!";
    } else {
        activityAdvice = "Будь ласка, введіть дійсні погодні умови.";
        jacketAdvice = ""; // В такому випадку не виводимо поради щодо куртки
    }

    // Рекомендація щодо взуття (використання switch case)
    int weatherType;
    if (weather == "sunny") {
        weatherType = 1;
    } else if (weather == "rainy") {
        weatherType = 2;
    } else if (weather == "cloudy") {
        weatherType = 3;
    } else if (weather == "snowy") {
        weatherType = 4;
    } else if (weather == "windy") {
        weatherType = 5;
    } else {
        weatherType = 0; // Недійсне значення
    }

    string footwearAdvice;
    switch (weatherType) {
        case 1:
            footwearAdvice = "Взуй улюблені кросівки!";
            break;
        case 2:
            footwearAdvice = "Дощові чоботи - гарна ідея!";
            break;
        case 3:
            footwearAdvice = "Сьогодні підходить будь-яке взуття.";
            break;
        case 4:
            footwearAdvice = "Снігові черевики зігріють ваші ноги!";
            break;
        case 5:
            footwearAdvice = "Одягніть щось міцне!";
            break;
        default:
            footwearAdvice = ""; // Не виводити взуття для недійсних погодних умов
            break;
    }

    // Виводимо рекомендації користувачеві
    if (!jacketAdvice.empty()) {
        cout << jacketAdvice << endl;
    }
    cout << activityAdvice << endl;
    if (!footwearAdvice.empty()) {
        cout << footwearAdvice << endl;
    }

    return 0;
}

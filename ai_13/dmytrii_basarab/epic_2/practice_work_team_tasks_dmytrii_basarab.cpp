#include <iostream>
#include <string>

using namespace std;

enum type{sunny, rainy, cloudy, snowy, windy};

type getWeather( string& weather) {
  if (weather == "sunny") return sunny;
  if (weather == "rainy") return rainy;
  if (weather == "cloudy") return cloudy;
  if (weather == "snowy") return snowy;
  if (weather == "windy") return windy;
};

int main() {
    string weather;

 

    cout << "Input weather (sunny, rainy, cloudy, snowy, windy): ";
    cin >> weather;

  if (weather =="sunny" || weather =="rainy" || weather =="cloudy" || weather =="snowy" || weather =="windy") {

    if (weather == "snowy" || weather == "rainy") {
        cout << "Одягни куртку" << endl;
    } else {
        cout << "Куртка не потрібна" << endl;
    }



    if (weather == "sunny") {
      cout << "Чудовий день для пікніка!" << endl;
    } else if (weather == "rainy") {
      cout << "Ідеальна погода, щоб почитати книгу всередині" << endl;
    } else if (weather == "cloudy") {
      cout << "Може, відвідати музей?" << endl;
    } else if (weather == "snowy") {
      cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else { //windy
      cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }



  /*switch не може використати string то робим функцію шоб
   видавала ,відповідно до введеного, ретурн
   і значення яке вставим в switch*/  
  type word = getWeather(weather);
   switch (word) {

      case sunny:
        cout << "Взуй улюблені кросівки!" << endl;
      break;
      case rainy:
        cout << "Дощові чоботи - гарна ідея!" << endl;
      break;
      case cloudy:
        cout << "Сьогодні підходить будь-яке взуття." << endl;
      break;
      case snowy:
        cout << "Снігові черевики зігріють ваші ноги!" << endl;
      break;
      case windy:
        cout << "Одягніть щось міцне!" << endl;
      break;
    }
  } else {
    cout << "write again" << endl;
    return 0;
  }

    return 0;
}

  #include <iostream>
#include <windows.h>
using namespace std;


int main(){
    string weather;
    int footwear;
    cout << "Введіть погоду на вулиці" << endl << "(sunny,rainy,cloudy,snowy,windy):" << " ";
    cin >> weather;
    if (weather == "rainy" || weather == "snowy") {
        cout << "Одягніть куртку." << endl;
    } else {
        cout << "Куртку вдягати не потрібно." << endl;
    }
    if (weather == "sunny"){
        cout << "Чудовий день для пікніка!" << endl;
    } else if (weather == "rainy"){
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl;
    } else if (weather == "cloudy"){
        cout << "Може, відвідати музей?" << endl;
    } else if (weather == "snowy"){
        cout << "Як щодо того, щоб зліпити сніговика?" << endl;
    } else if (weather == "windy"){
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl;
    }
    if (weather == "sunny"){
        footwear = 1;
    } else if (weather == "rainy"){
        footwear = 2;
    } else if (weather == "cloudy"){
        footwear = 3;
    } else if (weather == "snowy"){
        footwear = 4;
    } else if (weather == "windy"){
        footwear = 5;
    }
    switch (footwear)
	{
	case 1:
		cout << "Взуй улюблені кросівки!" << endl;
		break;
	case 2:
		cout << "Дощові чоботи - гарна ідея!" << endl;
		break;
	case 3:
		cout << "Сьогодні підходить будь-яке взуття." << endl;
		break;
	case 4:
		cout << "Снігові черевики зігріють ваші ноги!" << endl;
		break;
	case 5:
		cout << "Одягніть щось міцне!" << endl;
		break;
    }
    system("pause");
    return 0;
}
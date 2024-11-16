#include <iostream>

using namespace std;

int main()
{
    enum Weather  // оголошуємо енумератор для станів погоди
    {
        Sunny,
        Rainy,
        Cloudy,
        Snowy,
        Windy
    };

    int state;  // оголошуємо змінну для стану погоди сьогодні

    cout << "Введіть сьогоднішню погоду(1.Sunny/2.Rainy/3.Cloudy/4.Snowy/5.Windy): ";
    cin >> state;  // вводимо сьогоднішній стан погоди

    switch (state)  // присвоюємо змінній стан погоди
    {
        case 1:
        {
            state = Sunny;
            break;
        }
        case 2:
        {
            state = Rainy;
            break;
        }
        case 3:
        {
            state = Cloudy;
            break;
        }
        case 4:
        {
            state = Snowy;
            break;
        }
        case 5:
        {
            state = Windy;
            break;
        }
        default:  // якщо стану немає в енумераторі, просимо ввести інакший
        {
            cout << "Введіть валідне значення." << endl;
            return 0;
        }
    }

    cout << endl << "Чи потрібно вдягнути куртку?" << endl;

    if (state == Rainy)  // перевіряємо за станами, чи потрібно вдягнути куртку
    {
        cout << "Так, сьогодні потрібно вдягнути куртку." << endl;
    }
    else if (state == Snowy)
    {
        cout << "Так, сьогодні потрібно вдягнути куртку." << endl;
    }
    else
    {
        cout << "Ні, не потрібно." << endl;
    }

    cout << "Рекомендації щодо активності на сьогодні: " << endl;

    if (state == Sunny)  // перевіряючи за станами погоди, рекомендуємо, що робити сьогодні
    {
        cout << "Чудовий день для пікніка!" << endl; 
    }
    else if (state == Rainy)
    {
        cout << "Ідеальна погода, щоб читати книгу всередині!" << endl; 
    }
    else if (state == Cloudy)
    {
        cout << "Може, відвідати музей?" << endl; 
    }
    else if (state == Snowy)
    {
        cout << "Як щодо того, щоб зліпити сніговика?" << endl; 
    }
    else if (state == Windy)
    {
        cout << "Запустіть повітряного змія, якщо він у вас є!" << endl; 
    }

    cout << "Рекомендації щодо взуття: " << endl;

    switch (state)  // за допомогою перевірки, радимо, що взути сьогодні
    {
        case Sunny:
        {
            cout << "Взуй улюблені кросівки!" << endl;
            break;
        }
        case Rainy:
        {
            cout << "Дощові чоботи - гарна ідея!" << endl;
            break;
        }
        case Cloudy:
        {
            cout << "Сьогодні підходить будь-яке взуття." << endl;
            break;
        }
        case Snowy:
        {
            cout << "Снігові черевики зігріють ваші ноги!" << endl;
            break;
        }
        case Windy:
        {
            cout << "Одягніть щось міцне!" << endl;
            break;
        }
    }

    return 0;
    
}
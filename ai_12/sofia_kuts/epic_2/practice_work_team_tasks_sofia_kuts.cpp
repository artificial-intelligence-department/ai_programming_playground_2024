#include <iostream>
#include <string>

int main() {
    std::string weather;
    
    // Введення користувачем поточної погоди
    std::cout << " Яка зараз погода ?( введіть щось одне з : rainy, snowy, sunny, windy, cloudy ): ";
    std::cin >> weather;

    // Перевірка, чи потрібно одягати куртку
    if (weather == "rainy" || weather == "snowy") {
        std::cout << "Одягніть куртку!" << std::endl;
    } else {
        std::cout << " Можете не одягати куртку! " << std::endl;
    }

    // Рекомендації щодо активностей
    if (weather == "sunny") {
        std::cout << "Чудовий день для пікніка!" << std::endl;
    } else if (weather == "rainy") {
        std::cout << "Ідеальна погода, щоб читати книгу всередині!" << std::endl;
    } else if (weather == "cloudy") {
        std::cout << "Може, відвідати музей?" << std::endl;
    } else if (weather == "snowy") {
        std::cout << "Як щодо того, щоб зліпити сніговика?" << std::endl;
    } else if (weather == "windy") {
        std::cout << "Запустіть повітряного змія, якщо він в  вас є!" << std::endl;
    }
        return 0;
    

    // Рекомендація щодо взуття (з використанням switch case)
    std::cout << "Рекомендація щодо взуття: ";
    switch (weather[0]) {
        case 's': // sunny або snowy
            if (weather == "sunny") {
                std::cout << "Взуй улюблені кросівки!" << std::endl;
            } else if (weather == "snowy") {
                std::cout << "Снігові черевики зігріють ваші ноги!" << std::endl;
            }
            break;
        case 'r': // rainy
            std::cout << "Дощові чоботи - гарна ідея!" << std::endl;
            break;
        case 'c': // cloudy
            std::cout << "Сьогодні підходить будь-яке взуття." << std::endl;
            break;
        case 'w': // windy
            std::cout << "Одягніть щось міцне!" << std::endl;
            break;
        default:
                std::cout << "Невідома погода." << std::endl;
                break;
    }

    return 0;
}

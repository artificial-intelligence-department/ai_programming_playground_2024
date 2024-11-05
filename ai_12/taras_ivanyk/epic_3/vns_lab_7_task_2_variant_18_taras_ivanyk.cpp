#include <iostream>
#include <string>

std::string get(int year) {
    const std::string years[] = {
        "Щур", "Бик", "Тигр", "Кролик", "Дракон", "Змія",
        "Кінь", "Коза", "Мавпа", "Півень", "Собака", "Кабан"
    };
    int index = (year - 4) % 12;
    return years[index];
}
std::string get(const std::string& month) {
    if (month == "January" || month == "February") return "Водолій";
    if (month == "February" || month == "March") return "Риби";
    if (month == "March" || month == "April") return "Овен";
    if (month == "April" || month == "May") return "Телець";
    if (month == "May" || month == "June") return "Близнюки";
    if (month == "June" || month == "July") return "Рак";
    if (month == "July" || month == "August") return "Лев";
    if (month == "August" || month == "September") return "Діва";
    if (month == "September" || month == "October") return "Терези";
    if (month == "October" || month == "November") return "Скорпіон";
    if (month == "November" || month == "December") return "Стрілець";
    if (month == "December" || month == "January") return "Козеріг";
    
    return "Unknown month";
}

int main() {
 
    std::cout << "Enter a year: ";
    int year;
    std::cin >> year;
    std::cout << "Ваш рік за старояпонським календарем, це: " << get(year) << std::endl;

    std::cout << "Enter a month ";
    std::string month;
    std::cin >> month;
    std::cout << "Ваш знак зодіаку: " << get(month) << std::endl;

    return 0;
}

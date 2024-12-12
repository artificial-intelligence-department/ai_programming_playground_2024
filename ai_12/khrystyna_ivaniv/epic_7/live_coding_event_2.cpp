/**
 * Ви отримали своє перше завдання на новій роботі програмістом у
 * міжнародній логістичній компанії, що здійснює доставку між відділеннями.
 * Раніше офіси компанії працювали незалежно і лише в межах однієї країни,
 * але компанія запустила послугу "Комбінована доставка" і тепер розрахунок вартості
 * відбувається згідно тарифікації, що зберігається у файлах.
 * Все б нічого, але офіси використовують 3 різні системи вимірювання відстані:
 * - імперська (британська миля) == 1 609.344 метра; // mi
 * - миля США (US survey mile) == 1 609.347 метра; // mi_US
 * - метрична система виміру == 1 метр. // m
 *
 * Розробити програму для розрахунку вартості доставки,
 * яка буде використовувати ідентифікатор користувача та накопичувати відстані.
 * Компанія встановила наступні бонуси:
 * Якщо відстань відправлення є паліндромом, то користувач отримує +200 км бонусів.
 * Кожні накопичені 100км це 1$ знижки. Після використання накопичена відстань зменшується.
 * При обрахунку вартості запропонувати користувачу скористатись конвертацією накопичених бонусів.


 * Для формування ідентифікатора користувача використати наступний розрахунок:
    1. Відсортувати буĸви вашого імені за зростанням.
    2. Створити одновимірний масив на основі цілочисельного(int) значення
    символів (ASCII Value) помноженого на 0.4.

    Результат записати.
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

bool is_palindrome(int number)
{

   int origin_number = number;
   int reverse = 0;
   int carry;
   while (number != 0)
   {
      carry = number % 10;
      reverse = reverse * 10 + carry;
      number /= 10;
   }
   return reverse == origin_number;
}

double simulate_money_precision(double value)
{
   return round(value * 100.0) / 100.0;
}

double convert_to_meters(double distance, char *type)
{
   if (strcmp(type, "meter") == 0)
   {
      return distance;
   }
   else if (strcmp(type, "mile") == 0)
   {
      return distance * 1609.344;
   }

   else if (strcmp(type, "mile_us") == 0)
   {
      return distance * 1609.347;
   }

   else
   {
      cout << "Ви вказали некоректний тип даних";
      return 1;
   }
   return 0.0;
}

void sort_main(char name[], int len)
{
   for (int i = 0; i < len - 1; i++)
   {
      for (int j = 0; j < len - 1 - i; j++)
      {
         if (name[j] > name[j + 1])
         {
            char temp = name[j];
            name[j] = name[j + 1];
            name[j + 1] = temp;
         }
      }
   }
}
// void id(char *name)
// {
//    name * 0.4;
// }

int main()
{
   string user_name;
   int lenght = user_name.length();
   char name[lenght + 1];
   for (int i = 0; i < lenght; i++)
   {
      name[i] = user_name[i];
   }

   double distance_value;
   string measurement_system;
   bool convert_bonus;

   cout << "Введіть ваше ім'я: ";
   cin >> user_name;

   cout << "Введіть відстань: ";
   cin >> distance_value;

   cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
   cin >> measurement_system;
   cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
   cin >> convert_bonus;

   // cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
   // cout << "Ваша знижка: " << discount << "$" << endl;
   // cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
   // cout << "Вартість відправки: " << totalPrice << "$" << endl;

   return 0;
}
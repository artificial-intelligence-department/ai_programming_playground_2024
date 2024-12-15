#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const int var = 37;            // одна цілочисельна константа
bool is_palindrome(int number) // параметри та аргументи функції
{

   int origin_number = number;
   int reverse = 0;
   int carry;
   while (number != 0) // while цикл
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

double convert_to_meters(double distance, char *type) //вказівники
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
      cout << "Ви вказали некоректний тип даних" << endl;
      return 1;
   }

   return 0.0;
}

void sort_main(char name[], int len)
{
   for (int i = 0; i < len - 1; i++)
   {
      for (int j = 0; j < len - 1 - i; j++) // for цикл

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
   int length = user_name.length(); // цілочисельна змінна
   char name[length + 1];           // одновимірний масив
   for (int i = 0; i < length; i++)
   {
      name[i] = user_name[i];
   }

   ofstream out_file("user.txt"); //функції роботи з файлами, для того, щоб записати у файл
   out_file << user_name;
   out_file.close();

   ifstream in_file("user.txt"); //функції роботи з файлами, для того, щоб зчитати з файлу
   while (in_file)
   {
      string line;
      while (getline(in_file, line))
      {
         cout << line << endl;
      }
   }
   in_file.close();

   float distance_value; // дійсна змінна
   string measurement_system;
      int length1 = measurement_system.length(); // цілочисельна змінна
   char measurement_system_char[length1 + 1];           // одновимірний масив
   for (int i = 0; i < length1; i++)
   {
      measurement_system_char[i] = measurement_system[i];
   }
measurement_system_char[length1] = '\0';

   bool convert_bonus;

   cout << "Введіть ваше ім'я: "; // оператори виведення та введення даних
   cin >> user_name; //оператори виведення та введення даних

   cout << "Введіть відстань: ";
   cin >> distance_value;

   cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
   cin >> measurement_system;
   cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
   cin >> convert_bonus;

   is_palindrome(int(distance_value)); // параметри та аргументи функції	

       int bonuses = 0;
   // умовні оператори та розгалуження
   if (is_palindrome)
   {
      bonuses += 2000;
   }

   bonuses /= 1000;
   int carry;
   int discount = 0;
   if (convert_bonus)
   {
      carry = bonuses % 100; // математичні операції та математичні функції
      discount = bonuses % 100;
   }

   double total_price = convert_to_meters(distance_value, measurement_system_char) * 0.5; // дійсна змінна з подвійною точністю
   // ціна за кожен метр

double deliveryDistanceInKiloMeters = double(distance_value) / 1000;

   total_price = total_price - discount;
   cout << "Відстань поточної доставки: " << convert_to_meters << "m" << endl;
   cout << "Ваша знижка: " << discount << "$" << endl;
   cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "km" << endl;
   cout << "Вартість відправки: " << total_price << "$" << endl;

   return 0;
}

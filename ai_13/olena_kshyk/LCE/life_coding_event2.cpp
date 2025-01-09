#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

const double mi = 1609.344;
const double mi_us = 1609.347;

double simulateMoneyPrecision(double value)
{
    return std::round(value * 100.0) / 100.0;
}

double switch_m_systems(double d, string m)
{
    if (m == "mile")
    {
        return d * mi;
    }
    else if (m == "mile_us")
    {
        return d * mi_us;
    }
    else
    {
        return d;
    }
}

void bubble_sort(string &s)
{
    int n = s.size();
    bool sw;
    for (int i = 0; i < n - 1; i++)
    {
        sw = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
            }
        }
        if (!sw)
        {
            break;
        }
    }
}

bool palindrome(string num, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (num[start] != num[end])
    {
        return false;
    }

    return palindrome(num, start + 1, end + 1);
}

int main()
{
    string userName, measurementSystem;
    double distanceValue;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    string copy_username = userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;
    distanceValue = switch_m_systems(distanceValue, measurementSystem);
    string dist = to_string(int(distanceValue));
    bool pal = palindrome(dist, 0, dist.size() - 1);

    int *user_id = new int[userName.length()];
    string str_user_id = "";
    bubble_sort(userName);
    for (int i = 0; i < userName.size(); i++)
    {
        user_id[i] = int((userName[i] - '0') * 0.4);
        str_user_id += to_string(user_id[i]);
    }

    ifstream file1("collected_distance.txt");
    string line, word;
    bool t = false;
    int curr_bonus = 0;
    while (getline(file1, line))
    {
        stringstream ss(line);
        for (int i = 0; i < 3; i++)
        {
            getline(ss, word, ' ');
            if (i == 0 && word == copy_username)
            {
                t = true;
            }
            else
            {
                t = false;
                break;
            }
            if (i == 1 && word == str_user_id)
            {
                t = true;
            }
            else
            {
                t = false;
                break;
            }
            if (i == 2)
            {
                curr_bonus = stoi(word);
            }
        }
    }
    file1.close();

    int discount = curr_bonus / 100;

    char convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;
    if (convertBonus == 'y')
    {
        curr_bonus -= discount * 100;
    }
    else
    {
        discount = 0;
    }

    int price = distanceValue * 0.0005 - discount;
    curr_bonus += pal * 200 + distanceValue / 1000;
    ofstream file2("collected_distance.txt");
    if (!t)
    {
        file2 << copy_username << " " << str_user_id << " " << to_string(curr_bonus) << endl;
    }

    cout << "Відстань поточної доставки: " << distanceValue << "m" << endl;
    cout << "Ваша знижка: " << discount << "$" << endl;
    cout << "Накопичена відстань: " << curr_bonus << "km" << endl;
    cout << "Вартість відправки: " << price << "$" << endl;

    file1.close();
    return 0;
}
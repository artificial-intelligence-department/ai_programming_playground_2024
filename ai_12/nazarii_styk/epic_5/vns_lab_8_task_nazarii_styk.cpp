// Variant 19
#include <iostream>

using namespace std;

struct Film
{
    string name;
    string director;
    string country;
    double profit;
};

int main()
{
    Film films[3] = {
        {"The Shawshank Redemption", "Frank Darabont", "USA", 58.3},
        {"The Godfather", "Francis Ford Coppola", "USA", 246},
        {"The Dark Knight", "Christopher Nolan", "USA", 1000}};
    string name = "The Godfather";
    Film newFilm = {"The Godfather: Part II", "Francis Ford Coppola", "USA", 48};
    int n = 3;
    
    for (int i = 0; i < n; i++)
    {
        cout << films[i].name << " " << films[i].director << " " << films[i].country << " " << films[i].profit << endl;
    }
    cout << endl;

    n -= 2;
    films[n] = newFilm;
    for (int i = 0; i < n; i++)
    {
        cout << films[i].name << " " << films[i].director << " " << films[i].country << " " << films[i].profit << endl;
    }


    

    return 0;
}
// 19. Структура "Фільм":
// - назва;
// - режисер;
// - країна;
// - прибуток.
// Знищити 2 елементи з кінця файлу, додати елемент після елемента із зазначеною назвою.
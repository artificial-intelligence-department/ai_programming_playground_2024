#include <iostream>
#include <vector>
using namespace std;

int main() {

    int Students, Teams;
    cin >> Students >> Teams;
   
    vector<int> tmp(Students,1);    //Створюємо початковий масив, де в "кожній клманда" один учасник
    if(Students <= Teams * 3 && Students >= Teams) {    //перевіряємо умову, якщо студентів менше команд, то неможливо, якщо студентів ільше 3 на одну команду то теж неможоиво
        for(int i = tmp.size() - 1; i >= 0; i--) {
            for(int j = tmp.size() - 1; j > i; j--) {
                int a = tmp[i];
                int b = tmp[j];
                if(a + b <= 3 && tmp.size() != Teams){ 
                    tmp[i] = a + b;     //групуємо суму двох елементів в один, за умови, якщо вони менші-рівні за 3  
                    tmp.erase(tmp.begin() + j);
                } else if(tmp.size() == Teams) {    //перевіряємо чи наявні дані вже не задовілбняють умову
                    break;
                }
            }
        }
        for(int elm : tmp) {
            cout << elm << " ";
        }
    } else{
        cout << "Impossible";
    }


    return 0;
}
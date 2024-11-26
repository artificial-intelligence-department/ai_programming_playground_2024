#include <iostream>
#include <vector>
using namespace std;

struct Car{
    char brand[50];
    int year;
    int price;
    char color[50];
};

// функція формування файлу
void createFile(const char *filename){
    FILE* f;

    f = fopen(filename, "wb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    int N;
    cout << "Введіть кількість автомобілей: ";
    cin >> N;

    Car c; 

    for (int i=0; i<N; i++){
        cout << "Введіть назву марки: ";
        cin >> c.brand;
        cout << "Введіть рік випуску: ";
        cin >> c.year;
        cout << "Введіть ціну: ";
        cin >> c.price;
        cout << "Введіть колір: ";
        cin >> c.color;

        fwrite(&c, sizeof(Car), 1, f);
        if(ferror(f)){
            cout << "Помилка під час запису у файл";
            exit(2);
        }
    }
    fclose(f);
}

// функція друку
void printFile(const char *filename){
    FILE* f;

    f = fopen(filename, "rb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    Car c;

    cout << endl << "Вмістиме файлу: " << endl << "__________________________________" << endl;

    while (fread(&c, sizeof(Car), 1, f)) {
        cout << "Марка: " << c.brand << endl;
        cout << "Рік випуску: " << c.year << endl;
        cout << "Ціна: " << c.price << endl;
        cout << "Колір: " << c.color << endl;
        cout << "__________________________________" << endl;
        }
    fclose(f);
}    

// функція додвання 
void addNewCar(const char *filename){
    FILE* f;

    f = fopen(filename, "rb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(2);
    }

    vector<Car> cars;
    Car c;

    while (fread(&c, sizeof(Car), 1, f)){
        cars.push_back(c);
    }

    fclose(f);

    f = fopen(filename, "wb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(3);
    }

    cout << "Введіть дані нового автомобіля: " << endl << "Введіть назву марки: ";
    cin >> c.brand;
    cout << "Введіть рік випуску: ";
    cin >> c.year;
    cout << "Введіть ціну: ";
    cin >> c.price;
    cout << "Введіть колір: ";
    cin >> c.color;

    fwrite(&c, sizeof(Car), 1, f);
    if(ferror(f)){
        cout << "Помилка під час запису у файл";
        exit(4);
    }

    for (const auto& car : cars) {
        fwrite(&car, sizeof(Car), 1, f);
    }
    if(ferror(f)){
        cout << "Помилка під час запису у файл";
        exit(5);
    }
    fclose(f);
}

// фукнція знищення
void deleteCar(const char *filename, int yr){
    FILE* f;

    f = fopen(filename, "rb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(1);
    }

    vector<Car> cars;
    Car c;

    while (fread(&c, sizeof(Car), 1, f)){
        cars.push_back(c);
    }
    fclose(f);

    vector<Car> filteredByYear;
    for(const auto& car : cars){
        if(car.year >= yr){
            filteredByYear.push_back(car);
        }
    }

    f = fopen(filename, "wb");
    if(f==NULL){
        cout << "Помилка при відкритті файлу";
        exit(2);
    }

    for (const auto& car : filteredByYear) {
        fwrite(&car, sizeof(Car), 1, f);
    }

    if(ferror(f)){
        cout << "Помилка під час запису у файл";
        exit(3);
    }

    fclose(f);
}

int main(){
    const char* filename = "cars.dat";
    int yr;

    createFile(filename);
    printFile(filename);
    addNewCar(filename);
    printFile(filename);
    cout << "Вкажіть рік: ";
    cin >> yr;
    cout << endl << "Знищено автомобілі, рік випуску яких менше заданого.";
    deleteCar(filename, yr);
    printFile(filename);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
};

struct Person {
    string name;
    int age;
    Address address;
};

void inputPerson(Person* people, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введіть ім'я для людини " << i + 1 << ": ";
        cin >> people[i].name;
        cout << "Введіть вік для людини " << i + 1 << ": ";
        cin >> people[i].age;
        cout << "Введіть місто для людини " << i + 1 << ": ";
        cin >> people[i].address.city;
    }
}

void display(const Person* people, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Людина " << i + 1 << ": " << people[i].name << ", Вік: " << people[i].age
             << ", Адреса: " << people[i].address.city << endl;
    }
}

void sortAge(Person* people, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (people[j].age > people[j + 1].age) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Введіть кількість людей: ";
    cin >> size;

    Person* people = new Person[size];
    inputPerson(people, size);

    cout << "\nДо сортування:\n";
    display(people, size);

    sortAge(people, size);

    cout << "\nПісля сортування за віком:\n";
    display(people, size);

    delete[] people;

    return 0;
}

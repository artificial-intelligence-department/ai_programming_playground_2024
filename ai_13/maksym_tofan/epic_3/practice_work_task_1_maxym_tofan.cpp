#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBooks(const vector<string>& books, const vector<bool>& availability) {
    cout << "Список книг:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i] << " - " << (availability[i] ? "доступна" : "позичена") << endl;
    }
}

void borrowOrReturnBook(vector<bool>& availability, bool isBorrowing) {
    int bookNumber;
    cout << "Введіть номер книги, яку хочете " << (isBorrowing ? "позичити: " : "повернути: ");
    cin >> bookNumber;

    if (bookNumber < 1 || bookNumber > availability.size()) {
        cout << "Неправильний вибір, спробуйте ще раз.\n";
        return;
    }

    if (isBorrowing && !availability[bookNumber - 1]) {
        cout << "Ця книга вже позичена.\n";
    } else if (!isBorrowing && availability[bookNumber - 1]) {
        cout << "Ця книга не позичена.\n";
    } else {
        availability[bookNumber - 1] = !isBorrowing;
        cout << "Ви " << (isBorrowing ? "позичили" : "повернули") << " книгу.\n";
    }
}

int main() {
    vector<string> books = {"The Great Gatsby", "1984", "To Kill a Mockingbird", "The Catcher in the Rye"};
    vector<bool> availability = {true, true, true, true};
    int choice;

    while (true) {
        cout << "\nМеню:\n1. Список всіх книг\n2. Позичити книгу\n3. Повернути книгу\n4. Вийти\nВаш вибір: ";
        cin >> choice;

        if (choice == 1) {
            displayBooks(books, availability);
        } else if (choice == 2) {
            borrowOrReturnBook(availability, true);
        } else if (choice == 3) {
            borrowOrReturnBook(availability, false);
        } else if (choice == 4) {
            cout << "Програма завершена.\n";
            break;
        } else {
            cout << "Неправильний вибір, спробуйте ще раз.\n";
        }
    }

    return 0;
}

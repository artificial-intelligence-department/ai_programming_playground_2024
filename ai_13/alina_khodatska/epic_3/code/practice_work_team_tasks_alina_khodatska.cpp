#include <iostream>
#include <vector>
#include <string>

void listBooks(const std::vector<std::string>& books, const std::vector<bool>& availability) {  // оголошення та передача пареметру функції 
    std::cout << "List of books:\n";
    for (size_t i = 0; i < books.size(); ++i) {   // цикл for для виведення списку книг
        std::cout << i + 1 << ". " << books[i] << (availability[i] ? " (available)\n" : " (borrowed)\n");
    }
}

void updateBookStatus(std::vector<bool>& availability, bool borrow) {   // оголошення та передача пареметру функції
    int bookNumber;
    std::cout << "Enter the number of the book you want to " << (borrow ? "borrow" : "return") << ": ";
    std::cin >> bookNumber;

    if (bookNumber > 0 && bookNumber <= static_cast<int>(availability.size())) {   // оператор if else для перевірки введеного номера книги
        if (availability[bookNumber - 1] == borrow) {
            availability[bookNumber - 1] = !borrow;
            std::cout << "You have successfully " << (borrow ? "borrowed" : "returned") << " the book.\n";
        }
        else {
            std::cout << "This book is already " << (borrow ? "borrowed" : "available") << ".\n";
        }
    }
    else {
        std::cout << "Invalid book number.\n";
    }
}

int main() {
    std::vector<std::string> books = { "Book 1", "Book 2", "Book 3", "Book 4" };   // оголошення та ініціалізація вектора
    std::vector<bool> availability(books.size(), true);   // оголошення та ініціалізація вектора

    while (true) {   // цикл while 
        int choice;  // оголошення змінної
        std::cout << "\nMain Menu:\n";
        std::cout << "1. List all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            listBooks(books, availability);  // виклик функції
            break;
        case 2:
            updateBookStatus(availability, true); // виклик функції
            break;
        case 3:
            updateBookStatus(availability, false);	// виклик функції
            break;
        case 4:
            std::cout << "Thank you for using our library!\n";
            return 0;   // фунФункція main повертає значення 0 при завершенні роботи програми
        default:
            std::cout << "Invalid choice, please try again.\n";
            break;   //оператор break для виходу з оператора switch
        }
    }
}

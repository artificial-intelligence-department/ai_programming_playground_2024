#include <iostream>
#include <vector>
#include <string>

void listBooks(const std::vector<std::string>& books, const std::vector<bool>& availability) {
    std::cout << "List of books:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << i + 1 << ". " << books[i];
        if (availability[i]) {
            std::cout << " (available)\n";
        }
        else {
            std::cout << " (borrowed)\n";
        }
    }
}

void borrowBook(std::vector<bool>& availability) {
    int bookNumber;
    std::cout << "Enter the number of the book you want to borrow: ";
    std::cin >> bookNumber;
    if (bookNumber > 0 && bookNumber <= static_cast<int>(availability.size())) {
        if (availability[bookNumber - 1]) {
            availability[bookNumber - 1] = false;
            std::cout << "You have successfully borrowed the book.\n";
        }
        else {
            std::cout << "This book is already borrowed.\n";
        }
    }
    else {
        std::cout << "Invalid book number.\n";
    }
}

void returnBook(std::vector<bool>& availability) {
    int bookNumber;
    std::cout << "Enter the number of the book you want to return: ";
    std::cin >> bookNumber;
    if (bookNumber > 0 && bookNumber <= static_cast<int>(availability.size())) {
        if (!availability[bookNumber - 1]) {
            availability[bookNumber - 1] = true;
            std::cout << "You have successfully returned the book.\n";
        }
        else {
            std::cout << "This book is already available.\n";
        }
    }
    else {
        std::cout << "Invalid book number.\n";
    }
}

int main() {
    std::vector<std::string> books = { "Book 1", "Book 2", "Book 3", "Book 4" };
    std::vector<bool> availability(books.size(), true);

    bool continueProgram = true;

    do {
        int choice;

        std::cout << "\nMain Menu:\n";
        std::cout << "1. List all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            listBooks(books, availability);
            break;
        case 2:
            borrowBook(availability);
            break;
        case 3:
            returnBook(availability);
            break;
        case 4:
            continueProgram = false;
            break;
        default:
            std::cout << "Invalid choice, please try again.\n";
            goto mainMenu;
        }

        if (!continueProgram) {
            break;
        }

        char anotherOperation;
        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> anotherOperation;
        if (anotherOperation == 'n' || anotherOperation == 'N') {
            continueProgram = false;
        }

    mainMenu:
        continue;
    } while (continueProgram);

    std::cout << "Thank you for using our library!\n";
    return 0;
}

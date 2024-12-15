#include <iostream>
#include <vector>
#include <string>

void displayBooks(const std::vector<std::string> &books)
{
    std::cout << "\nList of Books:" << std::endl;
    for (const auto &book : books)
    {
        std::cout << "- " << book << std::endl;
    }
}

bool bookExists(const std::vector<std::string> &books, const std::string &bookName)
{
    for (const auto &book : books)
    {
        if (book == bookName)
        {
            return true;
        }
    }
    return false;
}

void removeBook(std::vector<std::string> &books, const std::string &bookName)
{
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (*it == bookName)
        {
            books.erase(it);
            return;
        }
    }
}

void addBook(std::vector<std::string> &books, const std::string &bookName)
{
    books.push_back(bookName);
}

int main()
{
    std::vector<std::string> books = {"Book1", "Book2", "Book3", "Book4"};
    std::vector<std::string> borrowedBooks;
    std::string choice;

main_menu:
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Borrow a Book\n";
    std::cout << "2. Return a Book\n";
    std::cout << "3. Display All Books\n";
    std::cout << "4. Check Book Availability\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == "1")
    {
        std::string bookName;
        std::cout << "Enter the name of the book to borrow: ";
        std::cin.ignore();
        std::getline(std::cin, bookName);

        if (bookExists(books, bookName))
        {
            removeBook(books, bookName);
            borrowedBooks.push_back(bookName);
            std::cout << "You have borrowed '" << bookName << "'." << std::endl;
        }
        else
        {
            std::cout << "Book not available." << std::endl;
        }
    }
    else if (choice == "2")
    {
        std::string bookName;
        std::cout << "Enter the name of the book to return: ";
        std::cin.ignore();
        std::getline(std::cin, bookName);

        if (bookExists(borrowedBooks, bookName))
        {
            removeBook(borrowedBooks, bookName);
            addBook(books, bookName);
            std::cout << "You have returned '" << bookName << "'." << std::endl;
        }
        else
        {
            std::cout << "You did not borrow this book." << std::endl;
        }
    }
    else if (choice == "3")
    {
        displayBooks(books);
    }
    else if (choice == "4")
    {
        std::string bookName;
        std::cout << "Enter the name of the book to check: ";
        std::cin.ignore();
        std::getline(std::cin, bookName);

        if (bookExists(books, bookName))
        {
            std::cout << "'" << bookName << "' is available." << std::endl;
        }
        else
        {
            std::cout << "'" << bookName << "' is not available." << std::endl;
        }
    }
    else if (choice == "5")
    {
        std::cout << "Exiting the program. Goodbye!" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Invalid choice. Returning to the main menu...\n";
        goto main_menu;
    }

    char continueChoice;
    do
    {
        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> continueChoice;

        if (continueChoice == 'y' || continueChoice == 'Y')
        {
            goto main_menu;
        }
        else if (continueChoice == 'n' || continueChoice == 'N')
        {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    } while (true);

    return 0;
}

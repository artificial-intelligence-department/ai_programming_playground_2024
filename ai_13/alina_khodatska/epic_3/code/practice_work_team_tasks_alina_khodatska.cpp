#include <iostream>
#include <vector>
#include <string>

void listBooks(const std::vector<std::string>& books, const std::vector<bool>& availability) {  // ���������� �� �������� ��������� ������� 
    std::cout << "List of books:\n";
    for (size_t i = 0; i < books.size(); ++i) {   // ���� for ��� ��������� ������ ����
        std::cout << i + 1 << ". " << books[i] << (availability[i] ? " (available)\n" : " (borrowed)\n");
    }
}

void updateBookStatus(std::vector<bool>& availability, bool borrow) {   // ���������� �� �������� ��������� �������
    int bookNumber;
    std::cout << "Enter the number of the book you want to " << (borrow ? "borrow" : "return") << ": ";
    std::cin >> bookNumber;

    if (bookNumber > 0 && bookNumber <= static_cast<int>(availability.size())) {   // �������� if else ��� �������� ��������� ������ �����
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
    std::vector<std::string> books = { "Book 1", "Book 2", "Book 3", "Book 4" };   // ���������� �� ����������� �������
    std::vector<bool> availability(books.size(), true);   // ���������� �� ����������� �������

    while (true) {   // ���� while 
        int choice;  // ���������� �����
        std::cout << "\nMain Menu:\n";
        std::cout << "1. List all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            listBooks(books, availability);  // ������ �������
            break;
        case 2:
            updateBookStatus(availability, true); // ������ �������
            break;
        case 3:
            updateBookStatus(availability, false);	// ������ �������
            break;
        case 4:
            std::cout << "Thank you for using our library!\n";
            return 0;   // ���������� main ������� �������� 0 ��� ��������� ������ ��������
        default:
            std::cout << "Invalid choice, please try again.\n";
            break;   //�������� break ��� ������ � ��������� switch
        }
    }
}
